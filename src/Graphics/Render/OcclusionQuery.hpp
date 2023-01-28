#ifndef __NEUTRON_GRAPHICS_OCCLUSIONQUERY_HPP__
#define __NEUTRON_GRAPHICS_OCCLUSIONQUERY_HPP__

#include "../GL.hpp"
#include "../GLObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 遮挡查询
        class OcclusionQuery : public GLObject
        {
        public:
            using SelfType = OcclusionQuery;

            /// @brief 查询类型
            enum QueryType
            {
                /// @brief 精确查询，但速度慢
                Accurate = GL_SAMPLES_PASSED,

                /// @brief 速度中等，当OpenGL确信不会有任何片段通过时，返回0；但不为0时，数值无法完全相信
                Balance = GL_ANY_SAMPLES_PASSED,

                /// @brief 最快速度查询，但数值无法完全相信
                Fast = GL_ANY_SAMPLES_PASSED_CONSERVATIVE,

                /// @brief 总数
                QCount = 3,

                /// @brief 未知
                QUnknown,
            };

            /// @brief 条件渲染类型
            enum ConditionalRenderType
            {
                /// @brief OpenGL会等待遮挡查询结果返回再渲染
                Wait = GL_QUERY_WAIT,

                /// @brief OpenGL不会等待遮挡查询结果返回再渲染
                NoWait = GL_QUERY_NO_WAIT,

                /// @brief OpenGL会判断片段结果的贡献，并等待遮挡查询完成
                ByRegionWait = GL_QUERY_BY_REGION_WAIT,

                /// @brief OpenGL会判断片段结果的贡献，但不会等待遮挡查询完成
                ByRegionNoWait = GL_QUERY_BY_REGION_NO_WAIT,

                /// @brief 总数
                CRCount = 4,

                /// @brief 未知
                CRUnknown,
            };

        private:
            /// @brief 上次查询类型
            QueryType m_query_type = QueryType::QUnknown;
            /// @brief 上次查询结果
            GLint m_result = -1;
            /// @brief 上次条件渲染的类型
            ConditionalRenderType m_conditional_render_type = ConditionalRenderType::CRUnknown;

        public:
            OcclusionQuery() = default;
            OcclusionQuery(GLuint queryID);
            OcclusionQuery(const SelfType &from) = default;
            ~OcclusionQuery() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取上次遮挡查询的类型
            QueryType get_query_type() const;

            /// @brief 获取上次遮挡查询的结果
            GLint get_result() const;

        public:
            /// @brief 获取返回值是否可用
            bool is_result_available();

            /// @brief 检查遮挡查询的结果，用于更新结果，须在get_result()之前调用
            /// @return is_result_available()为真返回结果，为假返回-1
            GLint check_result();

            /// @brief 获取是否有任何片段通过（结果不为0）
            bool any_passed();

        public:
            /// @brief 开启遮挡查询
            void begin_query(QueryType query_type = QueryType::Fast);

            /// @brief 结束遮挡查询
            void end_query();

            /// @brief 开启条件渲染，OpenGL会根据查询结果确定是否需要渲染
            void begin_conditional_render(ConditionalRenderType conditional_render_type = ConditionalRenderType::Wait);

            /// @brief 结束条件渲染
            void end_conditional_render();

        public:
            virtual void generate();
            virtual bool is_correct_objectID(GLuint objectID);
            virtual void release();
        };
    } // namespace Graphics

} // namespace ntk

#endif
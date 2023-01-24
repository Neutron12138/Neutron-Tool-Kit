#ifndef __NEUTRON_GRAPHICS_DRAWINFO_HPP__
#define __NEUTRON_GRAPHICS_DRAWINFO_HPP__

#include "../../Base/Object.hpp"
#include "DrawType.hpp"
#include "../Vertex/PrimitiveType.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 绘制信息
        class DrawInfo : public Object
        {
        public:
            using SelfType = DrawInfo;

        protected:
            /// @brief 绘制类型
            DrawType::DrawType m_draw_type = DrawType::DrawType::Arrays;
            /// @brief 图元类型
            PrimitiveType::PrimitiveType m_primitive_type = PrimitiveType::PrimitiveType::Triangles;
            /// @brief 第一个顶点索引（仅限DrawType::DrawType::Arrays系列）
            GLint m_first = 0;
            /// @brief 要绘制的顶点总数
            GLsizei m_count = 0;

        public:
            DrawInfo() = default;
            DrawInfo(DrawType::DrawType draw_type, PrimitiveType::PrimitiveType primitive_type, GLint first, GLsizei count);
            DrawInfo(PrimitiveType::PrimitiveType primitive_type, GLint first, GLsizei count);
            DrawInfo(const SelfType &from) = default;
            ~DrawInfo() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取绘制类型
            /// @return 绘制类型
            DrawType::DrawType get_draw_type() const;

            /// @brief 获取图元类型
            /// @return 图元类型
            PrimitiveType::PrimitiveType get_primitive_type() const;

            /// @brief 获取第一个顶点索引
            /// @return 第一个顶点索引
            GLint get_first() const;

            /// @brief 获取要绘制的顶点总数
            /// @return 要绘制的顶点总数
            GLsizei get_count() const;

            /// @brief 设置绘制类型
            /// @param draw_type 绘制类型
            void set_draw_type(DrawType::DrawType draw_type);

            /// @brief 设置图元类型
            /// @param primitive_type 图元类型
            void set_primitive_type(PrimitiveType::PrimitiveType primitive_type);

            /// @brief 设置第一个顶点索引
            /// @param first 第一个顶点索引
            void set_first(GLint first);

            /// @brief 设置要绘制的顶点总数
            /// @param count 要绘制的顶点总数
            void set_count(GLsizei count);

        public:
            /// @brief 绘制
            virtual void draw() const;
        };
    } // namespace Graphics

} // namespace ntk

#endif
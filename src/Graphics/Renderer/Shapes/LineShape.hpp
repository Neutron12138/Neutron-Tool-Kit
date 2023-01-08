#ifndef __NEUTRON_GRAPHICS_LINESHAPE_HPP__
#define __NEUTRON_GRAPHICS_LINESHAPE_HPP__

#include "../BaseShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 点精灵
        class LineShape : public BaseShape
        {
        protected:
            glm::vec2 m_vertex1;
            glm::vec2 m_vertex2;

        public:
            LineShape();
            LineShape(const glm::vec2 &vertex1, const glm::vec2 &vertex2);
            LineShape(const LineShape &from);
            ~LineShape();

        public:
            LineShape &operator=(const LineShape &from);

        public:
            /// @brief 获取顶点1的位置
            /// @return 顶点1的位置
            const glm::vec2 &get_vertex1() const;

            /// @brief 获取顶点2的位置
            /// @return 顶点2的位置
            const glm::vec2 &get_vertex2() const;

            /// @brief 设置顶点1的位置
            /// @param vertex 顶点1的位置
            virtual void set_vertex1(const glm::vec2 &vertex);

            /// @brief 设置顶点2的位置
            /// @param vertex 顶点2的位置
            virtual void set_vertex2(const glm::vec2 &vertex);

        public:
            virtual void generate_shape();
            virtual void update_VAO();
            virtual void render();
            virtual void render(UniformBinder &binder, const UniformDescriber &describer);
        };
    } // namespace Graphics

} // namespace ntk

#endif
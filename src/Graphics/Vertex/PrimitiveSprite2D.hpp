#ifndef __NEUTRON_GRAPHICS_PRIMITIVESPRITE2D_HPP__
#define __NEUTRON_GRAPHICS_PRIMITIVESPRITE2D_HPP__

#include "Sprite2D.hpp"
#include "PrimitiveType.hpp"
#include "VertexArrayObject.hpp"
#include "../Shade/Program.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 图元精灵
        class PrimitiveSprite2D : public Sprite2D
        {
        protected:
            /// @brief 顶点数组对象
            VertexArrayObject m_VAO;
            /// @brief 图元类型
            PrimitiveType::PrimitiveType m_primitive_type;
            /// @brief 顶点总数
            std::size_t m_vertex_count;

        public:
            PrimitiveSprite2D();
            PrimitiveSprite2D(const VertexArrayObject &VAO, PrimitiveType::PrimitiveType primitive_type, std::size_t vertex_count);
            PrimitiveSprite2D(const PrimitiveSprite2D &from);
            ~PrimitiveSprite2D();

        public:
            PrimitiveSprite2D &operator=(const PrimitiveSprite2D &from);

        public:
            virtual void render();
            virtual void render(UniformBinder &binder, const UniformDescriber &describer);
            virtual void release();
        };
    } // namespace Graphics

} // namespace ntk

#endif
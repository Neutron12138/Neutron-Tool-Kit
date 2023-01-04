#ifndef __NEUTRON_GRAPHICS_PRIMITIVESPRITE_HPP__
#define __NEUTRON_GRAPHICS_PRIMITIVESPRITE_HPP__

#include "Sprite.hpp"
#include "PrimitiveType.hpp"
#include "VertexArrayObject.hpp"
#include "../Shade/Program.hpp"

namespace ntk
{
    namespace Graphics
    {
        class PrimitiveSprite : public Sprite
        {
        protected:
            /// @brief 顶点数组对象
            VertexArrayObject m_VAO;
            /// @brief 图元类型
            PrimitiveType::PrimitiveType m_primitive_type;
            /// @brief 顶点总数
            std::size_t m_vertex_count;

        public:
            PrimitiveSprite();
            PrimitiveSprite(const VertexArrayObject &VAO, PrimitiveType::PrimitiveType primitive_type, std::size_t vertex_count);
            PrimitiveSprite(const PrimitiveSprite &from);
            ~PrimitiveSprite();

        public:
            PrimitiveSprite &operator=(const PrimitiveSprite &from);

        public:
            virtual void render();
            virtual void render(Program &program, const std::string &model_matrix_name = "u_model");
            virtual void release();
        };
    } // namespace Graphics

} // namespace ntk

#endif
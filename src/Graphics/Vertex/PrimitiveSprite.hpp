#ifndef __NEUTRON_GRAPHICS_PRIMITIVESPRITE_HPP__
#define __NEUTRON_GRAPHICS_PRIMITIVESPRITE_HPP__

#include "Sprite.hpp"
#include "PrimitiveType.hpp"
#include "VertexArrayObject.hpp"
#include "../Shade/Program.hpp"
#include "../../Utils/Resource/ResourceObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 图元精灵
        class PrimitiveSprite : public Sprite, public Utils::ResourceObject
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

        public:
            virtual void release();
        };
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_PRIMITIVESPRITE_CPP__
#define __NEUTRON_GRAPHICS_PRIMITIVESPRITE_CPP__

#include "PrimitiveSprite.hpp"

namespace ntk
{
    namespace Graphics
    {
        PrimitiveSprite::PrimitiveSprite() : Sprite() {}
        PrimitiveSprite::PrimitiveSprite(const VertexArrayObject &VAO, PrimitiveType::PrimitiveType primitive_type, std::size_t vertex_count) : Sprite(), m_VAO(VAO), m_primitive_type(primitive_type), m_vertex_count(vertex_count) {}
        PrimitiveSprite::PrimitiveSprite(const PrimitiveSprite &from) { *this = from; }
        PrimitiveSprite::~PrimitiveSprite() {}

        PrimitiveSprite &PrimitiveSprite::operator=(const PrimitiveSprite &from)
        {
            Sprite::operator=(from);
            m_VAO = from.m_VAO;
            m_primitive_type = from.m_primitive_type;
            m_vertex_count = from.m_vertex_count;
            return *this;
        }

        void PrimitiveSprite::render()
        {
            m_VAO.bind();
            glDrawArrays(static_cast<GLenum>(m_primitive_type), 0, m_vertex_count);
            m_VAO.unbind();
        }

        void PrimitiveSprite::render(Program &program, const std::string &model_matrix_name)
        {
            program.set_uniform(model_matrix_name, get_matrix());
            render();
        }

        void PrimitiveSprite::release()
        {
            m_VAO.delete_object();
        }
    } // namespace Graphics

} // namespace ntk

#endif
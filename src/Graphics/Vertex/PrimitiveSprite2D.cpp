#ifndef __NEUTRON_GRAPHICS_PRIMITIVESPRITE2D_CPP__
#define __NEUTRON_GRAPHICS_PRIMITIVESPRITE2D_CPP__

#include "PrimitiveSprite2D.hpp"

namespace ntk
{
    namespace Graphics
    {
        PrimitiveSprite2D::PrimitiveSprite2D() : Sprite2D() {}
        PrimitiveSprite2D::PrimitiveSprite2D(const VertexArrayObject &VAO, PrimitiveType::PrimitiveType primitive_type, std::size_t vertex_count) : Sprite2D(), m_VAO(VAO), m_primitive_type(primitive_type), m_vertex_count(vertex_count) {}
        PrimitiveSprite2D::PrimitiveSprite2D(const PrimitiveSprite2D &from) { *this = from; }
        PrimitiveSprite2D::~PrimitiveSprite2D() {}

        PrimitiveSprite2D &PrimitiveSprite2D::operator=(const PrimitiveSprite2D &from)
        {
            Sprite2D::operator=(from);
            m_VAO = from.m_VAO;
            m_primitive_type = from.m_primitive_type;
            m_vertex_count = from.m_vertex_count;
            return *this;
        }

        void PrimitiveSprite2D::render()
        {
            m_VAO.bind();
            glDrawArrays(static_cast<GLenum>(m_primitive_type), 0, m_vertex_count);
            m_VAO.unbind();
        }

        void PrimitiveSprite2D::render(UniformBinder &binder, const UniformDescriber &describer)
        {
            render();
        }

        void PrimitiveSprite2D::release()
        {
            m_VAO.delete_object();
        }
    } // namespace Graphics

} // namespace ntk

#endif
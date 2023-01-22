#ifndef __NEUTRON_GRAPHICS_VERTEX_CPP__
#define __NEUTRON_GRAPHICS_VERTEX_CPP__

#include "Vertex.hpp"

namespace ntk
{
    namespace Graphics
    {
        BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::BasicVertex() {}
        BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::BasicVertex(const typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::PositionType &position, const typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::NormalType &normal, const typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::TexCoordType &texCoord) : m_position(position), m_normal(normal), m_texCoord(texCoord) {}
        BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::BasicVertex(const typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::SelfType &from) { *this = from; }
        BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::~BasicVertex() {}

        typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::SelfType &BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::operator=(const typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::SelfType &from)
        {
            m_position = from.m_position;
            m_normal = from.m_normal;
            m_texCoord = from.m_texCoord;
            return *this;
        }

        const typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::PositionType BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::get_position() const
        {
            return m_position;
        }

        const typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::NormalType BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::get_normal() const
        {
            return m_normal;
        }

        const typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::TexCoordType BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::get_texCoord() const
        {
            return m_texCoord;
        }

        void BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::set_position(const typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::PositionType &position)
        {
            m_position = position;
        }

        void BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::set_normal(const typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::NormalType &normal)
        {
            m_normal = normal;
        }

        void BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::set_texCoord(const typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::TexCoordType &texCoord)
        {
            m_texCoord = texCoord;
        }

        void BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::apply(const typename BasicVertex<glm::vec3, glm::vec3, glm::vec2, Transform>::MatrixHolderType &matrix)
        {
            m_position = glm::vec3(glm::vec4(m_position.x, m_position.y, m_position.z, 1.0f) * matrix.get_matrix());
            m_normal = glm::normalize(glm::vec3(glm::vec4(m_normal.x, m_normal.y, m_normal.z, 1.0f) * matrix.get_matrix()));
        }
    } // namespace Graphics

} // namespace ntk

#endif
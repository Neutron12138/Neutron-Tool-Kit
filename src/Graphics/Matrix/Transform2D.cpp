#ifndef __NEUTRON_GRAPHICS_TRANSFORM2D_CPP__
#define __NEUTRON_GRAPHICS_TRANSFORM2D_CPP__

#include <glm/gtc/matrix_transform.hpp>
#include "Transform2D.hpp"

namespace ntk
{
    namespace Graphics
    {
        Transform2D::Transform2D() : MatrixHolder() { update(); }
        Transform2D::Transform2D(const glm::vec2 &translation, float rotation, const glm::vec2 scale) : MatrixHolder(), m_translation(translation), m_rotation(rotation), m_scale(scale) { update(); }
        Transform2D::Transform2D(const Transform2D &from) { *this = from; }
        Transform2D::~Transform2D() {}

        Transform2D &Transform2D::operator=(const Transform2D &from)
        {
            MatrixHolder::operator=(from);
            m_translation = from.m_translation;
            m_rotation = from.m_rotation;
            m_scale = from.m_scale;
            return *this;
        }

        const glm::vec2 &Transform2D::get_translation() const
        {
            return m_translation;
        }

        float Transform2D::get_rotation() const
        {
            return m_rotation;
        }

        const glm::vec2 &Transform2D::get_scale() const
        {
            return m_scale;
        }

        void Transform2D::set_translation(const glm::vec2 &translation)
        {
            m_translation = translation;
        }

        void Transform2D::set_rotation(float rotation)
        {
            m_rotation = rotation;
        }

        void Transform2D::set_scale(const glm::vec2 &scale)
        {
            m_scale = scale;
        }

        void Transform2D::translate(const glm::vec2 &translation)
        {
            m_translation += translation;
        }

        void Transform2D::rotate(float rotation)
        {
            m_rotation = rotation;
        }

        void Transform2D::scale(const glm::vec2 &scale)
        {
            m_scale = scale;
        }

        void Transform2D::update()
        {
            glm::mat4 matrix = glm::mat4(1.0f);
            matrix = glm::translate(matrix, glm::vec3(m_translation.x, m_translation.y, 0.0f));
            matrix = glm::rotate(matrix, m_rotation, glm::vec3(0.0f, 0.0f, 1.0f));
            matrix = glm::scale(matrix, glm::vec3(m_scale.x, m_scale.y, 1.0f));
            m_matrix = matrix;
        }
    } // namespace Graphics

} // namespace ntk

#endif
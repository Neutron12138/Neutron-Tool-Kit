#ifndef __NEUTRON_GRAPHICS_SPRITE2D_CPP__
#define __NEUTRON_GRAPHICS_SPRITE2D_CPP__

#include "Sprite2D.hpp"

namespace ntk
{
    namespace Graphics
    {
        Sprite2D::Sprite2D() : Transform2D() {}
        Sprite2D::Sprite2D(const glm::vec2 &translation, float rotation, const glm::vec2 &scale) : Transform2D(translation, rotation, scale) {}
        Sprite2D::Sprite2D(const Sprite2D &from) { *this = from; }
        Sprite2D::~Sprite2D() {}

        Sprite2D &Sprite2D::operator=(const Sprite2D &from)
        {
            Transform2D::operator=(from);
            return *this;
        }

        Sprite2D::PositionType Sprite2D::get_position() const
        {
            return m_translation;
        }
    } // namespace Graphics

} // namespace ntk

#endif
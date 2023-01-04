#ifndef __NEUTRON_GRAPHICS_SPRITE_CPP__
#define __NEUTRON_GRAPHICS_SPRITE_CPP__

#include "Sprite.hpp"

namespace ntk
{
    namespace Graphics
    {
        Sprite::Sprite() : Transform() {}
        Sprite::Sprite(const glm::vec3 &translation, const glm::vec3 &rotation, const glm::vec3 &scale) : Transform(translation, rotation, scale) {}
        Sprite::Sprite(const Sprite &from) { *this = from; }
        Sprite::~Sprite() {}

        Sprite &Sprite::operator=(const Sprite &from)
        {
            Transform::operator=(from);
            return *this;
        }

        const Sprite::PositionType &Sprite::get_position() const
        {
            return m_translation;
        }
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_CIRCLESHAPE_CPP__
#define __NEUTRON_GRAPHICS_CIRCLESHAPE_CPP__

#include "CircleShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        CircleShape::CircleShape() : RegularPolygonShape() {}
        CircleShape::CircleShape(float radius, std::uint32_t sides) : RegularPolygonShape(sides, radius) {}
        CircleShape::CircleShape(const CircleShape &from) { *this = from; }
        CircleShape::~CircleShape() {}

        CircleShape &CircleShape::operator=(const CircleShape &from)
        {
            RegularPolygonShape::operator=(from);
            return *this;
        }

        float CircleShape::get_circle_radius() const { return RegularPolygonShape::get_regpol_radius(); }
        void CircleShape::set_circle_radius(float radius) { RegularPolygonShape::set_regpol_radius(radius); }
    } // namespace Graphics

} // namespace ntk

#endif
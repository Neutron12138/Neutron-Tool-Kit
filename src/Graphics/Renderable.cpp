#ifndef __NEUTRON_GRAPHICS_RENDERABLE_CPP__
#define __NEUTRON_GRAPHICS_RENDERABLE_CPP__

#include "Renderable.hpp"

namespace ntk
{
    namespace Graphics
    {
        Renderable::Renderable() {}
        Renderable::Renderable(const Renderable &from) {}
        Renderable::~Renderable() {}
        Renderable &Renderable::operator=(const Renderable &from) { return *this; }
    } // namespace Graphics

} // namespace ntk

#endif
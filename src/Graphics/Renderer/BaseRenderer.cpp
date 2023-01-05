#ifndef __NEUTRON_GRAPHICS_BASERENDERER_CPP__
#define __NEUTRON_GRAPHICS_BASERENDERER_CPP__

#include "BaseRenderer.hpp"

namespace ntk
{
    namespace Graphics
    {
        BaseRenderer::BaseRenderer() {}
        BaseRenderer::BaseRenderer(const BaseRenderer &from) {}
        BaseRenderer::~BaseRenderer() {}
        BaseRenderer &BaseRenderer::operator=(const BaseRenderer &from) { return *this; }
    } // namespace Graphics

} // namespace ntk

#endif
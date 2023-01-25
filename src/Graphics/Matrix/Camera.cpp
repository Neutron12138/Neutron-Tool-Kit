#ifndef __NEUTRON_GRAPHICS_CAMERA_CPP__
#define __NEUTRON_GRAPHICS_CAMERA_CPP__

#include "Camera.hpp"

namespace ntk
{
    namespace Graphics
    {
        Camera::Camera() {}
        Camera::Camera(const Camera &from) {}
        Camera::~Camera() {}
        Camera &Camera::operator=(const Camera &from) { return *this; }
    } // namespace Graphics

} // namespace ntk

#endif
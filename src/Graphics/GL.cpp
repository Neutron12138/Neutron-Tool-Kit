#ifndef __NEUTRON_GRAPHICS_GL_CPP__
#define __NEUTRON_GRAPHICS_GL_CPP__

#include "GL.hpp"
#include "../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        bool loadGL()
        {
            bool success = glewInit() == GLEW_OK;
            if (success)
            {
                Instance::log.logi("load OpenGL", "OpenGL loaded succeefully");
            }
            else
            {
                Instance::log.loge("load OpenGL", "Failed to load OpenGL");
            }
            return success;
        }
    } // namespace Graphics

} // namespace ntk

#endif
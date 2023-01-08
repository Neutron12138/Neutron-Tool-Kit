#ifndef __NEUTRON_GRAPHICS_GL_HPP__
#define __NEUTRON_GRAPHICS_GL_HPP__

#include <GL/glew.h>
#include "../Utils/Log/Log.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 加载OpenGL的函数
        /// @return 加载是否成功
        bool loadGL();
    } // namespace Graphics

} // namespace ntk

#endif
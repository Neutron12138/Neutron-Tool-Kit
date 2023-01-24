#ifndef __NEUTRON_WINDOW_HPP__
#define __NEUTRON_WINDOW_HPP__

#include "Window/EventEnum.hpp"
#include "Window/Application.hpp"

// 实现：
// SFML实现：NEUTRON_WINDOW_IMPL_SFML
// FreeGLUT实现：NEUTRON_WINDOW_IMPL_FREEGLUT
// 原生Windows+WGL实现：NEUTRON_WINDOW_IMPL_WINDOWS

#define NTK_WND_IMP(x) NEUTRON_WINDOW_IMPL_##x
#define definedIMPL(x) defined(NTK_WND_IMPL(x))

#include "Window/SFML_Impl.hpp"

#endif
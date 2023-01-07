#ifndef __NEUTRON_GRAPHICS_RENDERABLE_HPP__
#define __NEUTRON_GRAPHICS_RENDERABLE_HPP__

#include "../Base/Object.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 可渲染对象的基类
        class Renderable : public Object
        {
        public:
            Renderable();
            Renderable(const Renderable &from);
            ~Renderable();

        public:
            Renderable &operator=(const Renderable &from);

        public:
            /// @brief 渲染本对象
            virtual void render() = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
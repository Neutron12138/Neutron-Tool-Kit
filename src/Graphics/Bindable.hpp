#ifndef __NEUTRON_GRAPHICS_BINDABLE_HPP__
#define __NEUTRON_GRAPHICS_BINDABLE_HPP__

#include "GLObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 可绑定的对象
        class Bindable : public GLObject
        {
        public:
            Bindable();
            Bindable(GLuint objectID);
            Bindable(const Bindable &from);
            ~Bindable();

        public:
            Bindable &operator=(const Bindable &from);

        public:
            /// @brief 绑定本对象
            virtual void bind() = 0;

            /// @brief 解除绑定（绑定保留值）
            virtual void unbind() = 0;

            /// @brief 让OpenGL分配一个缓冲区。如果原先储存了缓冲区，请自行管理:)
            virtual void generate() = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_AUDIO_BINDABLE_HPP__
#define __NEUTRON_AUDIO_BINDABLE_HPP__

#include "AL.hpp"
#include "ALObject.hpp"

namespace ntk
{
    namespace Audio
    {
        /// @brief 可绑定的对象
        class Bindable : public ALObject
        {
        public:
            Bindable();
            Bindable(ALuint objectID);
            Bindable(const Bindable &from);
            ~Bindable();

        public:
            Bindable &operator=(const Bindable &from);

        public:
            /// @brief 让OpenGL分配一个缓冲区。如果原先储存了缓冲区，请自行管理:)
            virtual void generate() = 0;
        };
    } // namespace Audio

} // namespace ntk

#endif
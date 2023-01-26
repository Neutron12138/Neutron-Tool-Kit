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
        };
    } // namespace Audio

} // namespace ntk

#endif
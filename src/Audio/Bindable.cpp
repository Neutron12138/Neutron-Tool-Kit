#ifndef __NEUTRON_AUDIO_BINDABLE_CPP__
#define __NEUTRON_AUDIO_BINDABLE_CPP__

#include "Bindable.hpp"

namespace ntk
{
    namespace Audio
    {
        Bindable::Bindable(ALuint objectID) : ALObject(objectID) {}
    } // namespace Audio

} // namespace ntk

#endif
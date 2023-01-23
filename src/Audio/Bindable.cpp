#ifndef __NEUTRON_AUDIO_BINDABLE_CPP__
#define __NEUTRON_AUDIO_BINDABLE_CPP__

#include "Bindable.hpp"

namespace ntk
{
    namespace Audio
    {
        Bindable::Bindable() : ALObject() {}
        Bindable::Bindable(ALuint objectID) : ALObject(objectID) {}
        Bindable::Bindable(const Bindable &from) { *this = from; }
        Bindable::~Bindable() {}

        Bindable &Bindable::operator=(const Bindable &from)
        {
            ALObject::operator=(from);
            return *this;
        }
    } // namespace Audio

} // namespace ntk

#endif
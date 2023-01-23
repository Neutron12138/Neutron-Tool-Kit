#ifndef __NEUTRON_GRAPHICS_BINDABLE_CPP__
#define __NEUTRON_GRAPHICS_BINDABLE_CPP__

#include "Bindable.hpp"

namespace ntk
{
    namespace Graphics
    {
        Bindable::Bindable() : GLObject() {}
        Bindable::Bindable(GLuint objectID) : GLObject(objectID) {}
        Bindable::Bindable(const Bindable &from) { *this = from; }
        Bindable::~Bindable() {}

        Bindable &Bindable::operator=(const Bindable &from)
        {
            GLObject::operator=(from);
            return *this;
        }
    } // namespace Graphics

} // namespace ntk

#endif
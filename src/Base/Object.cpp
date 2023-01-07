#ifndef __NEUTRON_BASE_OBJECT_CPP__
#define __NEUTRON_BASE_OBJECT_CPP__

#include "Object.hpp"

namespace ntk
{
    Object::Object() {}
    Object::Object(const Object &from) {}
    Object::~Object() {}
    Object &Object::operator=(const Object &from) { return *this; }
} // namespace ntk

#endif
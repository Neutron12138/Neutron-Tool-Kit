#ifndef __NEUTRON_BASE_OBJECT_CPP__
#define __NEUTRON_BASE_OBJECT_CPP__

#include "Object.hpp"
#include "../Utils/String/StringUtils.hpp"

namespace ntk
{
    Object::Object() {}
    Object::Object(const Object &from) {}
    Object::~Object() {}
    Object &Object::operator=(const Object &from) { return *this; }

    std::string Object::as_string() const
    {
        return Utils::to_string(this);
    }
} // namespace ntk

#endif
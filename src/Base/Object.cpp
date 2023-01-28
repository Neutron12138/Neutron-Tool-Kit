#ifndef __NEUTRON_BASE_OBJECT_CPP__
#define __NEUTRON_BASE_OBJECT_CPP__

#include "Object.hpp"
#include "../Utils/String/StringUtils.hpp"

namespace ntk
{
    std::string Object::as_string() const
    {
        return Utils::to_string("Object,", this);
    }
} // namespace ntk

#endif
#ifndef __NEUTRON_UTILS_RESOURCEOBJECT_CPP__
#define __NEUTRON_UTILS_RESOURCEOBJECT_CPP__

#include "ResourceObject.hpp"

namespace ntk
{
    namespace Utils
    {
        ResourceObject::ResourceObject() {}
        ResourceObject::ResourceObject(const ResourceObject &from) {}
        ResourceObject::~ResourceObject() {}
        ResourceObject &ResourceObject::operator=(const ResourceObject &from) { return *this; }
    } // namespace Utils

} // namespace ntk

#endif
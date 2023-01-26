#ifndef __NEUTRON_UTILS_RESOURCEDELETER_CPP__
#define __NEUTRON_UTILS_RESOURCEDELETER_CPP__

#include "ResourceDeleter.hpp"

namespace ntk
{
    namespace Utils
    {
        template <typename m_ResourceObjectType>
        void ResourceDeleter<m_ResourceObjectType>::operator()(typename ResourceDeleter<m_ResourceObjectType>::ResourceObjectType *ptr)
        {
            ptr->release();
            delete ptr;
        }
    } // namespace Utils

} // namespace ntk

#endif
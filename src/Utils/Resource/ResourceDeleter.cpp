#ifndef __NEUTRON_UTILS_RESOURCEDELETER_CPP__
#define __NEUTRON_UTILS_RESOURCEDELETER_CPP__

#include "ResourceDeleter.hpp"

namespace ntk
{
    namespace Utils
    {
        template <typename m_ResourceObjectType>
        ResourceDeleter<m_ResourceObjectType>::ResourceDeleter() {}
        template <typename m_ResourceObjectType>
        ResourceDeleter<m_ResourceObjectType>::ResourceDeleter(const ResourceDeleter<m_ResourceObjectType> &from) {}
        template <typename m_ResourceObjectType>
        ResourceDeleter<m_ResourceObjectType>::~ResourceDeleter() {}
        template <typename m_ResourceObjectType>
        ResourceDeleter<m_ResourceObjectType> &ResourceDeleter<m_ResourceObjectType>::operator=(const ResourceDeleter<m_ResourceObjectType> &from) { *this = from; }

        template <typename m_ResourceObjectType>
        void ResourceDeleter<m_ResourceObjectType>::operator()(ResourceObjectType *ptr)
        {
            ptr->release();
            delete ptr;
        }
    } // namespace Utils

} // namespace ntk

#endif
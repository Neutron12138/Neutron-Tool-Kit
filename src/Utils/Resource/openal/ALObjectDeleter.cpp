#ifndef __NEUTRON_UTILS_ALOBJECTDELETER_CPP__
#define __NEUTRON_UTILS_ALOBJECTDELETER_CPP__

#include "ALObjectDeleter.hpp"

namespace ntk
{
    namespace Utils
    {
        template <typename m_ALObjectType>
        ALObjectDeleter<m_ALObjectType>::ALObjectDeleter() {}
        template <typename m_ALObjectType>
        ALObjectDeleter<m_ALObjectType>::ALObjectDeleter(const ALObjectDeleter<m_ALObjectType> &from) {}
        template <typename m_ALObjectType>
        ALObjectDeleter<m_ALObjectType>::~ALObjectDeleter() {}
        template <typename m_ALObjectType>
        ALObjectDeleter<m_ALObjectType> &ALObjectDeleter<m_ALObjectType>::operator=(const ALObjectDeleter<m_ALObjectType> &from) { *this = from; }

        template <typename m_ALObjectType>
        void ALObjectDeleter<m_ALObjectType>::operator()(m_ALObjectType *ptr)
        {
            ptr->delete_object();
            delete ptr;
        }
    } // namespace Utils

} // namespace ntk

#endif
#ifndef __NEUTRON_UTILS_ALCOBJECTDELETER_CPP__
#define __NEUTRON_UTILS_ALCOBJECTDELETER_CPP__

#include "ALCObjectDeleter.hpp"

namespace ntk
{
    namespace Utils
    {
        template <typename m_ALCObjectType>
        ALCObjectDeleter<m_ALCObjectType>::ALCObjectDeleter() {}
        template <typename m_ALCObjectType>
        ALCObjectDeleter<m_ALCObjectType>::ALCObjectDeleter(const ALCObjectDeleter<m_ALCObjectType> &from) {}
        template <typename m_ALCObjectType>
        ALCObjectDeleter<m_ALCObjectType>::~ALCObjectDeleter() {}
        template <typename m_ALCObjectType>
        ALCObjectDeleter<m_ALCObjectType> &ALCObjectDeleter<m_ALCObjectType>::operator=(const ALCObjectDeleter<m_ALCObjectType> &from) { *this = from; }

        template <typename m_ALCObjectType>
        void ALCObjectDeleter<m_ALCObjectType>::operator()(m_ALCObjectType *ptr)
        {
            ptr->release();
            delete ptr;
        }
    } // namespace Utils

} // namespace ntk

#endif
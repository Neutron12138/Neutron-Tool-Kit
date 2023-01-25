#ifndef __NEUTRON_AUDIO_ALCOBJECT_CPP__
#define __NEUTRON_AUDIO_ALCOBJECT_CPP__

#include "ALCObject.hpp"

namespace ntk
{
    namespace Audio
    {
        template <typename m_ALCObjectType>
        ALCObject<m_ALCObjectType>::ALCObject() {}
        template <typename m_ALCObjectType>
        ALCObject<m_ALCObjectType>::ALCObject(ALCObjectType *object) : m_object(object) {}
        template <typename m_ALCObjectType>
        ALCObject<m_ALCObjectType>::ALCObject(const ALCObject &from) { *this = from; }
        template <typename m_ALCObjectType>
        ALCObject<m_ALCObjectType>::~ALCObject() {}

        template <typename m_ALCObjectType>
        typename ALCObject<m_ALCObjectType>::SelfType &ALCObject<m_ALCObjectType>::operator=(const typename ALCObject<m_ALCObjectType>::SelfType &from)
        {
            m_object = from.m_object;
            return *this;
        }

        template <typename m_ALCObjectType>
        typename ALCObject<m_ALCObjectType>::SelfType &ALCObject<m_ALCObjectType>::set_object(typename ALCObject<m_ALCObjectType>::ALCObjectType *object)
        {
            m_object = object;
            return *this;
        }

        template <typename m_ALCObjectType>
        const typename ALCObject<m_ALCObjectType>::ALCObjectType *ALCObject<m_ALCObjectType>::get_object() const
        {
            return m_object;
        }

        template <typename m_ALCObjectType>
        bool ALCObject<m_ALCObjectType>::is_null() const
        {
            return m_object == nullptr;
        }
    } // namespace Audio

} // namespace ntk

#endif
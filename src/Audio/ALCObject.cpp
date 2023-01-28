#ifndef __NEUTRON_AUDIO_ALCOBJECT_CPP__
#define __NEUTRON_AUDIO_ALCOBJECT_CPP__

#include "ALCObject.hpp"

namespace ntk
{
    namespace Audio
    {
        template <typename m_ALCObjectType>
        ALCObject<m_ALCObjectType>::ALCObject(typename ALCObject<m_ALCObjectType>::ALCObjectType* object) : m_object(object) {}

        template <typename m_ALCObjectType>
        void ALCObject<m_ALCObjectType>::set_object(typename ALCObject<m_ALCObjectType>::ALCObjectType* object)
        {
            m_object = object;
        }

        template <typename m_ALCObjectType>
        typename ALCObject<m_ALCObjectType>::ALCObjectType* ALCObject<m_ALCObjectType>::get_object() const
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
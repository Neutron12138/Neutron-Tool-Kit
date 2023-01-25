#ifndef __NEUTRON_AUDIO_ALOBJECT_CPP__
#define __NEUTRON_AUDIO_ALOBJECT_CPP__

#include "ALObject.hpp"

namespace ntk
{
    namespace Audio
    {
        ALObject::ALObject() : m_objectID(0) {}
        ALObject::ALObject(ALuint objectID) : m_objectID(objectID) {}
        ALObject::ALObject(const ALObject &from) { *this = from; }
        ALObject::~ALObject() {}

        ALObject &ALObject::operator=(const ALObject &from)
        {
            m_objectID = from.m_objectID;
            return *this;
        }

        ALObject &ALObject::set_objectID(ALuint objectID)
        {
            m_objectID = objectID;
            return *this;
        }

        ALuint ALObject::get_objectID() const
        {
            return m_objectID;
        }

        bool ALObject::is_null() const
        {
            return m_objectID == 0;
        }
    } // namespace Audio
    
} // namespace ntk


#endif
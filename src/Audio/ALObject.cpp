#ifndef __NEUTRON_AUDIO_ALOBJECT_CPP__
#define __NEUTRON_AUDIO_ALOBJECT_CPP__

#include "ALObject.hpp"

namespace ntk
{
    namespace Audio
    {
        ALObject::ALObject(ALuint objectID) : m_objectID(objectID) {}

        void ALObject::set_objectID(ALuint objectID)
        {
            m_objectID = objectID;
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
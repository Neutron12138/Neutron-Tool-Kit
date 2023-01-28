#ifndef __NEUTRON_AUDIO_SOURCE_CPP__
#define __NEUTRON_AUDIO_SOURCE_CPP__

#include "Source.hpp"
#include "../Instances.hpp"

namespace ntk
{
    namespace Audio
    {
        Source::Source(ALuint objectID) : Bindable(objectID) {}

        const Buffer &Source::get_buffer() const
        {
            return m_buffer;
        }

        float Source::get_pitch() const
        {
            return m_pitch;
        }

        float Source::get_gain() const
        {
            return m_gain;
        }

        const glm::vec3 &Source::get_position() const
        {
            return m_position;
        }

        const glm::vec3 &Source::get_velocity() const
        {
            return m_velocity;
        }

        bool Source::is_looping() const
        {
            return m_looping;
        }

        void Source::set_buffer(const Buffer &buffer)
        {
            m_buffer = buffer;
        }

        void Source::set_pitch(float pitch)
        {
            m_pitch = pitch;
        }

        void Source::set_gain(float gain)
        {
            m_gain = gain;
        }

        void Source::set_position(const glm::vec3 &position)
        {
            m_position = position;
        }

        void Source::set_velocity(const glm::vec3 &velocity)
        {
            m_velocity = velocity;
        }

        void Source::set_looping(bool looping)
        {
            m_looping = looping;
        }

        SourceStatus::Status Source::get_status() const
        {
            if (m_objectID != 0)
            {
                ALenum status;
                alGetSourcei(m_objectID, AL_SOURCE_STATE, &status);
                switch (status)
                {
                case AL_PLAYING:
                    return SourceStatus::Status::Playing;
                case AL_PAUSED:
                    return SourceStatus::Status::Paused;
                case AL_STOPPED:
                    return SourceStatus::Status::Stopped;
                }
            }
            else
            {
                Instance::log.loge("Source", "Bad object ID: reserved value 0");
            }
            return SourceStatus::Status::Unknown;
        }

        void Source::play()
        {
            if (m_objectID != 0)
            {
                alSourcePlay(m_objectID);
            }
            else
            {
                Instance::log.loge("Source", "Bad object ID: reserved value 0");
            }
        }

        void Source::pause()
        {
            if (m_objectID != 0)
            {
                alSourcePause(m_objectID);
            }
            else
            {
                Instance::log.loge("Source", "Bad object ID: reserved value 0");
            }
        }

        void Source::stop()
        {
            if (m_objectID != 0)
            {
                alSourceStop(m_objectID);
            }
            else
            {
                Instance::log.loge("Source", "Bad object ID: reserved value 0");
            }
        }

        void Source::rewind()
        {
            if (m_objectID != 0)
            {
                alSourceRewind(m_objectID);
            }
            else
            {
                Instance::log.loge("Source", "Bad object ID: reserved value 0");
            }
        }

        void Source::set_sourceID(ALuint sourceID)
        {
            if (sourceID != 0 && is_correct_objectID(sourceID))
            {
                m_objectID = sourceID;
            }
            else if (is_correct_objectID(sourceID))
            {
                Instance::log.loge("Source", "Incorrect object type");
            }
            else
            {
                m_objectID = sourceID;
                Instance::log.logw("Source", "You will assign a reserved value");
            }
        }

        void Source::update()
        {
            if (m_objectID != 0)
            {
                alSourcei(m_objectID, AL_BUFFER, m_buffer.get_objectID());
                alSourcef(m_objectID, AL_PITCH, m_pitch);
                alSourcef(m_objectID, AL_GAIN, m_gain);
                alSource3f(m_objectID, AL_POSITION, m_position.x, m_position.y, m_position.z);
                alSource3f(m_objectID, AL_VELOCITY, m_velocity.x, m_velocity.y, m_velocity.z);
                alSourcei(m_objectID, AL_LOOPING, m_looping);
            }
            else
            {
                Instance::log.loge("Source", "Bad object ID: reserved value 0");
            }
        }

        void Source::generate()
        {
            alGenSources(1, &m_objectID);
        }

        bool Source::is_correct_objectID(ALuint objectID)
        {
            return alIsSource(objectID);
        }

        void Source::release()
        {
            if (m_objectID != 0)
            {
                alDeleteSources(1, &m_objectID);
                m_objectID = 0;
            }
        }
    } // namespace Audio

} // namespace ntk

#endif
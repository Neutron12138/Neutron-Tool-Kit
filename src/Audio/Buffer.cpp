#ifndef __NEUTRON_AUDIO_BUFFER_CPP__
#define __NEUTRON_AUDIO_BUFFER_CPP__

#include "Buffer.hpp"

namespace ntk
{
    namespace Audio
    {
        Buffer::Buffer() : Bindable() {}
        Buffer::Buffer(ALuint objectID) : Bindable(objectID) {}
        Buffer::Buffer(const Buffer &from) { *this = from; }
        Buffer::~Buffer() {}

        Buffer &Buffer::operator=(const Buffer &from)
        {
            Bindable::operator=(from);
            return *this;
        }

        void Buffer::bind_data(ALenum format, const ALvoid *data, ALsizei size, ALsizei freq)
        {
            alBufferData(m_objectID, format, data, size, freq);
        }

        template <typename DataType>
        void Buffer::bind_data(ALenum format, const DataType *data, ALsizei size, ALsizei freq)
        {
            bind_data(format, static_cast<const ALvoid *>(data), static_cast<ALsizei>(size * sizeof(DataType)), freq);
        }

        template <typename DataType>
        void Buffer::bind_data(ALenum format, const std::vector<DataType> &data, ALsizei freq)
        {
            bind_data(format, data.data(), data.size(), freq);
        }

        void Buffer::set_bufferID(ALuint bufferID)
        {
            if (bufferID != 0 && is_correct_objectID(bufferID))
            {
                m_objectID = bufferID;
            }
            else if (is_correct_objectID(bufferID))
            {
                Instance::log.loge("Buffer", "Incorrect object type");
            }
            else
            {
                m_objectID = bufferID;
                Instance::log.logw("Buffer", "You will assign a reserved value");
            }
        }

        void Buffer::generate()
        {
            alGenBuffers(1, &m_objectID);
        }

        bool Buffer::is_correct_objectID(ALuint objectID)
        {
            return alIsBuffer(objectID);
        }

        void Buffer::delete_object()
        {
            if (m_objectID != 0)
            {
                alDeleteBuffers(1, &m_objectID);
                m_objectID = 0;
            }
        }
    } // namespace Audio

} // namespace ntk

#endif
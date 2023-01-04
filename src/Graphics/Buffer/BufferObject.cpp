#ifndef __NEUTRON_GRAPHICS_BUFFEROBJECT_CPP__
#define __NEUTRON_GRAPHICS_BUFFEROBJECT_CPP__

#include "BufferObject.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        BufferObject::BufferObject(GLenum buffer_type) : Bindable(), m_buffer_type(buffer_type) {}
        BufferObject::BufferObject(GLenum buffer_type, GLuint bufferID) : Bindable(bufferID), m_buffer_type(buffer_type) {}
        BufferObject::BufferObject(const BufferObject &from) { *this = from; }
        BufferObject::~BufferObject() {}

        BufferObject &BufferObject::operator=(const BufferObject &from)
        {
            Bindable::operator=(from);
            m_buffer_type = from.m_buffer_type;
            return *this;
        }

        GLenum BufferObject::get_buffer_type() const
        {
            return m_buffer_type;
        }

        void BufferObject::set_bufferID(GLuint bufferID)
        {
            // 如果bufferID不为0且类型正确
            if (bufferID != 0 && is_correct_objectID(bufferID))
            {
                m_objectID = bufferID;
            }
            // 如果bufferID类型不正确
            else if (!is_correct_objectID(bufferID))
            {
                Instance::log.loge("Buffer Object", "The type of OpenGL object to be assigned is not a buffer object.");
            }
            // 如果bufferID为0
            else
            {
                Instance::log.logw("Buffer Object", "You will assign a reserved value to the buffer object.");
                m_objectID = bufferID;
            }
        }

        void BufferObject::bind()
        {
            if (m_objectID != 0)
                glBindBuffer(m_buffer_type, m_objectID);
        }

        void BufferObject::unbind()
        {
            glBindBuffer(m_buffer_type, 0);
        }

        void BufferObject::generate()
        {
            glGenBuffers(1, &m_objectID);
        }

        bool BufferObject::is_correct_objectID(GLuint objectID)
        {
            return glIsBuffer(objectID);
        }

        void BufferObject::delete_object()
        {
            if (m_objectID != 0)
            {
                glDeleteBuffers(1, &m_objectID);
                m_objectID == 0;
            }
        }
    } // namespace Graphics

} // namespace ntk

#endif
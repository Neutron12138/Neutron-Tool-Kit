#ifndef __NEUTRON_GRAPHICS_GLOBJECT_CPP__
#define __NEUTRON_GRAPHICS_GLOBJECT_CPP__

#include "GLObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        GLObject::GLObject() : m_objectID(0) {}
        GLObject::GLObject(GLuint objectID) : m_objectID(objectID) {}
        GLObject::GLObject(const GLObject &from) { *this = from; }
        GLObject::~GLObject() {}

        GLObject &GLObject::operator=(const GLObject &from)
        {
            m_objectID = from.m_objectID;
            return *this;
        }

        GLObject &GLObject::set_objectID(GLuint objectID)
        {
            m_objectID = objectID;
            return *this;
        }

        GLuint GLObject::get_objectID() const
        {
            return m_objectID;
        }

        bool GLObject::is_null() const
        {
            return m_objectID == 0;
        }
    } // namespace Graphics

} // namespace ntk

#endif
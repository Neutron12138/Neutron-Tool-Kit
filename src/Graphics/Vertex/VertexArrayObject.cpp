#ifndef __NEUTRON_GRAPHICS_VERTEXARRAYOBJECT_CPP__
#define __NEUTRON_GRAPHICS_VERTEXARRAYOBJECT_CPP__

#include "VertexArrayObject.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        VertexArrayObject *VertexArrayObject::current_VAO = nullptr;

        VertexArrayObject::VertexArrayObject() : Bindable() {}
        VertexArrayObject::VertexArrayObject(GLuint VAO_ID) : Bindable(VAO_ID) {}
        VertexArrayObject::VertexArrayObject(const VertexArrayObject &from) { *this = from; }
        VertexArrayObject::~VertexArrayObject() {}

        VertexArrayObject &VertexArrayObject::operator=(const VertexArrayObject &from)
        {
            Bindable::operator=(from);
            return *this;
        }

        void VertexArrayObject::set_VAO_ID(GLuint VAO_ID)
        {
            // 如果VAO_ID不为0且类型正确
            if (VAO_ID != 0 && is_correct_objectID(VAO_ID))
            {
                m_objectID = VAO_ID;
            }
            // 如果VAO_ID类型不正确
            else if (!is_correct_objectID(VAO_ID))
            {
                Instance::log.loge("Vertex Array Object", "The type of OpenGL object to be assigned is not a vertex array object.");
            }
            // 如果VAO_ID为0
            else
            {
                Instance::log.logw("Vertex Array Object", "You will assign a reserved value to the vertex array object.");
                m_objectID = VAO_ID;
            }
        }

        void VertexArrayObject::bind()
        {
            if (m_objectID == 0)
            {
                Instance::log.logw("Vertex Array Object", "You will bind the reserved value of OpenGL.");
            }
            glBindVertexArray(m_objectID);
            current_VAO = this;
        }

        void VertexArrayObject::unbind()
        {
            glBindVertexArray(0);
            current_VAO = nullptr;
        }

        void VertexArrayObject::generate()
        {
            glGenVertexArrays(1, &m_objectID);
        }

        bool VertexArrayObject::is_correct_objectID(GLuint objectID)
        {
            return glIsVertexArray(objectID);
        }

        void VertexArrayObject::delete_object()
        {
            if (m_objectID != 0)
            {
                glDeleteVertexArrays(1, &m_objectID);
                m_objectID = 0;
            }
        }
    } // namespace Graphics

} // namespace ntk

#endif
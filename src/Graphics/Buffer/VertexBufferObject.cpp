#ifndef __NEUTRON_GRAPHICS_VERTEXBUFFEROBJECT_CPP__
#define __NEUTRON_GRAPHICS_VERTEXBUFFEROBJECT_CPP__

#include "VertexBufferObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        VertexBufferObject::VertexBufferObject() : BufferObject(GL_ARRAY_BUFFER) {}
        VertexBufferObject::VertexBufferObject(GLuint VBO_ID) : BufferObject(GL_ARRAY_BUFFER, VBO_ID) {}
        VertexBufferObject::VertexBufferObject(const VertexBufferObject &from) : BufferObject(GL_ARRAY_BUFFER) { *this = from; }
        VertexBufferObject::~VertexBufferObject() {}

        VertexBufferObject &VertexBufferObject::operator=(const VertexBufferObject &from)
        {
            BufferObject::operator=(from);
            return *this;
        }

        void VertexBufferObject::bind_single(GLsizeiptr buffer_size, const void *buffer_data, GLenum usage, GLuint index, GLint vertex_size, GLenum type, GLsizei stride)
        {
            bind();
            glBufferData(get_buffer_type(), buffer_size, buffer_data, usage);
            glVertexAttribPointer(index, vertex_size, type, GL_FALSE, stride, nullptr);
            glEnableVertexAttribArray(index);
        }

        void VertexBufferObject::bind_single(const std::vector<GLfloat> &vertices, GLuint index, GLint size, GLenum usage)
        {
            bind_single(vertices.size() * sizeof(GLfloat), vertices.data(), usage, index, size, GL_FLOAT, size * sizeof(GLfloat));
        }

        void VertexBufferObject::bind_single(const std::vector<glm::vec3> &vertices, GLuint index, GLenum usage)
        {
            bind_single(vertices.size() * sizeof(glm::vec3), vertices.data(), usage, index, 3, GL_FLOAT, sizeof(glm::vec3));
        }

        void VertexBufferObject::bind_single(const std::vector<glm::vec2> &vertices, GLuint index, GLenum usage)
        {
            bind_single(vertices.size() * sizeof(glm::vec2), vertices.data(), usage, index, 2, GL_FLOAT, sizeof(glm::vec2));
        }

        /*
                template <typename... ArgsT>
                void VertexBufferObject::bind_multiple(GLsizeiptr buffer_size, const void *buffer_data, GLenum usage, ArgsT... args)
                {
                    bind();
                    glBufferData(get_buffer_type(), buffer_size, buffer_data, usage);
                    bind_multiple(args...);
                }

                template <typename indexT, typename sizeT, typename typeT, typename strideT, typename pointerT, typename... ArgsT>
                void VertexBufferObject::bind_multiple(indexT index, sizeT size, typeT type, strideT stride, pointerT pointer, ArgsT... args)
                {
                    glVertexAttribPointer(index, size, type, GL_FALSE, stride, pointer);
                    glEnableVertexAttribArray(index);
                }

                void VertexBufferObject::bind_multiple() {}

                template <typename... ArgsT>
                void VertexBufferObject::bind_multiple(const std::vector<GLfloat> &vertices, GLenum usage, ArgsT... args)
                {
                    bind_multiple(vertices.size() * sizeof(GLfloat), vertices.data(), usage, args...);
                }
                */

        VertexBufferObject VertexBufferObject::createVBO_single(GLsizeiptr buffer_size, const void *buffer_data, GLenum usage, GLuint index, GLint vertex_size, GLenum type, GLsizei stride)
        {
            VertexBufferObject VBO;
            VBO.generate();
            VBO.bind_single(buffer_size, buffer_data, usage, index, vertex_size, type, stride);
            return VBO;
        }

        VertexBufferObject VertexBufferObject::createVBO_single(const std::vector<GLfloat> &vertices, GLuint index, GLint size, GLenum usage)
        {
            VertexBufferObject VBO;
            VBO.generate();
            VBO.bind_single(vertices, index, size, usage);
            return VBO;
        }

        VertexBufferObject VertexBufferObject::createVBO_single(const std::vector<glm::vec3> &vertices, GLuint index, GLenum usage)
        {
            VertexBufferObject VBO;
            VBO.generate();
            VBO.bind_single(vertices, index, usage);
            return VBO;
        }

        VertexBufferObject VertexBufferObject::createVBO_single(const std::vector<glm::vec2> &vertices, GLuint index, GLenum usage)
        {
            VertexBufferObject VBO;
            VBO.generate();
            VBO.bind_single(vertices, index, usage);
            return VBO;
        }
    } // namespace Graphics

} // namespace ntk

#endif
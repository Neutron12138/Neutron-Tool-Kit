#ifndef __NEUTRON_GRAPHICS_VERTEXARRAYOBJECT_HPP__
#define __NEUTRON_GRAPHICS_VERTEXARRAYOBJECT_HPP__

#include <vector>
#include "../GL.hpp"
#include "../Bindable.hpp"
#include "../Buffer/BufferObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        class VertexArrayObject : public Bindable
        {
        public:
            /// @brief 当前的顶点数组对象
            static VertexArrayObject *current_VAO;

        public:
            VertexArrayObject();
            VertexArrayObject(GLuint VAO_ID);
            VertexArrayObject(const VertexArrayObject &from);
            ~VertexArrayObject();

        public:
            VertexArrayObject &operator=(const VertexArrayObject &from);

        public:
            /// @brief 有对象检查版本的set_objectID()，建议使用这个而不是set_objectID()
            /// @param VAO_ID 要被赋予的顶点数组对象
            virtual void set_VAO_ID(GLuint VAO_ID);

        public:
            virtual void bind();
            virtual void unbind();
            virtual void generate();
            virtual bool is_correct_objectID(GLuint objectID);
            virtual void delete_object();
        };
    } // namespace Graphics

} // namespace ntk

#endif
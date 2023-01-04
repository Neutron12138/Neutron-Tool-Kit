#ifndef __NEUTRON_GRAPHICS_BUFFEROBJECT_HPP__
#define __NEUTRON_GRAPHICS_BUFFEROBJECT_HPP__

#include "../GL.hpp"
#include "../Bindable.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 缓冲区对象
        class BufferObject : public Bindable
        {
        private:
            /// @brief 缓冲区对象类型，不可改变
            GLenum m_buffer_type;

        public:
            BufferObject(GLenum buffer_type);
            BufferObject(GLenum buffer_type, GLuint bufferID);
            BufferObject(const BufferObject &from);
            ~BufferObject();

        public:
            BufferObject &operator=(const BufferObject &from);

        public:
            /// @brief 获取缓冲区对象的类型
            /// @return 缓冲区对象类型
            GLenum get_buffer_type() const;

            /// @brief 有对象检查版本的set_objectID()，建议使用这个而不是set_objectID()
            /// @param bufferID 要被赋予的缓冲区对象
            virtual void set_bufferID(GLuint bufferID);

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
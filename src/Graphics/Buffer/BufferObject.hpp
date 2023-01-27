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
            /// @brief 更新缓冲区数据，需要提前调用bind()
            /// @param offset 偏移值，单位为字节
            /// @param size 要更新的数据大小
            /// @param data 新数据
            virtual void sub_data(GLintptr offset, GLsizeiptr size, const void *data);

            /// @brief 更新缓冲区数据，偏移值为0
            /// @param size 要更新的数据大小
            /// @param data 新数据
            virtual void sub_data(GLsizeiptr size, const void *data);

            /// @brief 更新缓冲区数据
            /// @tparam DataType 数据类型
            /// @param offset 偏移值，会乘上sizeof(DataType)
            /// @param data 新数据
            template <typename DataType>
            void sub_data(GLintptr offset, const std::vector<DataType> &data);

            /// @brief 更新缓冲区数据
            /// @tparam DataType 数据类型
            /// @param data 新数据
            template <typename DataType>
            void sub_data(const std::vector<DataType> &data);

        public:
            virtual void bind();
            virtual void unbind();
            virtual void generate();
            virtual bool is_correct_objectID(GLuint objectID);
            virtual void release();
        };
    } // namespace Graphics

} // namespace ntk

#endif
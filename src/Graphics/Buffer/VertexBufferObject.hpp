#ifndef __NEUTRON_GRAPHICS_VERTEXBUFFEROBJECT_HPP__
#define __NEUTRON_GRAPHICS_VERTEXBUFFEROBJECT_HPP__

#include <vector>
#include "../GL.hpp"
#include "BufferObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        class VertexBufferObject : public BufferObject
        {
        public:
            VertexBufferObject();
            VertexBufferObject(GLuint VBO_ID);
            VertexBufferObject(const VertexBufferObject &from);
            ~VertexBufferObject();

        public:
            VertexBufferObject &operator=(const VertexBufferObject &from);

        public:
            /// @brief 让缓冲区绑定单个顶点属性
            /// @param buffer_size 缓冲区大小
            /// @param buffer_data 缓冲区数据
            /// @param usage 缓冲区用法
            /// @param index 顶点属性索引
            /// @param vertex_size 顶点大小
            /// @param type 顶点数据类型
            /// @param stride 顶点数据跨度
            virtual void bind_single(GLsizeiptr buffer_size, const void *buffer_data, GLenum usage, GLuint index, GLint vertex_size, GLenum type, GLsizei stride);

            /// @brief 让缓冲区绑定单个顶点属性，为GLfloat型数据特化
            /// @param vertices 顶点数组
            /// @param index 顶点属性索引
            /// @param size 顶点大小
            /// @param usage 缓冲区用法
            virtual void bind_single(const std::vector<GLfloat> &vertices, GLuint index, GLint size, GLenum usage = GL_STATIC_DRAW);

            /// @brief 让缓冲区绑定单个顶点属性，为GLfloat型数据特化
            /// @param vertices 顶点数组
            /// @param index 顶点属性索引
            /// @param usage 缓冲区用法
            virtual void bind_single(const std::vector<glm::vec3> &vertices, GLuint index, GLenum usage = GL_STATIC_DRAW);

            /// @brief 让缓冲区绑定单个顶点属性，为GLfloat型数据特化
            /// @param vertices 顶点数组
            /// @param index 顶点属性索引
            /// @param usage 缓冲区用法
            virtual void bind_single(const std::vector<glm::vec2> &vertices, GLuint index, GLenum usage = GL_STATIC_DRAW);

            /*
            完全基于模板可变参
            过于复杂，不利于维护，不够直观，现已废弃
            新的同时绑定多个顶点属性会改用VertexAttributeDescriptor，敬请期待

                        /// @brief 让缓冲区绑定多个顶点属性
                        /// @tparam ...ArgsT 参数类型
                        /// @param buffer_size 缓冲区大小
                        /// @param buffer_data 缓冲区数据
                        /// @param usage 缓冲区用法
                        /// @param type 顶点数据类型
                        /// @param ...args 顶点属性参数列表
                        template <typename... ArgsT>
                        void bind_multiple(GLsizeiptr buffer_size, const void *buffer_data, GLenum usage,  ArgsT... args);

                        /// @brief 让缓冲区绑定多个顶点属性
                        /// @tparam indexT 顶点属性索引类型
                        /// @tparam sizeT 顶点大小类型
                        /// @tparam strideT 顶点数据跨度类型
                        /// @tparam pointerT 顶点数据间隔类型
                        /// @tparam ...ArgsT 顶点属性参数列表
                        /// @param index 顶点属性索引
                        /// @param size 顶点大小
                        /// @param stride 顶点数据跨度
                        /// @param pointer 顶点数据间隔
                        /// @param ...args
                        template <typename indexT, typename sizeT, typename typeT, typename strideT, typename pointerT, typename... ArgsT>
                        void bind_multiple(indexT index, sizeT size, typeT type, strideT stride, pointerT pointer, ArgsT... args);

                        /// @brief 让缓冲区绑定多个顶点属性
                        void bind_multiple();

                        /// @brief 为GLfloat型特化
                        template <typename... ArgsT>
                        void bind_multiple(const std::vector<GLfloat> &vertices, GLenum usage, ArgsT... args);
            */

        public:
            /// @brief 用bind_single()快速创建VBO
            /// @param 参数同bind_single()
            /// @return 顶点缓冲对象
            static VertexBufferObject createVBO_single(GLsizeiptr buffer_size, const void *buffer_data, GLenum usage, GLuint index, GLint vertex_size, GLenum type, GLsizei stride);

            /// @brief 用bind_single()快速创建VBO
            /// @param 参数同bind_single()
            /// @return 顶点缓冲对象
            static VertexBufferObject createVBO_single(const std::vector<GLfloat> &vertices, GLuint index, GLint size, GLenum usage = GL_STATIC_DRAW);

            /// @brief 用bind_single()快速创建VBO
            /// @param 参数同bind_single()
            /// @return 顶点缓冲对象
            static VertexBufferObject createVBO_single(const std::vector<glm::vec3> &vertices, GLuint index, GLenum usage = GL_STATIC_DRAW);

            /// @brief 用bind_single()快速创建VBO
            /// @param 参数同bind_single()
            /// @return 顶点缓冲对象
            static VertexBufferObject createVBO_single(const std::vector<glm::vec2> &vertices, GLuint index, GLenum usage = GL_STATIC_DRAW);
        };
    } // namespace Graphics

} // namespace ntk

#endif
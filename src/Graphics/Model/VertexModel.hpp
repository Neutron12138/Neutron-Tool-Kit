#ifndef __NEUTRON_GRAPHICS_VERTEXMODEL_HPP__
#define __NEUTRON_GRAPHICS_VERTEXMODEL_HPP__

#include <vector>
#include "BasicVertexModel.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 顶点模型
        template <>
        class BasicVertexModel<Vertex, Transform, std::vector<Vertex>> : public VertexArray<Vertex, Transform, std::vector<Vertex>>
        {
        public:
            using VertexType = Vertex;
            using MatrixHolderType = Transform;
            using ContainerType = std::vector<Vertex>;
            using SelfType = BasicVertexModel<VertexType, MatrixHolderType, ContainerType>;
            using ParentType = VertexArray<VertexType, MatrixHolderType, ContainerType>;

        public:
            BasicVertexModel() = default;
            BasicVertexModel(const ContainerType &vertices);
            BasicVertexModel(const SelfType &from) = default;
            ~BasicVertexModel() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            virtual void push_back(const VertexType &vertex);
            virtual void pop_back(const VertexType &vertex);

        public:
            /// @brief 生成顶点数组对象
            /// @param VAO 顶点数组对象
            /// @param usage 缓冲区用法
            virtual void generate_VAO(VertexArrayObject &VAO, GLenum usage = GL_STATIC_DRAW);

            /// @brief 生成顶点数组对象
            /// @param VAO 顶点数组对象
            /// @param VBOs 顶点缓冲对象
            /// @param usage 缓冲区用法
            virtual void generate_VAO(VertexArrayObject &VAO, VertexBufferObject &VBO, GLenum usage = GL_STATIC_DRAW);

            /// @brief 生成顶点数组对象
            /// @param VAO 顶点数组对象
            /// @param program 着色程序对象
            /// @param describer 顶点属性描述器
            /// @param usage 缓冲区用法
            virtual void generate_VAO(VertexArrayObject &VAO, const Program &program, const VertexAttribDescriber &describer, GLenum usage = GL_STATIC_DRAW);

            /// @brief 生成顶点数组对象
            /// @param VAO 顶点数组对象
            /// @param VBOs 顶点缓冲对象
            /// @param program 着色程序对象
            /// @param describer 顶点属性描述器
            /// @param usage 缓冲区用法
            virtual void generate_VAO(VertexArrayObject &VAO, VertexBufferObject &VBO, const Program &program, const VertexAttribDescriber &describer, GLenum usage = GL_STATIC_DRAW);
        };

        using VertexModel = BasicVertexModel<Vertex, Transform, std::vector<Vertex>>;
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_BASICVERTEXMODEL_HPP__
#define __NEUTRON_GRAPHICS_BASICVERTEXMODEL_HPP__

#include <vector>
#include "Vertex.hpp"
#include "VertexArray.hpp"
#include "../Vertex/VertexArrayObject.hpp"
#include "../Buffer/VertexBufferObject.hpp"
#include "../Vertex/VertexAttribDescriber.hpp"
#include "../Shade/Program.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 顶点模型
        /// @tparam m_VertexType 三角面类型
        /// @tparam m_MatrixHolderType 矩阵类型
        /// @tparam m_ContainerType 容器类型
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        class BasicVertexModel : public VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>
        {
        public:
            using VertexType = m_VertexType;
            using MatrixHolderType = m_MatrixHolderType;
            using ContainerType = m_ContainerType;
            using SelfType = BasicVertexModel<VertexType, MatrixHolderType, ContainerType>;
            using ParentType = VertexArray<VertexType, MatrixHolderType, ContainerType>;

        public:
            BasicVertexModel();
            BasicVertexModel(const ContainerType &vertices);
            BasicVertexModel(const SelfType &from);
            ~BasicVertexModel();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 生成顶点数组对象
            /// @param VAO 顶点数组对象
            /// @param usage 缓冲区用法
            virtual void generate_VAO(VertexArrayObject &VAO, GLenum usage = GL_STATIC_DRAW) = 0;

            /// @brief 生成顶点数组对象
            /// @param VAO 顶点数组对象
            /// @param VBOs 顶点缓冲对象
            /// @param usage 缓冲区用法
            virtual void generate_VAO(VertexArrayObject &VAO, VertexBufferObject &VBO, GLenum usage = GL_STATIC_DRAW) = 0;

            /// @brief 生成顶点数组对象
            /// @param VAO 顶点数组对象
            /// @param program 着色程序对象
            /// @param describer 顶点属性描述器
            /// @param usage 缓冲区用法
            virtual void generate_VAO(VertexArrayObject &VAO, const Program &program, const VertexAttribDescriber &describer, GLenum usage = GL_STATIC_DRAW) = 0;

            /// @brief 生成顶点数组对象
            /// @param VAO 顶点数组对象
            /// @param VBOs 顶点缓冲对象
            /// @param program 着色程序对象
            /// @param describer 顶点属性描述器
            /// @param usage 缓冲区用法
            virtual void generate_VAO(VertexArrayObject &VAO, VertexBufferObject &VBO, const Program &program, const VertexAttribDescriber &describer, GLenum usage = GL_STATIC_DRAW) = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
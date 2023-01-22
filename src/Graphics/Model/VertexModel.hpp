#ifndef __NEUTRON_GRAPHICS_TRIANGULATEDMODEL_HPP__
#define __NEUTRON_GRAPHICS_TRIANGULATEDMODEL_HPP__

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
        template <typename m_VertexType = Vertex, typename m_MatrixHolderType = Transform, typename m_ContainerType = std::vector<m_VertexType>>
        class VertexModel : public VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>
        {
        public:
            using VertexType = m_VertexType;
            using MatrixHolderType = m_MatrixHolderType;
            using ContainerType = m_ContainerType;
            using SelfType = VertexModel<VertexType, MatrixHolderType, ContainerType>;
            using ParentType = VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>;

        public:
            VertexModel();
            VertexModel(const ContainerType &vertices);
            VertexModel(const SelfType &from);
            ~VertexModel();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 生成顶点数组对象
            /// @param VAO 顶点数组对象
            /// @param program 着色程序对象
            /// @param describer 顶点属性描述器
            /// @param usage 缓冲区用法
            virtual void generate_VAO(VertexArrayObject &VAO, const Program &program, const VertexAttribDescriber &describer, GLenum usage = GL_STATIC_DRAW);

            /// @brief 生成顶点数组对象
            /// @param VAO 顶点数组对象
            /// @param VBOs 顶点缓冲对象，按VertexAttributeEnum::VertexAttributeLocation排序
            /// @param program 着色程序对象
            /// @param describer 顶点属性描述器
            /// @param usage 缓冲区用法
            virtual void generate_VAO(VertexArrayObject &VAO, VertexBufferObject &VBO, const Program &program, const VertexAttribDescriber &describer, GLenum usage = GL_STATIC_DRAW);
        };
    } // namespace Graphics

} // namespace ntk

#endif
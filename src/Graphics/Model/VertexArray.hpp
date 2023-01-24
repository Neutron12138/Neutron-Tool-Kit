#ifndef __NEUTRON_GRAPHICS_VERTEXARRAY_HPP__
#define __NEUTRON_GRAPHICS_VERTEXARRAY_HPP__

#include <vector>
#include "../Matrix/Applicable.hpp"
#include "Vertex.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 顶点数组，用于储存顶点
        /// @tparam m_VertexType 顶点类型
        /// @tparam m_MatrixHolderType 应用矩阵类型
        /// @tparam m_ContainerType 容器类型
        template <typename m_VertexType = Vertex, typename m_MatrixHolderType = Transform, typename m_ContainerType = std::vector<m_VertexType>>
        class VertexArray : public Applicable<m_MatrixHolderType>
        {
        public:
            using VertexType = m_VertexType;
            using MatrixHolderType = m_MatrixHolderType;
            using ContainerType = m_ContainerType;
            using SelfType = VertexArray<VertexType, MatrixHolderType, ContainerType>;

        protected:
            ContainerType m_vertices;

        public:
            VertexArray();
            VertexArray(const ContainerType &vertices);
            VertexArray(const SelfType &from);
            ~VertexArray();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 获取所有顶点
            /// @return 顶点容器
            const ContainerType &get_vertices() const;

            /// @brief 设置顶点数组
            /// @param vertices 顶点
            virtual void set_vertices(const ContainerType &vertices);

            /// @brief 获取顶点
            /// @param index 顶点索引
            /// @return 顶点
            const VertexType &get_vertex(std::size_t index) const;

            /// @brief 设置顶点
            /// @param index 顶点索引
            /// @param vertex 顶点
            virtual void set_vertex(std::size_t index, const VertexType &vertex);

            /// @brief 获取顶点总数
            /// @return 顶点总数
            virtual std::size_t size() const;

            /// @brief 清空容器
            virtual void clear();

        public:
            virtual void apply(const MatrixHolderType &matrix);
        };
    } // namespace Graphics

} // namespace ntk

#endif
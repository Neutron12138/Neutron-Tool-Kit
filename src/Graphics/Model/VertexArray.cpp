#ifndef __NEUTRON_GRAPHICS_VERTEXARRAY_CPP__
#define __NEUTRON_GRAPHICS_VERTEXARRAY_CPP__

#include "VertexArray.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::VertexArray() : m_vertices() {}
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::VertexArray(const ContainerType &vertices) : m_vertices(vertices) {}
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::VertexArray(const typename VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::SelfType &from) { *this = from; }
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::~VertexArray() {}

        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        typename VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::SelfType &VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::operator=(const typename VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::SelfType &from)
        {
            m_vertices = from.m_vertices;
            return *this;
        }

        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        const typename VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::ContainerType &VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::get_vertices() const
        {
            return m_vertices;
        }

        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        void VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::set_vertices(const typename VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::ContainerType &vertices)
        {
            m_vertices = vertices;
        }

        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        const typename VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::VertexType &VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::get_vertex(std::size_t index) const
        {
            return m_vertices.at(index);
        }

        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        void VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::set_vertex(std::size_t index, const typename VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::VertexType &vertex)
        {
            m_vertices.at(index) = vertex;
        }

        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        void VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::clear()
        {
            //m_vertices.clear();
        }

        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        void VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::apply(const typename VertexArray<m_VertexType, m_MatrixHolderType, m_ContainerType>::MatrixHolderType &matrix)
        {
            for (std::size_t i = 0; i < m_vertices.size(); i++)
            {
                m_vertices.at(i).apply(matrix);
            }
        }
    } // namespace Graphics

} // namespace ntk

#endif
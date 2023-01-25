#ifndef __NEUTRON_GRAPHICS_TRIANGLEFACE_CPP__
#define __NEUTRON_GRAPHICS_TRIANGLEFACE_CPP__

#include "TriangleFace.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_VertexType, typename m_MatrixHolderType>
        TriangleFace<m_VertexType, m_MatrixHolderType>::TriangleFace() {}
        template <typename m_VertexType, typename m_MatrixHolderType>
        TriangleFace<m_VertexType, m_MatrixHolderType>::TriangleFace(const typename TriangleFace<m_VertexType, m_MatrixHolderType>::ContainerType &vertices) : TriangleFace<m_VertexType, m_MatrixHolderType>::ParentType(vertices) {}
        template <typename m_VertexType, typename m_MatrixHolderType>
        TriangleFace<m_VertexType, m_MatrixHolderType>::TriangleFace(const typename TriangleFace<m_VertexType, m_MatrixHolderType>::VertexType &v0, const typename TriangleFace<m_VertexType, m_MatrixHolderType>::VertexType &v1, const typename TriangleFace<m_VertexType, m_MatrixHolderType>::VertexType &v2)
        {
            TriangleFace<m_VertexType, m_MatrixHolderType>::ParentType::m_vertices.at(0) = v0;
            TriangleFace<m_VertexType, m_MatrixHolderType>::ParentType::m_vertices.at(1) = v1;
            TriangleFace<m_VertexType, m_MatrixHolderType>::ParentType::m_vertices.at(2) = v2;
        }
        template <typename m_VertexType, typename m_MatrixHolderType>
        TriangleFace<m_VertexType, m_MatrixHolderType>::TriangleFace(const typename TriangleFace<m_VertexType, m_MatrixHolderType>::SelfType &from) { *this = from; }
        template <typename m_VertexType, typename m_MatrixHolderType>
        TriangleFace<m_VertexType, m_MatrixHolderType>::~TriangleFace() {}

        template <typename m_VertexType, typename m_MatrixHolderType>
        typename TriangleFace<m_VertexType, m_MatrixHolderType>::SelfType &TriangleFace<m_VertexType, m_MatrixHolderType>::operator=(const typename TriangleFace<m_VertexType, m_MatrixHolderType>::SelfType &from)
        {
            TriangleFace<m_VertexType, m_MatrixHolderType>::ParentType::operator=(from);
            return *this;
        }

        template <typename m_VertexType, typename m_MatrixHolderType>
        typename TriangleFace<m_VertexType, m_MatrixHolderType>::VertexType::NormalType TriangleFace<m_VertexType, m_MatrixHolderType>::calculate_face_normal() const
        {
            typename TriangleFace<m_VertexType, m_MatrixHolderType>::VertexType::PositionType A = TriangleFace<m_VertexType, m_MatrixHolderType>::ParentType::m_vertices.at(0).get_position();
            typename TriangleFace<m_VertexType, m_MatrixHolderType>::VertexType::PositionType B = TriangleFace<m_VertexType, m_MatrixHolderType>::ParentType::m_vertices.at(1).get_position();
            typename TriangleFace<m_VertexType, m_MatrixHolderType>::VertexType::PositionType C = TriangleFace<m_VertexType, m_MatrixHolderType>::ParentType::m_vertices.at(2).get_position();

            typename TriangleFace<m_VertexType, m_MatrixHolderType>::VertexType::PositionType AB = B - A;
            typename TriangleFace<m_VertexType, m_MatrixHolderType>::VertexType::PositionType AC = C - A;

            return static_cast<typename TriangleFace<m_VertexType, m_MatrixHolderType>::VertexType::NormalType>(glm::cross(AB, AC));
        }

        template <typename m_VertexType, typename m_MatrixHolderType>
        void TriangleFace<m_VertexType, m_MatrixHolderType>::clear()
        {
            TriangleFace<m_VertexType, m_MatrixHolderType>::ParentType::m_vertices = std::array<typename TriangleFace<m_VertexType, m_MatrixHolderType>::VertexType, 3>();
        }
    } // namespace Graphics

} // namespace ntk

#endif
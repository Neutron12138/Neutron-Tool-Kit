#ifndef __NEUTRON_GRAPHICS_BASICVERTEXMODEL_CPP__
#define __NEUTRON_GRAPHICS_BASICVERTEXMODEL_CPP__

#include "BasicVertexModel.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        BasicVertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::BasicVertexModel() {}
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        BasicVertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::BasicVertexModel(const typename BasicVertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::ContainerType &vertices) : BasicVertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::BasicVertexModel::ParentType(vertices) {}
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        BasicVertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::BasicVertexModel(const typename BasicVertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::SelfType &from) { *this = from; }
        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        BasicVertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::~BasicVertexModel() {}

        template <typename m_VertexType, typename m_MatrixHolderType, typename m_ContainerType>
        typename BasicVertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::SelfType &BasicVertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::operator=(const typename BasicVertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::SelfType &from)
        {
            BasicVertexModel<m_VertexType, m_MatrixHolderType, m_ContainerType>::ParentType::operator=(from);
            return *this;
        }
    } // namespace Graphics

} // namespace ntk

#endif
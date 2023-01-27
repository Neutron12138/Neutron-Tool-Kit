#ifndef __NEUTRON_UTILS_BASENODE_CPP__
#define __NEUTRON_UTILS_BASENODE_CPP__

#include "BaseNode.hpp"

namespace ntk
{
    namespace Utils
    {
        template <typename m_StringType, typename m_ChildNodeType>
        BaseNode<m_StringType, m_ChildNodeType>::BaseNode() {}
        template <typename m_StringType, typename m_ChildNodeType>
        BaseNode<m_StringType, m_ChildNodeType>::BaseNode(const m_StringType &name) : NamedObject<m_StringType>(name) {}
        template <typename m_StringType, typename m_ChildNodeType>
        BaseNode<m_StringType, m_ChildNodeType>::BaseNode(const BaseNode<m_StringType, m_ChildNodeType> &from) { *this = from; }
        template <typename m_StringType, typename m_ChildNodeType>
        BaseNode<m_StringType, m_ChildNodeType>::~BaseNode() {}

        template <typename m_StringType, typename m_ChildNodeType>
        BaseNode<m_StringType, m_ChildNodeType> &BaseNode<m_StringType, m_ChildNodeType>::operator=(const BaseNode<m_StringType, m_ChildNodeType> &from)
        {
            NamedObject<m_StringType>::operator=(from);
            return *this;
        }
    } // namespace Utils

} // namespace ntk

#endif
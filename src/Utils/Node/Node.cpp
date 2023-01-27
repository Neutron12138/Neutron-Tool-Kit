#ifndef __NEUTRON_UTILS_NODE_CPP__
#define __NEUTRON_UTILS_NODE_CPP__

#include <typeinfo>
#include "Node.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../String/StringUtils.hpp"

namespace ntk
{
    namespace Utils
    {
        template <typename m_StringType, typename m_ChildNodeType>
        Node<m_StringType, m_ChildNodeType>::Node() {}
        template <typename m_StringType, typename m_ChildNodeType>
        Node<m_StringType, m_ChildNodeType>::Node(const m_StringType &name) : BaseNode<m_StringType, m_ChildNodeType>(name) {}
        template <typename m_StringType, typename m_ChildNodeType>
        Node<m_StringType, m_ChildNodeType>::Node(const SelfType &from) { *this = from; }
        template <typename m_StringType, typename m_ChildNodeType>
        Node<m_StringType, m_ChildNodeType>::~Node() {}

        template <typename m_StringType, typename m_ChildNodeType>
        Node<m_StringType, m_ChildNodeType> &Node<m_StringType, m_ChildNodeType>::operator=(const Node<m_StringType, m_ChildNodeType> &from)
        {
            BaseNode<m_StringType, m_ChildNodeType>::operator=(from);
            m_child_nodes = from.m_child_nodes;
            return *this;
        }

        template <typename m_StringType, typename m_ChildNodeType>
        const std::map<m_StringType, m_ChildNodeType> &Node<m_StringType, m_ChildNodeType>::get_child_nodes() const
        {
            return m_child_nodes;
        }

        template <typename m_StringType, typename m_ChildNodeType>
        m_ChildNodeType &Node<m_StringType, m_ChildNodeType>::get_child_node(const m_StringType &name)
        {
            try
            {
                m_ChildNodeType &result = m_child_nodes.at(name);
                return result;
            }
            catch (const std::out_of_range &exception)
            {
                throw OutOfRangeException(Utils::to_string("Attempt to get non-existent child node:\"", name, "\""),
                                          Utils::to_string("\"template <typename m_StringType, typename m_ChildNodeType> Node<m_StringType,m_ChildNodeType> &Node<m_StringType,m_ChildNodeType>::get_child_node(const m_StringType &name)\"\n\"m_StringType\":\"", typeid(m_StringType).name(), "\""));
            }
            catch (const std::exception &exception)
            {
                throw Exception(exception.what(), "", "template <typename m_StringType, typename m_ChildNodeType> Node<m_StringType,m_ChildNodeType> &Node<m_StringType,m_ChildNodeType>::get_child_node(const m_StringType &name)");
            }
        }

        template <typename m_StringType, typename m_ChildNodeType>
        void Node<m_StringType, m_ChildNodeType>::add_child_node(const m_StringType &name, const m_ChildNodeType &child_node)
        {
            m_child_nodes.insert(std::pair<m_StringType, m_ChildNodeType>(name, child_node));
        }

        template <typename m_StringType, typename m_ChildNodeType>
        void Node<m_StringType, m_ChildNodeType>::remove_child_node(const m_StringType &name)
        {
            auto iter = m_child_nodes.find(name);
            if (iter != m_child_nodes.cend())
            {
                m_child_nodes.erase(iter);
            }
        }

        template <typename m_StringType, typename m_ChildNodeType>
        bool Node<m_StringType, m_ChildNodeType>::is_exist(const m_StringType &name)
        {
            auto iter = m_child_nodes.find(name);
            return iter != m_child_nodes.cend();
        }

        template <typename m_StringType, typename m_ChildNodeType>
        bool Node<m_StringType, m_ChildNodeType>::has_parent()
        {
            return false;
        }

        template <typename m_StringType, typename m_ChildNodeType>
        bool Node<m_StringType, m_ChildNodeType>::has_childs()
        {
            return !m_child_nodes.empty();
        }

        template <typename m_StringType, typename m_ChildNodeType>
        void Node<m_StringType, m_ChildNodeType>::clear_all()
        {
            m_child_nodes.clear();
        }
    } // namespace Utils

} // namespace ntk

#endif
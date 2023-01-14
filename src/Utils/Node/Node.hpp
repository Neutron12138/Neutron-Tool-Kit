#ifndef __NEUTRON_UTILS_NODE_HPP__
#define __NEUTRON_UTILS_NODE_HPP__

#include <map>
#include <string>
#include "BaseNode.hpp"

namespace ntk
{
    namespace Utils
    {
        template <typename m_StringType, typename m_ChildNodeType>
        class Node : public BaseNode<m_StringType, m_ChildNodeType>
        {
        public:
            using StringType = m_StringType;
            using ChildNodeType = m_ChildNodeType;
            using SelfType = Node<StringType, ChildNodeType>;

        protected:
            std::map<StringType, ChildNodeType> m_child_nodes;

        public:
            Node();
            Node(const StringType &name);
            Node(const SelfType &from);
            ~Node();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            const std::map<StringType, ChildNodeType> &get_child_nodes() const;

        public:
            virtual ChildNodeType &get_child_node(const StringType &name);
            virtual void add_child_node(const StringType &name, const ChildNodeType &child_node);
            virtual void remove_child_node(const StringType &name);
            virtual bool is_exist(const StringType &name);
            virtual bool has_parent();
            virtual bool has_childs();
            virtual void clear_all();
        };
    } // namespace Utils

} // namespace ntk

#endif
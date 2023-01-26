#ifndef __NEUTRON_UTILS_BASENODE_HPP__
#define __NEUTRON_UTILS_BASENODE_HPP__

#include "../../Base/NamedObject.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 基础节点类
        /// @tparam m_ChildNodeType 子节点类型，继承自BaseNode
        /// @tparam m_StringType 节点的名称字符串类型，默认为String
        template <typename m_StringType, typename m_ChildNodeType>
        class BaseNode : public NamedObject<m_StringType>
        {
        public:
            using StringType = m_StringType;
            using ChildNodeType = m_ChildNodeType;
            using SelfType = BaseNode<StringType, ChildNodeType>;

        public:
            BaseNode();
            BaseNode(const StringType &name);
            BaseNode(const SelfType &from);
            ~BaseNode();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 获取一个子节点
            /// @param name 要获取的子节点的名称
            /// @return 子节点
            virtual ChildNodeType &get_child_node(const StringType &name) = 0;

            /// @brief 添加一个子节点
            /// @param name 要添加的子节点的名称
            /// @param child_node 要添加的子节点
            virtual void add_child_node(const StringType &name, const ChildNodeType &child_node) = 0;

            /// @brief 移除一个子节点
            /// @param name 要移除的子节点的名称
            virtual void remove_child_node(const StringType &name) = 0;

            /// @brief 判断一个子节点是否存在
            /// @param name 要判断的子节点的名称
            /// @return 子节点是否存在
            virtual bool is_exist(const StringType &name) = 0;

            /// @brief 判断本节点是否存在父级
            /// @return 是否存在父级
            virtual bool has_parent() = 0;

            /// @brief 判断本节点是否存在子级
            /// @return 是否存在子级
            virtual bool has_childs() = 0;

            /// @brief 清除所有子节点
            virtual void clear_all() = 0;
        };
    } // namespace Utils

} // namespace ntk

#endif
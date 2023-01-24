#ifndef __NEUTRON_UTILS_RESOURCEDELETER_HPP__
#define __NEUTRON_UTILS_RESOURCEDELETER_HPP__

#include "../../Base/Type.hpp"
#include "../../Base/BasicDeleter.hpp"
#include "ResourceObject.hpp"

namespace ntk
{
    namespace Utils
    {
        // 资源删除器没有数组特化型
        // 因为无法指明具体要删除的元素个数
        // 请使用std::vector之类的代替

        /// @brief 资源删除器
        /// @tparam m_ResourceObjectType 资源对象类型
        template <typename m_ResourceObjectType>
        class ResourceDeleter : public BasicDeleter<m_ResourceObjectType>
        {
        public:
            using ResourceObjectType = m_ResourceObjectType;
            using SelfType = ResourceDeleter<ResourceObjectType>;

        public:
            ResourceDeleter();
            ResourceDeleter(const SelfType &from);
            ~ResourceDeleter();

        public:
            ResourceDeleter &operator=(const SelfType &from);
            void operator()(ResourceObjectType *ptr);
        };
    } // namespace Utils

} // namespace ntk

#endif
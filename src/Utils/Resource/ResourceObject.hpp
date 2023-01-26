#ifndef __NEUTRON_UTILS_RESOURCEOBJECT_HPP__
#define __NEUTRON_UTILS_RESOURCEOBJECT_HPP__

#include "../../Base/Object.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 资源对象的基类
        class ResourceObject : public Object
        {
        public:
            ResourceObject() = default;
            ResourceObject(const ResourceObject &from) = default;
            ~ResourceObject() = default;

        public:
            ResourceObject &operator=(const ResourceObject &from) = default;

        public:
            /// @brief 释放所持有的资源
            virtual void release() = 0;
        };
    } // namespace Utils

} // namespace ntk

#endif
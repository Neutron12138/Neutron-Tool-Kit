#ifndef __NEUTRON_UTILS_ALOBJECTDELETER_HPP__
#define __NEUTRON_UTILS_ALOBJECTDELETER_HPP__

#include "../../../Base/BasicDeleter.hpp"

namespace ntk
{
    namespace Utils
    {
        // OpenAL对象删除器没有数组特化型
        // 因为无法指明具体要删除的元素个数
        // 请使用std::vector之类的代替

        /// @brief 资源删除器
        /// @tparam m_ALObjectType 资源对象类型
        template <typename m_ALObjectType>
        class ALObjectDeleter : public BasicDeleter<m_ALObjectType>
        {
        public:
            using ALObjectType = m_ALObjectType;
            using SelfType = ALObjectDeleter<ALObjectType>;

        public:
            ALObjectDeleter();
            ALObjectDeleter(const SelfType &from);
            ~ALObjectDeleter();

        public:
            SelfType &operator=(const SelfType &from);
            void operator()(ALObjectType *ptr);
        };
    } // namespace Utils

} // namespace ntk

#endif
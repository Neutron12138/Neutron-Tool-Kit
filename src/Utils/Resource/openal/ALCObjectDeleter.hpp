#ifndef __NEUTRON_UTILS_ALCOBJECTDELETER_HPP__
#define __NEUTRON_UTILS_ALCOBJECTDELETER_HPP__

#include "../../../Base/BasicDeleter.hpp"

namespace ntk
{
    namespace Utils
    {
        // OpenAL对象删除器没有数组特化型
        // 因为无法指明具体要删除的元素个数
        // 请使用std::vector之类的代替

        /// @brief 资源删除器
        /// @tparam m_ALCObjectType 资源对象类型
        template <typename m_ALCObjectType>
        class ALCObjectDeleter : public BasicDeleter<m_ALCObjectType>
        {
        public:
            using ALCObjectType = m_ALCObjectType;
            using SelfType = ALCObjectDeleter<ALCObjectType>;

        public:
            ALCObjectDeleter();
            ALCObjectDeleter(const SelfType &from);
            ~ALCObjectDeleter();

        public:
            SelfType &operator=(const SelfType &from);
            void operator()(ALCObjectType *ptr);
        };
    } // namespace Utils

} // namespace ntk

#endif
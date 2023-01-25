#ifndef __NEUTRON_UTILS_SHAREDPOINTER_HPP__
#define __NEUTRON_UTILS_SHAREDPOINTER_HPP__

#include <memory>
#include "../../Base/Pointer.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 共享指针类型，所有指针共享同一份资源
        /// @tparam m_DataType 指针类型
        template <typename m_DataType>
        class SharedPointer : public Pointer<m_DataType>, public std::shared_ptr<m_DataType>
        {
        public:
            using DataType = m_DataType;
            using AutoPointerType = std::shared_ptr<DataType>;
            using SelfType = SharedPointer<DataType>;
            using ParentType = AutoPointerType;

        public:
            SharedPointer() = default;
            SharedPointer(DataType *ptr);
            template <typename DeleterType>
            SharedPointer(DataType *ptr, DeleterType deleter);
            SharedPointer(const SelfType &from) = default;
            ~SharedPointer() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;
            virtual DataType &operator*() const;
            virtual DataType *operator->() const;

        public:
            virtual DataType *get() const;
        };
    } // namespace Utils

} // namespace ntk

#endif
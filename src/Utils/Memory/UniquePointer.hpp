#ifndef __NEUTRON_UTILS_UNIQUEPOINTER_HPP__
#define __NEUTRON_UTILS_UNIQUEPOINTER_HPP__

#include <memory>
#include "../../Base/Pointer.hpp"
#include "../../Base/BasicDeleter.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 专有指针类型，只能有一个指针拥有资源
        /// @tparam m_DataType 指针类型
        /// @tparam m_DeleterType 删除器类型
        template <typename m_DataType, typename m_DeleterType = BasicDeleter<m_DataType>>
        class UniquePointer : public Pointer<m_DataType>, public std::unique_ptr<m_DataType, m_DeleterType>
        {
        public:
            using DataType = m_DataType;
            using DeleterType = m_DeleterType;
            using AutoPointerType = std::unique_ptr<DataType, DeleterType>;
            using SelfType = UniquePointer<DataType, DeleterType>;
            using ParentType = AutoPointerType;

        public:
            UniquePointer() = default;
            UniquePointer(DataType *ptr);
            UniquePointer(DataType *ptr, DeleterType deleter);
            UniquePointer(const SelfType &from) = delete;
            UniquePointer(SelfType &&from);
            ~UniquePointer() = default;

        public:
            SelfType &operator=(const SelfType &from) = delete;
            SelfType &operator=(SelfType &&from);
            virtual DataType &operator*() const;
            virtual DataType *operator->() const;

        public:
            virtual DataType *get() const;
        };

        /// @brief 专有数组类型，只能有一个指针拥有资源
        /// @tparam m_DataType 指针类型
        /// @tparam m_DeleterType 删除器类型
        template <typename m_DataType, typename m_DeleterType>
        class UniquePointer<m_DataType[], m_DeleterType> : public Pointer<m_DataType>, public std::unique_ptr<m_DataType[], m_DeleterType>
        {
        public:
            using DataType = m_DataType;
            using DeleterType = m_DeleterType;
            using AutoPointerType = std::unique_ptr<DataType[], DeleterType>;
            using SelfType = UniquePointer<DataType[], DeleterType>;
            using ParentType = AutoPointerType;

        public:
            UniquePointer() = default;
            UniquePointer(DataType *ptr);
            UniquePointer(DataType *ptr, DeleterType deleter);
            UniquePointer(const SelfType &from) = delete;
            UniquePointer(SelfType &&from);
            ~UniquePointer() = default;

        public:
            SelfType &operator=(const SelfType &from) = delete;
            SelfType &operator=(SelfType &&from);
            virtual DataType &operator*() const;
            virtual DataType *operator->() const;
            virtual DataType &operator[](std::size_t index);

        public:
            virtual DataType *get() const;
        };
    } // namespace Utils

} // namespace ntk

#endif
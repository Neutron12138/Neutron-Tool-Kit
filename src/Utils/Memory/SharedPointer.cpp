#ifndef __NEUTRON_UTILS_SHAREDPOINTER_CPP__
#define __NEUTRON_UTILS_SHAREDPOINTER_CPP__

#include "SharedPointer.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntk
{
    namespace Utils
    {
        template <typename m_DataType>
        SharedPointer<m_DataType>::SharedPointer(typename SharedPointer<m_DataType>::DataType *ptr) : SharedPointer<m_DataType>::ParentType(ptr) {}
        template <typename m_DataType>
        template <typename DeleterType>
        SharedPointer<m_DataType>::SharedPointer(typename SharedPointer<m_DataType>::DataType *ptr, DeleterType deleter) : SharedPointer<m_DataType>::ParentType(ptr, deleter) {}

        template <typename m_DataType>
        typename SharedPointer<m_DataType>::DataType &SharedPointer<m_DataType>::operator*() const
        {
            if (Pointer<m_DataType>::is_nullptr())
                throw NullPointerException("template <typename m_DataType> typename SharedPointer<m_DataType>::DataType &SharedPointer<m_DataType>::operator*()");
            return *get();
        }

        template <typename m_DataType>
        typename SharedPointer<m_DataType>::DataType *SharedPointer<m_DataType>::operator->() const
        {
            return get();
        }

        template <typename m_DataType>
        typename SharedPointer<m_DataType>::DataType *SharedPointer<m_DataType>::get() const
        {
            return SharedPointer<m_DataType>::ParentType::get();
        }
    } // namespace Utils

} // namespace ntk

#endif
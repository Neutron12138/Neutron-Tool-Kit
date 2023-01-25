#ifndef __NEUTRON_BASE_POINTER_CPP__
#define __NEUTRON_BASE_POINTER_CPP__

#include <memory>
#include "Pointer.hpp"
#include "../Utils/Exception/NullPointerException.hpp"

namespace ntk
{
    template <typename m_DataType>
    typename Pointer<m_DataType>::DataType &Pointer<m_DataType>::operator*() const
    {
        if (is_nullptr())
            throw Utils::NullPointerException("template <typename m_DataType> typename Pointer<m_DataType>::Type &Pointer<m_DataType>::operator*()");
        return *get();
    }

    template <typename m_DataType>
    typename Pointer<m_DataType>::DataType *Pointer<m_DataType>::operator->() const
    {
        return get();
    }

    template <typename m_DataType>
    bool Pointer<m_DataType>::is_nullptr() const
    {
        return get() == nullptr;
    }
} // namespace ntk

#endif
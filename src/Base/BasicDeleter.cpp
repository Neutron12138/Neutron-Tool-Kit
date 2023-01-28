#ifndef __NEUTRON_BASE_BASICDELETER_CPP__
#define __NEUTRON_BASE_BASICDELETER_CPP__

#include "BasicDeleter.hpp"

namespace ntk
{
    template <typename m_DataType>
    void BasicDeleter<m_DataType>::operator()(m_DataType *ptr) const
    {
        delete ptr;
    }

    template <typename m_DataType>
    void BasicDeleter<m_DataType[]>::operator()(m_DataType *ptr) const
    {
        delete[] ptr;
    }
} // namespace ntk

#endif
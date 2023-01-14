#ifndef __NEUTRON_BASE_BASICDELETER_CPP__
#define __NEUTRON_BASE_BASICDELETER_CPP__

#include "BasicDeleter.hpp"

namespace ntk
{
    template <typename m_DataType>
    BasicDeleter<m_DataType>::BasicDeleter() {}
    template <typename m_DataType>
    BasicDeleter<m_DataType>::BasicDeleter(const BasicDeleter<m_DataType> &from) {}
    template <typename m_DataType>
    BasicDeleter<m_DataType>::~BasicDeleter() {}
    template <typename m_DataType>
    BasicDeleter<m_DataType> &BasicDeleter<m_DataType>::operator=(const BasicDeleter<m_DataType> &from) { return *this; }

    template <typename m_DataType>
    void BasicDeleter<m_DataType>::operator()(m_DataType *ptr)
    {
        delete ptr;
    }

    template <typename m_DataType>
    BasicDeleter<m_DataType[]>::BasicDeleter() {}
    template <typename m_DataType>
    BasicDeleter<m_DataType[]>::BasicDeleter(const BasicDeleter<m_DataType[]> &from) {}
    template <typename m_DataType>
    BasicDeleter<m_DataType[]>::~BasicDeleter() {}
    template <typename m_DataType>
    BasicDeleter<m_DataType[]> &BasicDeleter<m_DataType[]>::operator=(const BasicDeleter<m_DataType[]> &from) { return *this; }

    template <typename m_DataType>
    void BasicDeleter<m_DataType[]>::operator()(m_DataType *ptr)
    {
        delete[] ptr;
    }
} // namespace ntk

#endif
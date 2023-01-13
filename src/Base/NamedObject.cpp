#ifndef __NEUTRON_BASE_NAMEDOBJECT_CPP__
#define __NEUTRON_BASE_NAMEDOBJECT_CPP__

#include "NamedObject.hpp"

namespace ntk
{
    template <typename m_StringType>
    NamedObject<m_StringType>::NamedObject() {}
    template <typename m_StringType>
    NamedObject<m_StringType>::NamedObject(const m_StringType &name) : m_name(name) {}
    template <typename m_StringType>
    NamedObject<m_StringType>::NamedObject(const NamedObject<m_StringType> &from) { *this = from; }
    template <typename m_StringType>
    NamedObject<m_StringType>::~NamedObject() {}

    template <typename m_StringType>
    NamedObject<m_StringType> &NamedObject<m_StringType>::operator=(const NamedObject<m_StringType> &from)
    {
        m_name = from.m_name;
        return *this;
    }

    template <typename m_StringType>
    const m_StringType &NamedObject<m_StringType>::get_name() const
    {
        return m_name;
    }

    template <typename m_StringType>
    void NamedObject<m_StringType>::set_name(const m_StringType &name)
    {
        m_name = name;
    }
} // namespace ntk

#endif
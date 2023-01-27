#ifndef __NEUTRON_GRAPHICS_INSTANCINGDATAARRAY_CPP__
#define __NEUTRON_GRAPHICS_INSTANCINGDATAARRAY_CPP__

#include "InstancingDataArray.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_InstancingDataType, typename m_ContainerType>
        InstancingDataArray<m_InstancingDataType, m_ContainerType>::InstancingDataArray(const ContainerType &data) : m_data(data) {}

        template <typename m_InstancingDataType, typename m_ContainerType>
        typename InstancingDataArray<m_InstancingDataType, m_ContainerType>::InstancingDataType &InstancingDataArray<m_InstancingDataType, m_ContainerType>::operator[](std::size_t index)
        {
            return m_data.at(index);
        }

        template <typename m_InstancingDataType, typename m_ContainerType>
        const typename InstancingDataArray<m_InstancingDataType, m_ContainerType>::ContainerType &InstancingDataArray<m_InstancingDataType, m_ContainerType>::get_data() const
        {
            return m_data;
        }

        template <typename m_InstancingDataType, typename m_ContainerType>
        const typename InstancingDataArray<m_InstancingDataType, m_ContainerType>::InstancingDataType &InstancingDataArray<m_InstancingDataType, m_ContainerType>::get_data(std::size_t index) const
        {
            return m_data.at(index);
        }

        template <typename m_InstancingDataType, typename m_ContainerType>
        void InstancingDataArray<m_InstancingDataType, m_ContainerType>::set_data(const typename InstancingDataArray<m_InstancingDataType, m_ContainerType>::ContainerType &data)
        {
            m_data = data;
        }

        template <typename m_InstancingDataType, typename m_ContainerType>
        void InstancingDataArray<m_InstancingDataType, m_ContainerType>::set_data(std::size_t index, const typename InstancingDataArray<m_InstancingDataType, m_ContainerType>::InstancingDataType &data)
        {
            m_data.at(index) = data;
        }

        template <typename m_InstancingDataType, typename m_ContainerType>
        const std::size_t InstancingDataArray<m_InstancingDataType, m_ContainerType>::size() const
        {
            return m_data.size();
        }
    } // namespace Graphics

} // namespace ntk

#endif
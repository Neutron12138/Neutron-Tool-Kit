#ifndef __NEUTRON_GRAPHICS_BASICDRAWPROCEDURE_CPP__
#define __NEUTRON_GRAPHICS_BASICDRAWPROCEDURE_CPP__

#include "BasicDrawProcedure.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_DrawInfoType, typename m_ContainerType>
        BasicDrawProcedure<m_DrawInfoType, m_ContainerType>::BasicDrawProcedure(const ContainerType &procedures) : m_procedures(procedures) {}

        template <typename m_DrawInfoType, typename m_ContainerType>
        const typename BasicDrawProcedure<m_DrawInfoType, m_ContainerType>::ContainerType &BasicDrawProcedure<m_DrawInfoType, m_ContainerType>::get() const
        {
            return m_procedures;
        }

        template <typename m_DrawInfoType, typename m_ContainerType>
        void BasicDrawProcedure<m_DrawInfoType, m_ContainerType>::set(const typename BasicDrawProcedure<m_DrawInfoType, m_ContainerType>::ContainerType &procedures)
        {
            m_procedures = procedures;
        }

        template <typename m_DrawInfoType, typename m_ContainerType>
        const typename BasicDrawProcedure<m_DrawInfoType, m_ContainerType>::DrawInfoType &BasicDrawProcedure<m_DrawInfoType, m_ContainerType>::get(std::size_t index) const
        {
            return m_procedures.at(index);
        }

        template <typename m_DrawInfoType, typename m_ContainerType>
        void BasicDrawProcedure<m_DrawInfoType, m_ContainerType>::set(std::size_t index, const typename BasicDrawProcedure<m_DrawInfoType, m_ContainerType>::DrawInfoType &draw_info)
        {
            m_procedures.at(index) = draw_info;
        }

        template <typename m_DrawInfoType, typename m_ContainerType>
        void BasicDrawProcedure<m_DrawInfoType, m_ContainerType>::draw()
        {
            for (auto ptr = m_procedures.cbegin(); ptr != m_procedures.cend(); ptr++)
            {
                ptr->draw();
            }
        }
    } // namespace Graphics

} // namespace ntk

#endif
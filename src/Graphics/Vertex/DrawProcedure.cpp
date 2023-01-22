#ifndef __NEUTRON_GRAPHICS_DRAWPROCEDURE_CPP__
#define __NEUTRON_GRAPHICS_DRAWPROCEDURE_CPP__

#include "BasicDrawProcedure.hpp"

namespace ntk
{
    namespace Graphics
    {

        BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::BasicDrawProcedure(const typename BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::ContainerType &procedures) : m_procedures(procedures) {}

        const typename BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::ContainerType &BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::get() const
        {
            return m_procedures;
        }

        void BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::set(const ContainerType &procedures)
        {
            m_procedures = procedures;
        }

        const typename BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::DrawInfoType &BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::get(std::size_t index) const
        {
            return m_procedures.at(index);
        }

        void BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::set(std::size_t index, const typename BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::DrawInfoType &draw_info)
        {
            m_procedures.at(index) = draw_info;
        }

        void BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::push(const typename BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::DrawInfoType &draw_info)
        {
            m_procedures.push_back(draw_info);
        }

        void BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::pop()
        {
            m_procedures.pop_back();
        }

        void BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>::draw()
        {
            for (auto ptr = m_procedures.cbegin(); ptr != m_procedures.cend(); ptr++)
            {
                ptr->draw();
            }
        }
    } // namespace Graphics

} // namespace ntk

#endif
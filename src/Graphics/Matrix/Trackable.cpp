#ifndef __NEUTRON_GRAPHICS_TRACKABLE_CPP__
#define __NEUTRON_GRAPHICS_TRACKABLE_CPP__

#include "Trackable.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_PositionType>
        Trackable<m_PositionType>::Trackable() {}
        template <typename m_PositionType>
        Trackable<m_PositionType>::Trackable(const Trackable<m_PositionType> &from) {}
        template <typename m_PositionType>
        Trackable<m_PositionType>::~Trackable() {}
        template <typename m_PositionType>
        Trackable<m_PositionType> &Trackable<m_PositionType>::operator=(const Trackable<m_PositionType> &from) { return *this; }
    } // namespace Graphics

} // namespace ntk

#endif
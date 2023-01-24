#ifndef __NEUTRON_GRAPHICS_ORBITVIEW_CPP__
#define __NEUTRON_GRAPHICS_ORBITVIEW_CPP__

#include "OrbitView.hpp"

namespace ntk
{
    namespace Graphics
    {
        OrbitView::OrbitView() : TrackingView() {}
        OrbitView::OrbitView(Trackable<> *target_object) : TrackingView(target_object) {}
        OrbitView::OrbitView(const OrbitView &from) { *this = from; }
        OrbitView::~OrbitView() {}

        OrbitView &OrbitView::operator=(const OrbitView &from)
        {
            TrackingView::operator=(from);
            return *this;
        }

        void OrbitView::update()
        {
            if (m_target_object != nullptr)
                m_target = m_target_object->get_position();
            m_matrix = glm::lookAt(m_target + m_position, m_target, m_up);
        }
    } // namespace Graphics

} // namespace ntk

#endif
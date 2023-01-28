#ifndef __NEUTRON_GRAPHICS_TRACKINGVIEW_CPP__
#define __NEUTRON_GRAPHICS_TRACKINGVIEW_CPP__

#include "TrackingView.hpp"

namespace ntk
{
    namespace Graphics
    {
        TrackingView::TrackingView() : View() { update(); }
        TrackingView::TrackingView(Trackable<> *target_object) : View(), m_target_object(target_object) { update(); }
        TrackingView::TrackingView(const TrackingView &from) { *this = from; }
        TrackingView::~TrackingView() {}

        TrackingView &TrackingView::operator=(const TrackingView &from)
        {
            View::operator=(from);
            m_target_object = from.m_target_object;
            return *this;
        }

        Trackable<> *TrackingView::get_target_object() const
        {
            return m_target_object;
        }

        void TrackingView::set_target_object(Trackable<> *target_object)
        {
            m_target_object = target_object;
        }

        void TrackingView::update()
        {
            if (m_target_object != nullptr)
                m_target = m_target_object->get_position();
            m_matrix = glm::lookAt(m_position, m_target, m_up);
        }
    } // namespace Graphics

} // namespace ntk

#endif
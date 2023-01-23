#ifndef __NEUTRON_GRAPHICS_ORBITVIEW_HPP__
#define __NEUTRON_GRAPHICS_ORBITVIEW_HPP__

#include "TrackingView.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 环绕视图
        class OrbitView : public TrackingView
        {
        public:
            OrbitView();
            OrbitView(Trackable<> *target_object);
            OrbitView(const OrbitView &from);
            ~OrbitView();

        public:
            OrbitView &operator=(const OrbitView &from);

        public:
            virtual void update();
        };
    } // namespace Graphics

} // namespace ntk

#endif
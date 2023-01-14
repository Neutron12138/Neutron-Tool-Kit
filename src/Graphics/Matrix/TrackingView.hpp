#ifndef __NEUTRON_GRAPHICS_TRACKINGVIEW_HPP__
#define __NEUTRON_GRAPHICS_TRACKINGVIEW_HPP__

#include "View.hpp"
#include "Trackable.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 追踪视图
        class TrackingView : public View
        {
        protected:
            /// @brief 正在追踪的目标对象
            Trackable<> *m_target_object = nullptr;

        public:
            TrackingView();
            TrackingView(Trackable<> *target_object);
            TrackingView(const TrackingView &from);
            ~TrackingView();

        public:
            TrackingView &operator=(const TrackingView &from);

        public:
            /// @brief 获取追踪目标
            /// @return 正在追踪的目标对象
            Trackable<> *get_target_object() const;

            /// @brief 设置追踪目标
            /// @param target_object 要追踪的目标
            virtual void set_target_object(Trackable<> *target_object);

        public:
            virtual void update();
        };
    } // namespace Graphics

} // namespace ntk

#endif
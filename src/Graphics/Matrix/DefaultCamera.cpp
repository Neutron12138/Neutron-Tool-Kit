#ifndef __NEUTRON_GRAPHICS_DEFAULTCAMERA_CPP__
#define __NEUTRON_GRAPHICS_DEFAULTCAMERA_CPP__

#include "DefaultCamera.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_ViewType, typename m_ProjectionType>
        DefaultCamera<m_ViewType, m_ProjectionType>::DefaultCamera() : m_ViewType(), m_ProjectionType() {}
        template <typename m_ViewType, typename m_ProjectionType>
        DefaultCamera<m_ViewType, m_ProjectionType>::DefaultCamera(const DefaultCamera<m_ViewType, m_ProjectionType> &from) { *this = from; }
        template <typename m_ViewType, typename m_ProjectionType>
        DefaultCamera<m_ViewType, m_ProjectionType>::~DefaultCamera() {}

        template <typename m_ViewType, typename m_ProjectionType>
        DefaultCamera<m_ViewType, m_ProjectionType> &DefaultCamera<m_ViewType, m_ProjectionType>::operator=(const DefaultCamera<m_ViewType, m_ProjectionType> &from)
        {
            m_ViewType::operator=(from);
            m_ProjectionType::operator=(from);
            return *this;
        }

        template <typename m_ViewType, typename m_ProjectionType>
        void DefaultCamera<m_ViewType, m_ProjectionType>::set_uniforms(UniformBinder &binder, const UniformDescriber &describer)
        {
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::ProjectionMatrix), get_projection());
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::ViewMatrix), get_view());
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::ViewPosition), m_ViewType::get_position());
        }

        template <typename m_ViewType, typename m_ProjectionType>
        const glm::mat4 &DefaultCamera<m_ViewType, m_ProjectionType>::get_view() const
        {
            return m_ViewType::get_matrix();
        }

        template <typename m_ViewType, typename m_ProjectionType>
        const glm::mat4 &DefaultCamera<m_ViewType, m_ProjectionType>::get_projection() const
        {
            return m_ProjectionType::get_matrix();
        }

        template <typename m_ViewType, typename m_ProjectionType>
        void DefaultCamera<m_ViewType, m_ProjectionType>::update_view()
        {
            m_ViewType::update();
        }

        template <typename m_ViewType, typename m_ProjectionType>
        void DefaultCamera<m_ViewType, m_ProjectionType>::update_projection()
        {
            m_ProjectionType::update();
        }
    } // namespace Graphics

} // namespace ntk

#endif
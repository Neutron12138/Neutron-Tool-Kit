#ifndef __NEUTRON_GRAPHICS_DEFAULTCAMERA_HPP__
#define __NEUTRON_GRAPHICS_DEFAULTCAMERA_HPP__

#include "Camera.hpp"
#include "View.hpp"
#include "PerspectiveProjection.hpp"
#include "../Shade/UniformBinder.hpp"
#include "../Shade/UniformNameEnum.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 默认摄像机
        /// @tparam m_ViewType 视图类型，继承自View
        /// @tparam m_ProjectionType 投影类型，继承自Projection
        template <typename m_ViewType = View, typename m_ProjectionType = PerspectiveProjection>
        class DefaultCamera : public Camera, public m_ViewType, public m_ProjectionType
        {
        public:
            using ViewType = m_ViewType;
            using ProjectionType = m_ProjectionType;
            using SelfType = DefaultCamera<ViewType, ProjectionType>;

        public:
            DefaultCamera();
            DefaultCamera(const SelfType &from);
            ~DefaultCamera();

        public:
            DefaultCamera &operator=(const SelfType &from);

            public:
            virtual void set_uniforms(UniformBinder& binder,const UniformDescriber& describer);

        public:
            virtual const glm::mat4 &get_view() const;
            virtual const glm::mat4 &get_projection() const;
            virtual void update_view();
            virtual void update_projection();
        };
    } // namespace Graphics

} // namespace ntk

#endif
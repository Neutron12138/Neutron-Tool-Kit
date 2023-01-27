#ifndef __NEUTRON_GRAPHICS_PERSPECTIVEPROJECTION_HPP__
#define __NEUTRON_GRAPHICS_PERSPECTIVEPROJECTION_HPP__

#include "Projection.hpp"

namespace ntk
{
    namespace Graphics
    {
        class PerspectiveProjection : public Projection
        {
        protected:
            /// @brief 视野
            float m_fovy = 60.0f;

            /// @brief 宽高比
            float m_aspect = 1.0f;

        public:
            PerspectiveProjection();
            PerspectiveProjection(float fovy, float aspect, float zNear, float zFar);
            PerspectiveProjection(const PerspectiveProjection &from);
            ~PerspectiveProjection();

        public:
            PerspectiveProjection &operator=(const PerspectiveProjection &from);

        public:
            /// @brief 获取视野大小
            /// @return 视野大小
            float get_fovy() const;

            /// @brief 获取宽高比
            /// @return 宽高比
            float get_aspect() const;

            /// @brief 设置视野
            /// @param fovy 视野
            virtual void set_fovy(float fovy);

            /// @brief 设置宽高比
            /// @param aspect 宽高比
            virtual void set_aspect(float aspect);

        public:
            virtual void update();
        };
    } // namespace Graphics

} // namespace ntk

#endif
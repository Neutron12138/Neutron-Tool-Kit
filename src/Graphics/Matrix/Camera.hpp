#ifndef __NEUTRON_GRAPHICS_CAMERA_HPP__
#define __NEUTRON_GRAPHICS_CAMERA_HPP__

#include <glm/glm.hpp>
#include "../../Base/Object.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 摄像机类
        class Camera : public Object
        {
        public:
            Camera();
            Camera(const Camera &from);
            ~Camera();

        public:
            Camera &operator=(const Camera &from);

        public:
            /// @brief 获取视图矩阵
            /// @return 视图矩阵
            virtual const glm::mat4 &get_view() const = 0;

            /// @brief 获取投影矩阵
            /// @return 投影矩阵
            virtual const glm::mat4 &get_projection() const = 0;

            /// @brief 更新视图矩阵
            virtual void update_view() = 0;

            /// @brief 更新投影矩阵
            virtual void update_projection() = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
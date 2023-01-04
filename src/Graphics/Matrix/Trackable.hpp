#ifndef __NEUTRON_GRAPHICS_TRACKABLE_HPP__
#define __NEUTRON_GRAPHICS_TRACKABLE_HPP__

#include <glm/glm.hpp>
#include "../../Base/Object.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 可追踪的对象
        /// @tparam m_PositionType 对象的位置类型
        template <typename m_PositionType = glm::vec3>
        class Trackable : public Object
        {
        public:
            using PositionType = m_PositionType;
            using SelfType = Trackable<PositionType>;

        public:
            Trackable();
            Trackable(const SelfType &from);
            ~Trackable();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 获取位置
            /// @return 位置
            virtual const PositionType &get_position() const = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
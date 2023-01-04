#ifndef __NEUTRON_GRAPHICS_SPRITE_HPP__
#define __NEUTRON_GRAPHICS_SPRITE_HPP__

#include "../Renderable.hpp"
#include "../Matrix/Transform.hpp"
#include "../Matrix/Trackable.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 精灵类
        class Sprite : public Renderable, public Transform, public Trackable<glm::vec3>
        {
        public:
            using PositionType = glm::vec3;

        public:
            Sprite();
            Sprite(const glm::vec3 &translation, const glm::vec3 &rotation, const glm::vec3 &scale);
            Sprite(const Sprite &from);
            ~Sprite();

        public:
            Sprite &operator=(const Sprite &from);

        public:
            virtual const PositionType &get_position() const;
        };
    } // namespace Graphics

} // namespace ntk

#endif
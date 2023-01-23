#ifndef __NEUTRON_GRAPHICS_SPRITE2D_HPP__
#define __NEUTRON_GRAPHICS_SPRITE2D_HPP__

#include "../Renderable.hpp"
#include "../Matrix/Transform2D.hpp"
#include "../Matrix/Trackable.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 2D精灵类
        class Sprite2D : public Renderable, public Transform2D, public Trackable<glm::vec2>
        {
        public:
            using PositionType = glm::vec2;

        public:
            Sprite2D();
            Sprite2D(const glm::vec2 &translation, float rotation, const glm::vec2 &scale);
            Sprite2D(const Sprite2D &from);
            ~Sprite2D();

        public:
            Sprite2D &operator=(const Sprite2D &from);

        public:
            virtual PositionType get_position() const;
        };
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_POINTSHAPE_HPP__
#define __NEUTRON_GRAPHICS_POINTSHAPE_HPP__

#include "../BaseShape.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 点精灵
        class PointShape : public BaseShape
        {
        public:
            PointShape();
            PointShape(const glm::vec2 &position);
            PointShape(const PointShape &from);
            ~PointShape();

        public:
            PointShape &operator=(const PointShape &from);

        public:
            virtual void generate_shape();
            virtual void update_VAO();
            virtual void render();
            virtual void render(UniformBinder &binder, const UniformDescriber &describer);
        };
    } // namespace Graphics

} // namespace ntk

#endif
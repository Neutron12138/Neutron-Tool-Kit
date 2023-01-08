#ifndef __NEUTRON_GRAPHICS_CUBOIDSPATIAL_HPP__
#define __NEUTRON_GRAPHICS_CUBOIDSPATIAL_HPP__

#include "../BaseSpatial.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 长方体
        /// @tparam m_MaterialType 材质类型
        template <typename m_MaterialType = Material<>>
        class CuboidSpatial : public BaseSpatial<m_MaterialType>
        {
        public:
            using MaterialType = m_MaterialType;
            using SelfType = CuboidSpatial<MaterialType>;

        protected:
            /// @brief 长方体的位置
            glm::vec3 m_cuboid_position = glm::vec3(0.0f, 0.0f, 0.0f);
            /// @brief 长方体的大小
            glm::vec3 m_cuboid_size = glm::vec3(0.0f, 0.0f, 0.0f);

        public:
            CuboidSpatial();
            CuboidSpatial(const glm::vec3 &position, const glm::vec3 &size);
            CuboidSpatial(const SelfType &from);
            ~CuboidSpatial();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 获取长方体的位置
            /// @return 长方体的位置
            const glm::vec3 &get_cuboid_position() const;

            /// @brief 设置长方体的位置
            /// @param position 长方体的位置
            virtual void set_cuboid_position(const glm::vec3 &position);

            /// @brief 获取长方体的大小
            /// @return 长方体的大小
            const glm::vec3 &get_cuboid_size() const;

            /// @brief 设置长方体的大小
            /// @param size 长方体的大小
            virtual void set_cuboid_size(const glm::vec3 &size);

        public:
            virtual void generate_shape();
            virtual void update_VAO();
            virtual void render();
            virtual void render(UniformBinder &binder, const UniformDescriber &describer);
        };
    } // namespace Graphics

} // namespace ntk

#endif
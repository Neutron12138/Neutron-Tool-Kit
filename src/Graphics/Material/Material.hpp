#ifndef __NEUTRON_GRAPHICS_MATERIAL_HPP__
#define __NEUTRON_GRAPHICS_MATERIAL_HPP__

#include <glm/glm.hpp>
#include "../../Base/Object.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 材料类
        /// @tparam m_AmbientType 环境光类型。可以是一个颜色，也可以是一张纹理。
        /// @tparam m_DiffuseType 漫射光类型。可以是一个颜色，也可以是一张纹理。
        /// @tparam m_SpecularType 镜面光类型。可以是一个颜色，也可以是一张纹理。
        /// @tparam m_EmissionType 自发光类型。可以是一个颜色，也可以是一张纹理。
        template <typename m_AmbientType = glm::vec4, typename m_DiffuseType = glm::vec4, typename m_SpecularType = glm::vec4, typename m_EmissionType = glm::vec4>
        class Material : public Object
        {
        public:
            using AmbientType = m_AmbientType;
            using DiffuseType = m_DiffuseType;
            using SpecularType = m_SpecularType;
            using EmissionType = m_EmissionType;
            using SelfType = Material<AmbientType, DiffuseType, SpecularType, EmissionType>;

        protected:
            /// @brief 环境光
            AmbientType m_ambient;
            /// @brief 漫射光
            DiffuseType m_diffuse;
            /// @brief 镜面光
            SpecularType m_specular;
            /// @brief 自发光
            EmissionType m_emission;
            /// @brief 光泽度
            float m_shininess;

        public:
            Material();
            Material(const AmbientType &ambient, const DiffuseType &diffuse, const SpecularType &specular, const EmissionType &emission, float shininess);
            Material(const SelfType &from);
            ~Material();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 获取环境光
            /// @return 环境光
            const AmbientType &get_ambient() const;
            /// @brief 获取漫射光
            /// @return 漫射光
            const DiffuseType &get_diffuse() const;
            /// @brief 获取镜面光
            /// @return 镜面光
            const SpecularType &get_specular() const;
            /// @brief 获取自发光
            /// @return 自发光
            const EmissionType &get_emission() const;
            /// @brief 获取光泽度
            /// @return 光泽度
            float get_shininess() const;

        public:
            /// @brief 设置环境光
            /// @param ambient 环境光
            virtual void set_ambient(const AmbientType &ambient);
            /// @brief 设置漫射光
            /// @param diffuse 漫射光
            virtual void set_diffuse(const DiffuseType &diffuse);
            /// @brief 设置镜面光
            /// @param specular 镜面光
            virtual void set_specular(const SpecularType &specular);
            /// @brief 设置自发光
            /// @param emission 自发光
            virtual void set_emission(const EmissionType &emission);
            /// @brief 设置光泽度
            /// @param shininess 光泽度
            virtual void set_shininess(float shininess);
        };
    } // namespace Graphics

} // namespace ntk

#endif
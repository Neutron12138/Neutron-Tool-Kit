#ifndef __NEUTRON_GRAPHICS_UNIFORMDESCRIBER_HPP__
#define __NEUTRON_GRAPHICS_UNIFORMDESCRIBER_HPP__

#include <array>
#include <string>
#include "../../Base/Object.hpp"
#include "UniformNameEnum.hpp"

namespace ntk
{
    namespace Graphics
    {
        class UniformDescriber : public Object
        {
        protected:
            std::array<std::string, UniformNameEnum::UniformName::Count> m_names;

        public:
            UniformDescriber();
            UniformDescriber(const UniformDescriber &from);
            ~UniformDescriber();

        public:
            UniformDescriber &operator=(const UniformDescriber &from);

        public:
            /// @brief 获取uniform在着色器中的名称
            /// @param name_enum uniform名称枚举
            /// @return uniform在着色器中的名称
            const std::string &get_name(UniformNameEnum::UniformName name_enum) const;

            /// @brief 设置uniform在着色器中的名称
            /// @param name_enum uniform名称枚举
            /// @param uniform_name uniform在着色器中的名称
            void set_name(UniformNameEnum::UniformName name_enum, const std::string &uniform_name);
        };
    } // namespace Graphics

} // namespace ntk

#endif
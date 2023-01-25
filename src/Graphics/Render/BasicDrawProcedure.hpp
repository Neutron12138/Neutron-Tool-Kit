#ifndef __NEUTRON_GRAPHICS_BASICDRAWPROCEDURE_HPP__
#define __NEUTRON_GRAPHICS_BASICDRAWPROCEDURE_HPP__

#include "../../Base/Object.hpp"
#include "DrawInfo.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 基础绘制过程
        template <typename m_DrawInfoType, typename m_ContainerType>
        class BasicDrawProcedure : public Object
        {
        public:
            using DrawInfoType = m_DrawInfoType;
            using ContainerType = m_ContainerType;
            using SelfType = BasicDrawProcedure<DrawInfoType, ContainerType>;

        protected:
            /// @brief 绘制过程
            ContainerType m_procedures;

        public:
            BasicDrawProcedure() = default;
            BasicDrawProcedure(const ContainerType &procedures);
            BasicDrawProcedure(const SelfType &from) = default;
            ~BasicDrawProcedure() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取所有绘制信息
            /// @return 所有绘制信息
            const ContainerType &get() const;

            /// @brief 设置所有绘制信息
            /// @param procedures 绘制信息
            virtual void set(const ContainerType &procedures);

            /// @brief 获取绘制信息
            /// @param index 索引
            /// @return 绘制信息
            const DrawInfoType &get(std::size_t index) const;

            /// @brief 设置绘制信息
            /// @param index 索引
            /// @param draw_info 绘制信息
            virtual void set(std::size_t index, const DrawInfoType &draw_info);

        public:
            /// @brief 绘制
            virtual void draw();
        };
    } // namespace Graphics

} // namespace ntk

#endif
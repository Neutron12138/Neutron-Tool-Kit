#ifndef __NEUTRON_GRAPHICS_DRAWPROCEDURE_HPP__
#define __NEUTRON_GRAPHICS_DRAWPROCEDURE_HPP__

#include <vector>
#include "../../Base/Object.hpp"
#include "BasicDrawProcedure.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 绘制过程
        template <>
        class BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>> : public Object
        {
        public:
            using DrawInfoType = DrawInfo;
            using ContainerType = std::vector<DrawInfoType>;
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

            /// @brief 在末尾添加一条绘制信息
            /// @param draw_info 绘制信息
            virtual void push(const DrawInfoType &draw_info);

            /// @brief 删除末尾的一条绘制信息
            virtual void pop();

        public:
            /// @brief 绘制
            virtual void draw();
        };

        using DrawProcedure = BasicDrawProcedure<DrawInfo, std::vector<DrawInfo>>;
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_INSTANCINGDATAARRAY_HPP__
#define __NEUTRON_GRAPHICS_INSTANCINGDATAARRAY_HPP__

#include <vector>
#include "../../Base/Object.hpp"
#include "InstancingData.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 实例数据数组
        /// @tparam m_InstancingDataType 实例数据类型
        /// @tparam m_ContainerType 容器类型
        template <typename m_InstancingDataType, typename m_ContainerType = std::vector<m_InstancingDataType>>
        class InstancingDataArray : public Object
        {
        public:
            using InstancingDataType = m_InstancingDataType;
            using ContainerType = m_ContainerType;
            using SelfType = InstancingDataArray<InstancingDataType, ContainerType>;

        protected:
            ContainerType m_data;

        public:
            InstancingDataArray() = default;
            InstancingDataArray(const ContainerType &data);
            InstancingDataArray(const SelfType &from) = default;
            ~InstancingDataArray() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;
            InstancingDataType &operator[](std::size_t index);

        public:
            /// @brief 获取所有实例数据
            /// @return 所有实例数据
            const ContainerType &get_data() const;

            /// @brief 获取实例数据
            /// @param index 索引
            /// @return 实例数据
            const InstancingDataType &get_data(std::size_t index) const;

            /// @brief 设置所有实例数据
            /// @param data 实例数据
            virtual void set_data(const ContainerType &data);

            /// @brief 设置实例数据
            /// @param index 索引
            /// @param data 实例数据
            virtual void set_data(std::size_t index, const InstancingDataType &data);

            /// @brief 获取数组大小
            /// @return 数组大小
            const std::size_t size() const;

        public:
            /// @brief 生成一个顶点缓冲对象
            /// @return 顶点缓冲对象
            virtual VertexBufferObject generate_VBO() = 0;

            /// @brief 生成一个顶点缓冲对象
            /// @param program 着色程序
            /// @param describer 顶点属性描述器
            /// @return 一个顶点缓冲对象
            virtual VertexBufferObject generate_VBO(const BasicProgram &program, const VertexAttribDescriber &describer) = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
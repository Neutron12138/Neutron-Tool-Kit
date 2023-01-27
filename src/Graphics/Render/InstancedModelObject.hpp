#ifndef __NEUTRON_GRAPHICS_INSTANCEDMODELOBJECT_HPP__
#define __NEUTRON_GRAPHICS_INSTANCEDMODELOBJECT_HPP__

#include "../Vertex/Sprite.hpp"
#include "BasicModelObject.hpp"
#include "InstancingDataArray.hpp"
#include "../Model/VertexModel.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 基础实例化渲染的模型对象
        /// @tparam m_InstancingDataArrayType 实例数据数组类型
        /// @tparam m_VertexModelType 顶点模型类型
        template <typename m_InstancingDataArrayType, typename m_VertexModelType = VertexModel>
        class InstancedModelObject : public Sprite, public BasicModelObject<m_VertexModelType>
        {
        public:
            using InstancingDataType = typename m_InstancingDataArrayType::InstancingDataType;
            using InstancingDataArrayType = m_InstancingDataArrayType;
            using VertexModelType = m_VertexModelType;
            using SelfType = InstancedModelObject<InstancingDataArrayType, VertexModelType>;
            using ParentType = BasicModelObject<VertexModelType>;

        protected:
            /// @brief 实例数据数组
            InstancingDataArrayType m_data;

            /// @brief 实例数据数组的顶点缓冲对象
            Utils::SharedPointer<VertexBufferObject> m_data_VBO;

        public:
            InstancedModelObject() = default;
            InstancedModelObject(const ParentType &model, const InstancingDataArrayType &data);
            InstancedModelObject(const VertexModelType &model, const InstancingDataArrayType &data);
            InstancedModelObject(const VertexModelType &model, const InstancingDataArrayType &data, const DrawInfo &draw_info);
            InstancedModelObject(const SelfType &from) = default;
            ~InstancedModelObject() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        protected:
            virtual void create();

        public:
            /// @brief 获取实例数据的顶点缓冲对象
            /// @return 实例数据的顶点缓冲对象
            const VertexBufferObject &get_data_VBO() const;

            /// @brief 获取实例数据数组
            /// @return 实例数据数组
            const InstancingDataArrayType &get_data() const;

            /// @brief 设置实例数据数组
            /// @param data 实例数据数组
            virtual void set_data(const InstancingDataArrayType &data);

        public:
            /// @brief 实例化的模型对象无法创建模型实例
            /// @return 空的模型实例
            virtual ModelInstance create_instance();

            virtual void update_VAO(GLenum usage = GL_STATIC_DRAW);
            virtual void update_VAO(const Program &program, const VertexAttribDescriber &describer, GLenum usage = GL_STATIC_DRAW);
            virtual void release();
            virtual void render();
            virtual void render(UniformBinder &binder, const UniformDescriber &describer);
        };
    } // namespace Graphics

} // namespace ntk

#endif
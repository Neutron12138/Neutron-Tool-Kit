#ifndef __NEUTRON_GRAPHICS_MODELOBJECT_HPP__
#define __NEUTRON_GRAPHICS_MODELOBJECT_HPP__

#include "../../Base/Object.hpp"
#include "../Model/VertexModel.hpp"
#include "ModelInstance.hpp"
#include "VertexArrayObject.hpp"
#include "../Buffer/VertexBufferObject.hpp"
#include "../../Utils/Resource/ResourceObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 模型对象，实例化的ModelInstance对象都共享资源
        /// @tparam m_VertexModelType 模型类型
        template <typename m_VertexModelType = VertexModel>
        class ModelObject : public m_VertexModelType, public Utils::ResourceObject
        {
        public:
            using VertexModelType = m_VertexModelType;
            using SelfType = ModelObject<VertexModelType>;
            using ParentType = VertexModelType;

        protected:
            /// @brief 正在管理的顶点数组对象
            VertexArrayObject m_VAO;
            /// @brief 正在管理的顶点缓冲对象
            VertexBufferObject m_VBO;

        public:
            ModelObject() = default;
            ModelObject(const VertexModelType &model);
            ModelObject(const SelfType &from) = default;
            ~ModelObject() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取顶点数组对象
            /// @return 顶点数组对象
            const VertexArrayObject &get_VAO() const;

            /// @brief 获取顶点缓冲对象
            /// @return 顶点缓冲对象
            const VertexBufferObject &get_VBO() const;

        public:
            /// @brief 创建一个新实例
            /// @return 模型实例
            virtual ModelInstance create_instance();

            /// @brief 更新顶点数组对象（和顶点缓冲对象）
            /// @param usage 缓冲区用法
            virtual void update_VAO(GLenum usage = GL_STATIC_DRAW);

            /// @brief 更新顶点数组对象（和顶点缓冲对象）
            /// @param program 着色程序
            /// @param describer 顶点属性描述器
            /// @param usage 缓冲区用法
            virtual void update_VAO(const Program &program, const VertexAttribDescriber &describer, GLenum usage = GL_STATIC_DRAW);

        public:
            virtual void release();
        };
    } // namespace Graphics

} // namespace ntk

#endif
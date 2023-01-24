#ifndef __NEUTRON_GRAPHICS_BASICMODELOBJECT_HPP__
#define __NEUTRON_GRAPHICS_BASICMODELOBJECT_HPP__

#include <memory>
#include "../../Base/Object.hpp"
#include "../Model/VertexModel.hpp"
#include "ModelInstance.hpp"
#include "../Vertex/VertexArrayObject.hpp"
#include "../Buffer/VertexBufferObject.hpp"
#include "../../Utils/Resource/ResourceObject.hpp"
#include "../../Utils/Resource/opengl/GLObjectDeleter.hpp"
#include "DrawInfo.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 模型对象，实例化的ModelInstance对象都共享资源
        /// @tparam m_VertexModelType 顶点模型类型
        template <typename m_VertexModelType>
        class BasicModelObject : public m_VertexModelType, public Utils::ResourceObject
        {
        public:
            using VertexModelType = m_VertexModelType;
            using SelfType = BasicModelObject<VertexModelType>;
            using ParentType = VertexModelType;

        protected:
            /// @brief 正在管理的顶点数组对象
            std::shared_ptr<VertexArrayObject> m_VAO;
            /// @brief 正在管理的顶点缓冲对象
            std::shared_ptr<VertexBufferObject> m_VBO;
            /// @brief 绘制信息
            std::shared_ptr<DrawInfo> m_draw_info;

        public:
            BasicModelObject() = default;
            BasicModelObject(const VertexModelType &model);
            BasicModelObject(const VertexModelType &model, const DrawInfo &draw_info);
            BasicModelObject(const SelfType &from) = default;
            ~BasicModelObject() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        protected:
            /// @brief 创建顶点数组对象和顶点缓冲对象
            virtual void create();

        public:
            /// @brief 获取顶点数组对象
            /// @return 顶点数组对象
            const VertexArrayObject &get_VAO() const;

            /// @brief 获取顶点缓冲对象
            /// @return 顶点缓冲对象
            const VertexBufferObject &get_VBO() const;

            /// @brief 获取绘制信息
            /// @return 绘制信息
            const DrawInfo &get_draw_info() const;

            /// @brief 设置绘制信息
            /// @param draw_info 绘制信息
            virtual void set_draw_info(const DrawInfo &draw_info);

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
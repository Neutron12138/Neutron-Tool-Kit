#ifndef __NEUTRON_GRAPHICS_MODELINSTANCE_HPP__
#define __NEUTRON_GRAPHICS_MODELINSTANCE_HPP__

#include <memory>
#include "Sprite.hpp"
#include "VertexArrayObject.hpp"
#include "DrawInfo.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 模型实例对象
        class ModelInstance : public Sprite
        {
        public:
            using SelfType = ModelInstance;
            using ParentType = Sprite;

        protected:
            /// @brief 顶点数组对象
            std::shared_ptr<VertexArrayObject> m_VAO;
            std::shared_ptr<DrawInfo> m_draw_info;

        public:
            ModelInstance() = default;
            ModelInstance(const std::shared_ptr<VertexArrayObject> &VAO);
            ModelInstance(const std::shared_ptr<VertexArrayObject> &VAO, const std::shared_ptr<DrawInfo> &draw_info);
            ModelInstance(const SelfType &from) = default;
            ~ModelInstance() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取顶点数组对象
            /// @return 顶点数组对象
            const VertexArrayObject &get_VAO() const;

            /// @brief 获取绘制信息
            /// @return 绘制信息
            const DrawInfo &get_draw_info() const;

        public:
            virtual void render();
            virtual void render(UniformBinder &binder, const UniformDescriber &describer);
        };
    } // namespace Graphics

} // namespace ntk

#endif
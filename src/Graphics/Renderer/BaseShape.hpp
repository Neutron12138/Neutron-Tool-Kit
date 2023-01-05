#ifndef __NEUTRON_GRAPHICS_BASESHAPE_HPP__
#define __NEUTRON_GRAPHICS_BASESHAPE_HPP__

#include <array>
#include "../Vertex/PrimitiveSprite2D.hpp"
#include "../Texture/Texture2D.hpp"
#include "../Buffer/VertexBufferObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 基础2D形状类
        class BaseShape : public PrimitiveSprite2D
        {
        public:
            /// @brief 顶点缓冲对象索引枚举
            enum VBOIndex
            {
                /// @brief 顶点
                Vertices = 0,
                /// @brief 纹理坐标
                TexCoords,
                /// @brief 颜色
                Colors,
                /// @brief 总计
                Count,
            };

        protected:
            /// @brief 图形位置
            glm::vec2 m_shape_position = glm::vec2(0.0f, 0.0f);
            /// @brief 纹理
            Texture2D m_texture;
            /// @brief 顶点缓冲对象
            std::array<VertexBufferObject, VBOIndex::Count> m_VBOs;

        public:
            BaseShape();
            BaseShape(const glm::vec2 &position);
            BaseShape(const BaseShape &from);
            ~BaseShape();

        public:
            BaseShape &operator=(const BaseShape &from);

        public:
            /// @brief 获取位置（与get_position()不同）
            /// @return 位置
            const glm::vec2 &get_shape_position() const;

            /// @brief 设置位置
            /// @param position 位置
            virtual void set_shape_position(const glm::vec2 &position);

            /// @brief 获取纹理
            /// @return 纹理
            const Texture2D &get_texture() const;

            /// @brief 设置纹理
            /// @param texture 纹理
            virtual void set_texture(const Texture2D &texture);

        public:
            virtual Sprite2D::PositionType get_position();
            virtual void release();

        public:
            /// @brief 生成形状
            virtual void generate_shape() = 0;

            /// @brief 更新VAO
            virtual void update_VAO() = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
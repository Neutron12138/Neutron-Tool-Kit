#ifndef __NEUTRON_GRAPHICS_BASESHAPE_HPP__
#define __NEUTRON_GRAPHICS_BASESHAPE_HPP__

#include <array>
#include <glm/glm.hpp>
#include "../../Utils/Resource/ResourceObject.hpp"
#include "../Vertex/Sprite2D.hpp"
#include "../Texture/Texture2D.hpp"
#include "../Buffer/VertexBufferObject.hpp"
#include "../Vertex/VertexArrayObject.hpp"
#include "../Vertex/VertexAttributeEnum.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 基础2D形状类
        class BaseShape : public Sprite2D, public Utils::ResourceObject
        {
        public:
            /// @brief 顶点数据
            struct VertexData : public Utils::ResourceObject
            {
                /// @brief 顶点数组对象
                VertexArrayObject vertex_array;
                /// @brief 顶点缓冲对象
                VertexBufferObject vertex_buffer;
                /// @brief 纹理坐标缓冲对象
                VertexBufferObject texCoord_buffer;
                /// @brief 颜色
                glm::vec4 color;

                VertexData();
                VertexData(const VertexData &from);
                ~VertexData();
                VertexData &operator=(const VertexData &from);

                virtual void release();
            };

        protected:
            /// @brief 图形位置
            glm::vec2 m_shape_position = glm::vec2(0.0f, 0.0f);
            /// @brief 纹理
            // Texture2D m_texture;
            /// @brief 顶点数据
            VertexData m_vertices;

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

            /*
            /// @brief 获取纹理
            /// @return 纹理
            const Texture2D &get_texture() const;

            /// @brief 设置纹理
            /// @param texture 纹理
            virtual void set_texture(const Texture2D &texture);
            */

            /// @brief 获取填充颜色
            /// @return 填充颜色
            const glm::vec4 &get_fill_color() const;

            /// @brief 设置填充颜色
            /// @param fill_color 填充颜色
            virtual void set_fill_color(const glm::vec4 &fill_color);

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
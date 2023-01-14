#ifndef __NEUTRON_GRAPHICS_BASESPATIAL_HPP__
#define __NEUTRON_GRAPHICS_BASESPATIAL_HPP__

#include <glm/glm.hpp>
#include "../../Utils/Resource/ResourceObject.hpp"
#include "../Vertex/Sprite.hpp"
#include "../Buffer/VertexBufferObject.hpp"
#include "../Vertex/VertexArrayObject.hpp"
#include "../Vertex/VertexAttributeEnum.hpp"
#include "../Material/Material.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 基础3D形状类
        /// @tparam m_MaterialType 材质类型
        template <typename m_MaterialType = Material<>>
        class BaseSpatial : public Sprite, public Utils::ResourceObject
        {
        public:
            using MaterialType = m_MaterialType;
            using SelfType = BaseSpatial<MaterialType>;

            /// @brief 顶点数据
            struct VertexData : public Utils::ResourceObject
            {
                /// @brief 顶点数组对象
                VertexArrayObject vertex_array;
                /// @brief 顶点缓冲对象
                VertexBufferObject vertex_buffer;
                /// @brief 法线缓冲对象
                VertexBufferObject normal_buffer;
                /// @brief 纹理坐标缓冲对象
                VertexBufferObject texCoord_buffer;
                /// @brief 材质
                MaterialType material;

                VertexData();
                VertexData(const VertexData &from);
                ~VertexData();
                VertexData &operator=(const VertexData &from);

                virtual void release();
            };

        protected:
            /// @brief 图形位置
            glm::vec3 m_spatial_position = glm::vec3(0.0f, 0.0f, 0.0f);
            /// @brief 顶点数据
            VertexData m_vertices;

        public:
            BaseSpatial();
            BaseSpatial(const glm::vec3 &position);
            BaseSpatial(const SelfType &from);
            ~BaseSpatial();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 获取位置
            /// @return 位置
            const glm::vec3 &get_spatial_position() const;

            /// @brief 设置位置
            /// @param position 位置
            virtual void set_spatial_position(const glm::vec3 &position);

            /// @brief 获取材质
            /// @return 材质
            const MaterialType &get_material() const;

            /// @brief 设置材质
            /// @param material 材质
            virtual void set_material(const MaterialType &material);

        public:
            virtual Sprite::PositionType get_position();
            virtual void release();
            virtual void render(UniformBinder &binder, const UniformDescriber &describer);

        public:
            /// @brief 生成形状
            virtual void generate_shape() = 0;

            /// @brief 更新VAO
            virtual void update_VAO() = 0;
        };
    } // namespace Graphics

} // namespace ntk

#endif
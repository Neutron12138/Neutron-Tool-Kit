#ifndef __NEUTRON_GRAPHICS_GLOBJECT_HPP__
#define __NEUTRON_GRAPHICS_GLOBJECT_HPP__

#include "GL.hpp"
#include "../Utils/Resource/ResourceObject.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief GL对象的基类
        class GLObject : public Utils::ResourceObject
        {
        protected:
            GLuint m_objectID = 0;

        public:
            GLObject();
            GLObject(GLuint objectID);
            GLObject(const GLObject &from);
            // 因为有时并不需要在本对象销毁时同时销毁OpenGL对象（比如函数返回值），所以请手动管理
            ~GLObject();

        public:
            GLObject &operator=(const GLObject &from);

        public:
            /// @brief 设置对象的ID。如果本对象储存的OpenGL对象ID不是0，请自行决定是销毁还是保留，假定你会管理好的:)
            /// @param objectID 对象ID
            /// @return 本对象
            GLObject &set_objectID(GLuint objectID);

            /// @brief 获取储存的OpenGL对象的ID
            /// @return 储存的OpenGL对象的ID
            GLuint get_objectID() const;

        public:
            /// @brief 储存的OpenGL对象是否为空（即保留值0）
            /// @return 储存的OpenGL对象是否为空
            virtual bool is_null() const;

            /// @brief 生成一个对象
            virtual void generate() = 0;

            /// @brief 为了防止误把着色器对象用纹理对象管理的这种情况，需要判断对象ID是否正确。
            /// @param objectID 要判断的OpenGL对象ID
            /// @return 类型是否正确
            virtual bool is_correct_objectID(GLuint objectID) = 0;

            /// @brief 删除储存的OpenGL对象
            virtual void release() = 0;
        };

        /// @brief 删除所有OpenGL对象
        /// @tparam ContainerType 容器类型
        /// @param container 容器
        template <typename ContainerType>
        void delete_all_globjects(ContainerType container);
    } // namespace Graphics

} // namespace ntk

#endif
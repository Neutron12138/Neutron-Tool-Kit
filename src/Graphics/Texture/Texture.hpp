#ifndef __NEUTRON_GRAPHICS_TEXTURE_HPP__
#define __NEUTRON_GRAPHICS_TEXTURE_HPP__

#include "../GL.hpp"
#include "../Bindable.hpp"
#include "TextureType.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 基础纹理类
        class Texture : public Bindable
        {
        private:
            TextureType::TextureType m_texture_type;

        public:
            Texture(TextureType::TextureType texture_type);
            Texture(TextureType::TextureType texture_type, GLuint textureID);
            Texture(const Texture &from);
            ~Texture();

        public:
            Texture &operator=(const Texture &from);

        public:
            /// @brief 获取纹理类型
            /// @return 纹理类型
            TextureType::TextureType get_texture_type() const;

            /// @brief 有对象检查版本的set_objectID()，建议使用这个而不是set_objectID()
            /// @param textureID 要被赋予的缓冲区对象
            virtual void set_textureID(GLuint textureID);

        public:
            virtual void bind();
            virtual void unbind();
            virtual void generate();
            virtual bool is_correct_objectID(GLuint objectID);
            virtual void delete_object();
        };
    } // namespace Graphics

} // namespace ntk

#endif
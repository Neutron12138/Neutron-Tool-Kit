#ifndef __NEUTRON_GRAPHICS_TEXTURE_CPP__
#define __NEUTRON_GRAPHICS_TEXTURE_CPP__

#include "Texture.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        Texture::Texture(TextureType::TextureType texture_type) : Bindable(), m_texture_type(texture_type) {}
        Texture::Texture(TextureType::TextureType texture_type, GLuint textureID) : Bindable(textureID), m_texture_type(texture_type) {}
        Texture::Texture(const Texture &from) { *this = from; }
        Texture::~Texture() {}

        Texture &Texture::operator=(const Texture &from)
        {
            Bindable::operator=(from);
            m_texture_type = from.m_texture_type;
            return *this;
        }

        TextureType::TextureType Texture::get_texture_type() const
        {
            return m_texture_type;
        }

        void Texture::set_textureID(GLuint textureID)
        {
            if (textureID != 0 && is_correct_objectID(textureID))
            {
                m_objectID = textureID;
            }
            else if (!is_correct_objectID(textureID))
            {
                Instance::log.loge("Texture", "The type of OpenGL object to be assigned is not a texture object.");
            }
            else
            {
                Instance::log.logw("Texture", "You will assign a reserved value to the texture object.");
                m_objectID = textureID;
            }
        }

        void Texture::bind()
        {
            glBindTexture(static_cast<GLenum>(m_texture_type), m_objectID);
        }

        void Texture::unbind()
        {
            glBindTexture(static_cast<GLenum>(m_texture_type), 0);
        }

        void Texture::generate()
        {
            glGenTextures(1, &m_objectID);
        }

        bool Texture::is_correct_objectID(GLuint objectID)
        {
            return glIsTexture(objectID);
        }

        void Texture::delete_object()
        {
            if (m_objectID != 0)
            {
                glDeleteTextures(1, &m_objectID);
                m_objectID = 0;
            }
        }
    } // namespace Graphics

} // namespace ntk

#endif
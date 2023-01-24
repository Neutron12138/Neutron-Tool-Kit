#ifndef __NEUTRON_GRAPHICS_TEXTURE2D_CPP__
#define __NEUTRON_GRAPHICS_TEXTURE2D_CPP__

#include "Texture2D.hpp"
#include "../../Utils/Image/Image.hpp"

namespace ntk
{
    namespace Graphics
    {
        Texture2D::Texture2D() : Texture(TextureType::TextureType::Texture_2D) {}
        Texture2D::Texture2D(const Texture2D &from) : Texture(TextureType::TextureType::Texture_2D) { *this = from; }
        Texture2D::~Texture2D() {}

        Texture2D &Texture2D::operator=(const Texture2D &from)
        {
            Texture::operator=(from);
            m_width = from.m_width;
            m_height = from.m_height;
            m_format = from.m_format;
            return *this;
        }

        GLsizei Texture2D::get_width() const
        {
            return m_width;
        }

        GLsizei Texture2D::get_height() const
        {
            return m_height;
        }

        bool Texture2D::load_from_file(const std::string &filename)
        {
            Utils::Image image;
            bool success = image.load_from_file(filename);
            if (!success)
                return false;

            m_width = image.get_width();
            m_height = image.get_height();
            m_format = image.get_color_channel() == Utils::ColorChannel::ColorChannel::RGB ? GL_RGB : GL_RGBA;

            generate();
            bind();
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexImage2D(GL_TEXTURE_2D, 0, m_format, m_width, m_height, 0, m_format, GL_UNSIGNED_BYTE, image.get_pixels());
            glGenerateMipmap(GL_TEXTURE_2D);
            unbind();

            image.release();

            return true;
        }
    } // namespace Graphics

} // namespace ntk

#endif
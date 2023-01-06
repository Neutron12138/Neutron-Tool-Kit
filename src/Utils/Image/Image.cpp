#ifndef __NEUTRON_UTILS_IMAGE_CPP__
#define __NEUTRON_UTILS_IMAGE_CPP__

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>
#include "Image.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Utils
    {
        Image::Image() {}
        Image::Image(const Image &from) { *this = from; }
        Image::~Image() {}

        Image &Image::operator=(const Image &from)
        {
            m_pixels = from.m_pixels;
            m_width = from.m_width;
            m_height = from.m_height;
            m_color_channel = from.m_color_channel;
            return *this;
        }

        const std::uint8_t *Image::get_pixels() const
        {
            return m_pixels;
        }

        std::uint32_t Image::get_width() const
        {
            return m_width;
        }

        std::uint32_t Image::get_height() const
        {
            return m_height;
        }

        ColorChannel::ColorChannel Image::get_color_channel() const
        {
            return m_color_channel;
        }

        bool Image::load_from_file(const std::string &filename, int desired_channels)
        {
            int width, height, comp;
            m_pixels = stbi_load(filename.data(), &width, &height, &comp, desired_channels);
            bool success = m_pixels != nullptr;
            if (success)
            {
                m_width = width;
                m_height = height;
                m_color_channel = static_cast<ColorChannel::ColorChannel>(comp - 1);
            }
            else
            {
                Instance::log.loge("Image", Instance::string_utils.to_string("Unable to load image from file:\"", filename, "\""));
            }
            return success;
        }

        bool Image::own_from_memory(std::uint32_t width, std::uint32_t height, ColorChannel::ColorChannel color_channel, std::uint8_t *source)
        {
            if (source == nullptr && width != 0 && height != 0)
                return false;

            m_width = width;
            m_height = height;
            m_color_channel = color_channel;
            m_pixels = source;
            return true;
        }

        bool Image::copy_from_memory(std::uint32_t width, std::uint32_t height, ColorChannel::ColorChannel color_channel, const std::uint8_t *source)
        {
            if (source == nullptr && width != 0 && height != 0)
                return false;

            m_width = width;
            m_height = height;
            m_color_channel = color_channel;
            std::size_t size = width * height * static_cast<int>(color_channel) + 1;
            m_pixels = new std::uint8_t[size];
            memcpy_s(m_pixels, size, source, size);
            return true;
        }

        bool Image::own_from_another(Image &another)
        {
            if (another.m_pixels == nullptr && another.m_width != 0 && another.m_height != 0)
                return false;

            *this = another;
            return true;
        }

        bool Image::copy_from_another(const Image &another)
        {
            if (another.m_pixels == nullptr && another.m_width != 0 && another.m_height != 0)
                return false;

            *this = another;
            std::size_t size = another.m_width * another.m_height * static_cast<int>(another.m_color_channel) + 1;
            m_pixels = new std::uint8_t[size];
            memcpy_s(m_pixels, size, another.m_pixels, size);
            return true;
        }

        void Image::write_as_png(const std::string &filename, bool flip)
        {
            stbi_flip_vertically_on_write(flip);
            stbi_write_png(filename.data(), m_width, m_height, static_cast<int>(m_color_channel) + 1, m_pixels, 0);
        }

        void Image::release()
        {
            if (m_pixels != nullptr)
                delete[] m_pixels;
        }
    } // namespace Utils

} // namespace ntk

#endif
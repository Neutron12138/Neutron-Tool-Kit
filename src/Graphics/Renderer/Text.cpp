#ifndef __NEUTRON_GRAPHICS_TEXT_CPP__
#define __NEUTRON_GRAPHICS_TEXT_CPP__

#include "Text.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        template <typename m_StringType, typename m_FontType>
        Text<m_StringType, m_FontType>::Text() : RectangleShape() {}
        template <typename m_StringType, typename m_FontType>
        Text<m_StringType, m_FontType>::Text(const m_StringType &text, std::uint32_t size, FontType *font) : RectangleShape(), m_text(text), m_text_size(size), m_font(font) {}
        template <typename m_StringType, typename m_FontType>
        Text<m_StringType, m_FontType>::Text(const Text<m_StringType, m_FontType> &from) { *this = from; }
        template <typename m_StringType, typename m_FontType>
        Text<m_StringType, m_FontType>::~Text() {}

        template <typename m_StringType, typename m_FontType>
        Text<m_StringType, m_FontType> &Text<m_StringType, m_FontType>::operator=(const Text<m_StringType, m_FontType> &from)
        {
            RectangleShape::operator=(from);
            m_text = from.m_text;
            m_text_size = from.m_text_size;
            m_font = from.m_font;
            m_multi_line = from.m_multi_line;
            m_line_space = from.m_line_space;
            return *this;
        }

        template <typename m_StringType, typename m_FontType>
        const m_StringType &Text<m_StringType, m_FontType>::get_text() const
        {
            return m_text;
        }

        template <typename m_StringType, typename m_FontType>
        std::uint32_t Text<m_StringType, m_FontType>::get_text_size() const
        {
            return m_text_size;
        }

        template <typename m_StringType, typename m_FontType>
        m_FontType *Text<m_StringType, m_FontType>::get_font() const
        {
            return m_font;
        }

        template <typename m_StringType, typename m_FontType>
        bool Text<m_StringType, m_FontType>::enabled_multi_line() const
        {
            return m_multi_line;
        }

        template <typename m_StringType, typename m_FontType>
        std::uint32_t Text<m_StringType, m_FontType>::get_line_space() const
        {
            return m_line_space;
        }

        template <typename m_StringType, typename m_FontType>
        void Text<m_StringType, m_FontType>::set_text(const StringType &text)
        {
            m_text = text;
        }

        template <typename m_StringType, typename m_FontType>
        void Text<m_StringType, m_FontType>::set_text_size(std::uint32_t size)
        {
            m_text_size = size;
        }

        template <typename m_StringType, typename m_FontType>
        void Text<m_StringType, m_FontType>::set_font(m_FontType *font)
        {
            m_font = font;
        }

        template <typename m_StringType, typename m_FontType>
        void Text<m_StringType, m_FontType>::set_multi_line(bool enabled)
        {
            m_multi_line = enabled;
        }

        template <typename m_StringType, typename m_FontType>
        void Text<m_StringType, m_FontType>::set_line_space(std::uint32_t line_space)
        {
            m_line_space = line_space;
        }

        template <typename m_StringType, typename m_FontType>
        void Text<m_StringType, m_FontType>::render()
        {
        }

        template <typename m_StringType, typename m_FontType>
        void Text<m_StringType, m_FontType>::render(const glm::vec2 &scale)
        {
            // 判断是否每个字形都可用
            for (std::size_t i = 0; i < m_text.length(); i++)
            {
                std::uint32_t ch = static_cast<std::uint32_t>(m_text.at(i));
                typename m_FontType::GlyphCollectionType *gc = m_font->get_glyph(ch);
                if (gc == nullptr)
                {
                    if (!m_font->load_glyph(ch, m_text_size))
                    {
                        Instance::log.loge("Text", Instance::string_utils.to_string("Unable to load glyph:", ch, ",size:", m_text_size));
                        return;
                    }
                }
                else
                {
                    typename m_FontType::GlyphType *g = gc->get_glyph(m_text_size);
                    if (g == nullptr)
                    {
                        if (!m_font->load_glyph(ch, m_text_size))
                        {
                            Instance::log.loge("Text", Instance::string_utils.to_string("Unable to load glyph:", ch, ",size:", m_text_size));
                            return;
                        }
                    }
                }
            }

            // 绘制
            GLfloat x = m_shape_position.x;
            GLfloat y = m_shape_position.y;
            for (std::size_t i = 0; i < m_text.length(); i++)
            {
                std::uint32_t ch = static_cast<std::uint32_t>(m_text.at(i));
                if (ch == '\n')
                {
                    if (m_multi_line)
                    {
                        x = m_shape_position.x;
                        y -= static_cast<GLfloat>(m_line_space) * scale.y;
                        continue;
                    }
                }

                typename m_FontType::GlyphType *glyph = m_font->get_glyph(ch)->get_glyph(m_text_size);
                GLfloat xpos = x + static_cast<GLfloat>(glyph->get_bearing().x) * scale.x;
                GLfloat ypos = y - (static_cast<GLfloat>(glyph->get_size().y) - static_cast<GLfloat>(glyph->get_bearing().y)) * scale.y;

                GLfloat w = static_cast<GLfloat>(glyph->get_size().x) * scale.x;
                GLfloat h = static_cast<GLfloat>(glyph->get_size().y) * scale.y;

                std::vector<glm::vec3> vertices =
                    {
                        glm::vec3(xpos + 0, ypos - 0, 0.0f),
                        glm::vec3(xpos + 0, ypos - h, 0.0f),
                        glm::vec3(xpos + w, ypos - h, 0.0f),
                        glm::vec3(xpos + w, ypos - 0, 0.0f),
                    };

                glyph->bind_texture();
                m_vertices.vertex_array.bind();
                m_vertices.vertex_buffer.bind();
                m_vertices.vertex_buffer.sub_data(vertices);
                glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
                m_vertices.vertex_array.unbind();
                glBindBuffer(GL_ARRAY_BUFFER, 0);

                x += static_cast<GLfloat>(glyph->get_advance().x) * scale.x / 64.0f;
            }
        }

        template <typename m_StringType, typename m_FontType>
        void Text<m_StringType, m_FontType>::render(const glm::vec2 &scale, UniformBinder &binder, const UniformDescriber &describer)
        {
            binder.set_uniform(describer.get_name(UniformNameEnum::UniformName::Color), m_outline.color);
            render(scale);
        }

        template <typename StringType, typename FontType>
        int measure_text_width(const StringType &text, std::uint32_t size, FontType *font)
        {
            // 判断是否每个字形都可用
            for (std::size_t i = 0; i < text.length(); i++)
            {
                std::uint32_t ch = static_cast<std::uint32_t>(text.at(i));
                typename FontType::GlyphCollection *gc = font->get_glyph(ch);
                if (gc == nullptr)
                {
                    if (!font->load_glyph(ch, size))
                    {
                        Instance::log.loge("measure text width", Instance::string_utils.to_string("Unable to load glyph:", ch, ",size:", size));
                        return -1;
                    }
                }
                else
                {
                    typename FontType::GlyphType *g = gc->get_glyph(size);
                    if (g == nullptr)
                    {
                        if (!font->load_glyph(ch, size))
                        {
                            Instance::log.loge("measure text width", Instance::string_utils.to_string("Unable to load glyph:", ch, ",size:", size));
                            return -1;
                        }
                    }
                }
            }

            // 统计宽度
            // 要包含字形宽度和到下一字形的距离
            int count = 0;
            for (std::size_t i = 0; i < text.length(); i++)
            {
                std::uint32_t ch = static_cast<std::uint32_t>(text.at(i));
                typename FontType::GlyphType *g = font->get_glyph(ch)->get_glyph(size);
                count += g->get_size().x * 64;
                count += g->get_advance().x;
            }

            return count;
        }
    } // namespace Graphics

} // namespace ntk

#endif
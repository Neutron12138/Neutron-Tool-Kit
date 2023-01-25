#ifndef __NEUTRON_GRAPHICS_TRUETYPEFONT_HPP__
#define __NEUTRON_GRAPHICS_TRUETYPEFONT_HPP__

#include <ft2build.h>
#include FT_FREETYPE_H
#include "Font.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief TrueType字体类
        /// @tparam m_GlyphType 字形类型
        template <typename m_GlyphType = Glyph, typename m_GlyphCollectionType = GlyphCollection<Glyph>>
        class TrueTypeFont : public Font<m_GlyphType, m_GlyphCollectionType>
        {
        public:
            using GlyphType = m_GlyphType;
            using GlyphCollectionType = m_GlyphCollectionType;
            using SelfType = TrueTypeFont<GlyphType, GlyphCollectionType>;

        protected:
            FT_Library m_library = nullptr;
            FT_Face m_face = nullptr;

        public:
            TrueTypeFont();
            TrueTypeFont(const SelfType &from);
            ~TrueTypeFont();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            virtual bool load_font(const std::string &filename);
            virtual void close_font();
            virtual bool load_glyph(std::uint32_t code, std::uint32_t size, GlyphType &result);
            virtual bool load_glyph(std::uint32_t code, std::uint32_t size);
        };
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_GRAPHICS_TRUETYPEFONT_HPP__
#define __NEUTRON_GRAPHICS_TRUETYPEFONT_HPP__

#include <ft2build.h>
#include FT_FREETYPE_H
#include "Font.hpp"

namespace ntk
{
    namespace Graphics
    {
        class TrueTypeFont : public Font
        {
        protected:
            FT_Library m_library = nullptr;
            FT_Face m_face = nullptr;

        public:
            TrueTypeFont();
            TrueTypeFont(const TrueTypeFont &from);
            ~TrueTypeFont();

        public:
            TrueTypeFont &operator=(const TrueTypeFont &from);

        public:
            virtual bool load_font(const std::string &filename);
            virtual void close_font();
            virtual bool load_glyph(std::uint32_t code, std::uint32_t size, Glyph &result);
            virtual bool load_glyph(std::uint32_t code, std::uint32_t size);
        };
    } // namespace Graphics

} // namespace ntk

#endif
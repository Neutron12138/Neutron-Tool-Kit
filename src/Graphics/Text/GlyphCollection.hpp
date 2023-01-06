#ifndef __NEUTRON_GRAPHICS_GLYPHCOLLECTION_HPP__
#define __NEUTRON_GRAPHICS_GLYPHCOLLECTION_HPP__

#include <map>
#include "Glyph.hpp"
#include "../../Base/Object.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 字形集
        /// @tparam m_GlyphType 字形类型，继承自Glyph
        template <typename m_GlyphType = Glyph>
        class GlyphCollection : public Object
        {
        public:
            using GlyphType = m_GlyphType;
            using SelfType = GlyphCollection<GlyphType>;

        protected:
            /// @brief 字形，键为字形大小（单位：像素）
            std::map<std::uint32_t, Glyph> m_glyphs;
            /// @brief 该字的编码
            std::uint32_t m_code;

        public:
            GlyphCollection(std::uint32_t code);
            GlyphCollection(const SelfType &from);
            ~GlyphCollection();

        public:
            SelfType &operator=(const SelfType &from);

        public:
            /// @brief 获取所有字形
            /// @return 字形
            const std::map<std::uint32_t, GlyphType> &get_glyphs() const;

            /// @brief 获取该字的编码
            /// @return 该字的编码
            std::uint32_t get_code() const;

            /// @brief 获取字形
            /// @param size 大小
            /// @return 字形
            GlyphType *get_glyph(std::uint32_t size);

        public:
            /// @brief 加载该字形
            /// @param size 该字形的大小
            /// @return 是否加载成功
            virtual bool load(FT_Face face, std::uint32_t size);

            /// @brief 释放所有
            virtual void release_all();
        };
    } // namespace Graphics

} // namespace ntk

#endif
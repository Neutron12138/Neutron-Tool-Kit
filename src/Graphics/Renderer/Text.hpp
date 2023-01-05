#ifndef __NEUTRON_GRAPHICS_TEXT_HPP__
#define __NEUTRON_GRAPHICS_TEXT_HPP__

#include "../../Base/Type.hpp"
#include "BaseShape.hpp"
#include "../Text/Font.hpp"

namespace ntk
{
    namespace Graphics
    {
        /// @brief 文本对象
        /// @tparam m_StringType 字符串类型
        template <typename m_StringType = String>
        class Text : public BaseShape
        {
        public:
            using StringType = m_StringType;
            using SelfType = Text<StringType>;

        private:
            /// @brief 字符串
            StringType m_text;
            /// @brief 文本大小
            std::uint32_t m_size = 32;
            /// @brief 字体
            Font *m_font = nullptr;

        public:
            Text();
            Text(const StringType &text, std::uint32_t size, Font *font);
            Text(const SelfType &from);
            ~Text();

        public:
            Text &operator=(const SelfType &from);

        public:
            const StringType &get_text() const;
            std::uint32_t get_size() const;
            Font *get_font() const;

            virtual void set_text(const StringType &text);
            virtual void set_size(std::uint32_t size);
            virtual void set_font(Font *font);
        };
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_WINDOW_IMPL_SFML_HPP__
#define __NEUTRON_WINDOW_IMPL_SFML_HPP__

#include <memory>
#include <SFML/Graphics.hpp>
#include "Application.hpp"

namespace ntk
{
    namespace Window
    {
        static const sf::ContextSettings DEFAULT_CONTEXT_SETTINGS = sf::ContextSettings(16, 8, 4, 3, 3, sf::ContextSettings::Attribute::Core | sf::ContextSettings::Attribute::Debug, false);

        class SFApplication : public Application
        {
        protected:
            /// @brief 窗口实例
            std::shared_ptr<sf::RenderWindow> m_window;

        protected:
            virtual void create(sf::VideoMode mode, std::string title, sf::Uint32 style, const sf::ContextSettings &settings);

        public:
            SFApplication();
            SFApplication(std::string title, glm::ivec2 size);
            SFApplication(std::string title, glm::ivec2 size, sf::Uint32 style);
            SFApplication(std::string title, glm::ivec2 size, glm::uvec2 version);
            SFApplication(std::string title, glm::ivec2 size, glm::uvec3 framebuffer_config);
            SFApplication(std::string title, glm::ivec2 size, sf::Uint32 style, glm::uvec2 version);
            SFApplication(std::string title, glm::ivec2 size, sf::Uint32 style, glm::uvec2 version, glm::uvec3 framebuffer_config);
            SFApplication(sf::VideoMode mode, std::string title, sf::Uint32 style, const sf::ContextSettings &settings);
            SFApplication(const SFApplication &from);
            ~SFApplication();

        public:
            /// @brief 赋值函数。注意：这是浅拷贝！
            /// @param from 要被赋予的值
            /// @return 本对象
            SFApplication &operator=(const SFApplication &from);

        public:
            virtual int run();
            virtual glm::ivec2 get_mouse_position();

        public:
            /// @brief 处理其他事件
            /// @param event 事件
            /// @return 如果返回true，则说明事件被处理，不会再次处理此事件（调用回调函数）
            virtual bool onEvent(const sf::Event& event);

            /// @brief 遇到sf::Event::EventType::Closed时调用
            virtual void onClose();

        public:
            /// @brief 获取窗口
            /// @return 窗口
            sf::RenderWindow &get_window();
        };
    } // namespace Window

} // namespace ntk

#endif
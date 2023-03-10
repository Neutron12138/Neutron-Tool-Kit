#ifndef __NEUTRON_WINDOW_IMPL_SFML_CPP__
#define __NEUTRON_WINDOW_IMPL_SFML_CPP__

#include "SFML_Impl.hpp"
#include "../Instances.hpp"
#include "../Utils/Exception/NullPointerException.hpp"

namespace ntk
{
    namespace Window
    {
        void SFApplication::create(sf::VideoMode mode, std::string title, sf::Uint32 style, const sf::ContextSettings &settings)
        {
            m_window = Utils::SharedPointer<sf::RenderWindow>(new sf::RenderWindow(mode, title, style, settings));
        }

        SFApplication::SFApplication() : Application() {}

        SFApplication::SFApplication(std::string title, glm::ivec2 size) : Application()
        {
            create(sf::VideoMode(size.x, size.y), title, sf::Style::Default, DEFAULT_SF_CONTEXT_SETTINGS);
        }

        SFApplication::SFApplication(std::string title, glm::ivec2 size, sf::Uint32 style) : Application()
        {
            create(sf::VideoMode(size.x, size.y), title, style, DEFAULT_SF_CONTEXT_SETTINGS);
        }

        SFApplication::SFApplication(std::string title, glm::ivec2 size, glm::uvec2 version) : Application()
        {
            sf::ContextSettings settings = DEFAULT_SF_CONTEXT_SETTINGS;
            settings.majorVersion = version.x;
            settings.minorVersion = version.y;
            create(sf::VideoMode(size.x, size.y), title, sf::Style::Default, settings);
        }

        SFApplication::SFApplication(std::string title, glm::ivec2 size, glm::uvec3 framebuffer_config) : Application()
        {
            sf::ContextSettings settings = DEFAULT_SF_CONTEXT_SETTINGS;
            settings.depthBits = framebuffer_config.x;
            settings.stencilBits = framebuffer_config.y;
            settings.antialiasingLevel = framebuffer_config.z;
            create(sf::VideoMode(size.x, size.y), title, sf::Style::Default, settings);
        }

        SFApplication::SFApplication(std::string title, glm::ivec2 size, sf::Uint32 style, glm::uvec2 version) : Application()
        {
            sf::ContextSettings settings = DEFAULT_SF_CONTEXT_SETTINGS;
            settings.majorVersion = version.x;
            settings.minorVersion = version.y;
            create(sf::VideoMode(size.x, size.y), title, style, settings);
        }

        SFApplication::SFApplication(std::string title, glm::ivec2 size, sf::Uint32 style, glm::uvec2 version, glm::uvec3 framebuffer_config) : Application()
        {
            sf::ContextSettings settings = DEFAULT_SF_CONTEXT_SETTINGS;
            settings.majorVersion = version.x;
            settings.minorVersion = version.y;
            settings.depthBits = framebuffer_config.x;
            settings.stencilBits = framebuffer_config.y;
            settings.antialiasingLevel = framebuffer_config.z;
            create(sf::VideoMode(size.x, size.y), title, style, settings);
        }

        SFApplication::SFApplication(sf::VideoMode mode, std::string title, sf::Uint32 style, const sf::ContextSettings &settings) : Application()
        {
            create(mode, title, style, settings);
        }

        SFApplication::SFApplication(const SFApplication &from) : Application()
        {
            *this = from;
        }

        SFApplication::~SFApplication()
        {
        }

        SFApplication &SFApplication::operator=(const SFApplication &from)
        {
            Application::operator=(from);
            m_window = from.m_window;
            return *this;
        }

        int SFApplication::run()
        {
            // ??????
            m_is_running = true;
            m_timer.start();

            // ?????????
            onCreated();

            // ???????????????
            m_last_draw_time = Utils::get_current_time();
            onDisplay();
            onUpdate();

            // ?????????
            sf::Event event;
            while (m_is_running && m_window->isOpen())
            {
                // ????????????
                while (m_window->pollEvent(event))
                {
                    // ????????????????????????
                    // ????????????????????????????????????
                    if (onEvent(event))
                        continue;

                    // ????????????????????????????????????
                    switch (event.type)
                    {
                        // ?????????????????????
                    case sf::Event::EventType::Closed:
                        onClose();
                        break;

                        // ?????????????????????????????????
                    case sf::Event::EventType::Resized:
                    {
                        const sf::Vector2u size = m_window->getSize();
                        onResized(glm::uvec2(size.x, size.y));
                    }
                    break;

                    case sf::Event::EventType::KeyPressed:
                        onKeyPressed(static_cast<std::uint32_t>(event.key.code));
                        break;

                    case sf::Event::EventType::KeyReleased:
                        onKeyReleased(static_cast<std::uint32_t>(event.key.code));
                        break;

                    case sf::Event::EventType::TextEntered:
                        onTextEntered(static_cast<std::uint32_t>(event.text.unicode));

                    default:
                        break;
                    }
                }

                // ??????????????????
                if (m_is_running)
                {
                    // ??????????????????
                    const Utils::Time current_time = Utils::get_current_time();
                    // ???????????????
                    m_delta_time = current_time - m_last_draw_time;

                    // ????????????
                    onProcess(m_delta_time);
                    onDisplay();
                    m_window->display();
                    onUpdate();

                    // ????????????
                    m_last_draw_time = Utils::get_current_time();
                }
            }

            // ???????????????
            m_timer.stop();
            // ????????????????????????
            Instance::log.logi("Application", Utils::to_string("Application Finished\nexit code:", m_exit_code, "\n", m_timer.get_total_time().as_seconds(), " seconds exist"));

            // ????????????
            onDestroyed();

            // ??????
            return m_exit_code;
        }

        glm::ivec2 SFApplication::get_mouse_position()
        {
            sf::Vector2i pos = sf::Mouse::getPosition();
            return glm::ivec2(pos.x, pos.y);
        }

        bool SFApplication::onEvent(const sf::Event &event)
        {
            return false;
        }

        void SFApplication::onClose()
        {
            m_window->close();
        }

        sf::RenderWindow &SFApplication::get_window()
        {
            if (m_window.get() == nullptr)
                throw Utils::NullPointerException("sf::RenderWindow &SFApplication::get_window()");
            return *m_window.get();
        }
    } // namespace Window

} // namespace ntk

#endif
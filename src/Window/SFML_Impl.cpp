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
            create(sf::VideoMode(size.x, size.y), title, sf::Style::Default, DEFAULT_CONTEXT_SETTINGS);
        }

        SFApplication::SFApplication(std::string title, glm::ivec2 size, sf::Uint32 style) : Application()
        {
            create(sf::VideoMode(size.x, size.y), title, style, DEFAULT_CONTEXT_SETTINGS);
        }

        SFApplication::SFApplication(std::string title, glm::ivec2 size, glm::uvec2 version) : Application()
        {
            sf::ContextSettings settings = DEFAULT_CONTEXT_SETTINGS;
            settings.majorVersion = version.x;
            settings.minorVersion = version.y;
            create(sf::VideoMode(size.x, size.y), title, sf::Style::Default, settings);
        }

        SFApplication::SFApplication(std::string title, glm::ivec2 size, glm::uvec3 framebuffer_config) : Application()
        {
            sf::ContextSettings settings = DEFAULT_CONTEXT_SETTINGS;
            settings.depthBits = framebuffer_config.x;
            settings.stencilBits = framebuffer_config.y;
            settings.antialiasingLevel = framebuffer_config.z;
            create(sf::VideoMode(size.x, size.y), title, sf::Style::Default, settings);
        }

        SFApplication::SFApplication(std::string title, glm::ivec2 size, sf::Uint32 style, glm::uvec2 version) : Application()
        {
            sf::ContextSettings settings = DEFAULT_CONTEXT_SETTINGS;
            settings.majorVersion = version.x;
            settings.minorVersion = version.y;
            create(sf::VideoMode(size.x, size.y), title, style, settings);
        }

        SFApplication::SFApplication(std::string title, glm::ivec2 size, sf::Uint32 style, glm::uvec2 version, glm::uvec3 framebuffer_config) : Application()
        {
            sf::ContextSettings settings = DEFAULT_CONTEXT_SETTINGS;
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
            // 开始
            m_is_running = true;
            m_timer.start();

            // 初始化
            onCreated();

            // 绘制第一帧
            m_last_draw_time = Utils::get_current_time();
            onDisplay();
            onUpdate();

            // 主循环
            sf::Event event;
            while (m_is_running && m_window->isOpen())
            {
                // 处理事件
                while (m_window->pollEvent(event))
                {
                    // 检查是否处理完毕
                    // 处理完毕则处理下一个事件
                    if (onEvent(event))
                        continue;

                    // 没处理完毕则开始默认处理
                    switch (event.type)
                    {
                        // 如果事件为关闭
                    case sf::Event::EventType::Closed:
                        onClose();
                        break;

                        // 如果事件为重设窗口大小
                    case sf::Event::EventType::Resized:
                    {
                        const sf::Vector2u size = m_window->getSize();
                        onResized(glm::uvec2(size.x, size.y));
                    }
                    break;

                    default:
                        break;
                    }
                }

                // 如果正在运行
                if (m_is_running)
                {
                    // 获取当前事件
                    const Utils::Time current_time = Utils::get_current_time();
                    // 计算时间差
                    m_delta_time = current_time - m_last_draw_time;

                    // 开始绘制
                    onProcess(m_delta_time);
                    onDisplay();
                    m_window->display();
                    onUpdate();

                    // 更新时间
                    m_last_draw_time = Utils::get_current_time();
                }
            }

            // 停止计时器
            m_timer.stop();
            // 输出程序运行时长
            Instance::log.logi("Application", Utils::to_string("Application Finished\nexit code:", m_exit_code, "\n", m_timer.get_total_time().as_seconds(), " seconds exist"));

            // 释放资源
            onDestroyed();

            // 退出
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
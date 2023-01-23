#ifndef __NEUTRON_WINDOW_APPLICATION_CPP__
#define __NEUTRON_WINDOW_APPLICATION_CPP__

#include "Application.hpp"

namespace ntk
{
    namespace Window
    {
        Application::Application() : m_is_running(false), m_exit_code(0), m_timer() {}
        Application::Application(const Application &from) { *this = from; }
        Application::~Application() {}

        Application &Application::operator=(const Application &from)
        {
            m_is_running = from.m_is_running;
            m_exit_code = from.m_exit_code;
            m_timer = from.m_timer;
            return *this;
        }

        void Application::quit(int code)
        {
            m_is_running = false;
            m_exit_code = code;
        }

        bool Application::is_running() const
        {
            return m_is_running;
        }

        int Application::get_exit_code() const
        {
            if (m_is_running)
                return 0;
            else
                return m_exit_code;
        }

        const Utils::Timer &Application::get_timer() const
        {
            return m_timer;
        }

        void Application::onCreated()
        {
        }

        void Application::onDisplay()
        {
        }

        void Application::onDestroyed()
        {
        }

        void Application::onResized(const glm::uvec2& new_size)
        {
        }

        void Application::onKeyPressed(uint8_t key)
        {
        }
    } // namespace Window

} // namespace ntk

#endif
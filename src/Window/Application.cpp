#ifndef __NEUTRON_WINDOW_APPLICATION_CPP__
#define __NEUTRON_WINDOW_APPLICATION_CPP__

#include "Application.hpp"

namespace ntk
{
    namespace Window
    {
        Application::Application() : m_is_running(false), m_exit_code(0), m_timer(), m_delta_time() {}

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

        const Utils::Time &Application::get_delta_time() const
        {
            return m_delta_time;
        }

        void Application::onCreated()
        {
        }

        void Application::onProcess(const Utils::Time &delta_time)
        {
        }

        void Application::onDisplay()
        {
        }

        void Application::onUpdate()
        {
        }

        void Application::onDestroyed()
        {
        }

        void Application::onResized(const glm::uvec2 &new_size)
        {
        }

        void Application::onKeyPressed(std::uint32_t key)
        {
        }

        void Application::onKeyReleased(std::uint32_t key)
        {
        }

        void Application::onTextEntered(std::uint32_t  unicode)
        {
        }
    } // namespace Window

} // namespace ntk

#endif
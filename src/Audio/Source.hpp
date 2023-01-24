#ifndef __NEUTRON_AUDIO_SOURCE_HPP__
#define __NEUTRON_AUDIO_SOURCE_HPP__

#include <glm/glm.hpp>
#include "AL.hpp"
#include "Bindable.hpp"
#include "Buffer.hpp"

namespace ntk
{
    namespace Audio
    {
        /// @brief 源
        class Source : public Bindable
        {
        protected:
            /// @brief 缓冲对象
            Buffer m_buffer;
            /// @brief 俯仰角
            float m_pitch = 1.0f;
            /// @brief 增益
            float m_gain = 1.0f;
            /// @brief 位置
            glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
            /// @brief 速度
            glm::vec3 m_velocity = glm::vec3(0.0f, 0.0f, 0.0f);
            /// @brief 循环
            bool m_looping = false;

        public:
            Source();
            Source(ALuint objectID);
            Source(const Source &from);
            ~Source();

        public:
            Source &operator=(const Source &from);

        public:
            const Buffer &get_buffer() const;
            float get_pitch() const;
            float get_gain() const;
            const glm::vec3 &get_position() const;
            const glm::vec3 &get_velocity() const;
            bool is_looping() const;

            virtual void set_buffer(const Buffer &buffer);
            virtual void set_pitch(float pitch);
            virtual void set_gain(float gain);
            virtual void set_position(const glm::vec3 &position);
            virtual void set_velocity(const glm::vec3 &velocity);
            virtual void set_looping(bool looping);

        public:
            virtual SourceStatus::Status get_status() const;

        public:
            virtual void play();
            virtual void pause();
            virtual void stop();
            virtual void rewind();

        public:
            virtual void set_sourceID(ALuint sourceID);
            virtual void update();

        public:
            virtual void generate();
            virtual bool is_correct_objectID(ALuint objectID);
            virtual void delete_object();
        };
    } // namespace Audio

} // namespace ntk

#endif
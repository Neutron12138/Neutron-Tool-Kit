#ifndef __NEUTRON_AUDIO_CONTEXT_HPP__
#define __NEUTRON_AUDIO_CONTEXT_HPP__

#include "AL.hpp"
#include "ALCObject.hpp"

namespace ntk
{
    namespace Audio
    {
        /// @brief OpenAL上下文
        class Context : public ALCObject<ALCcontext>
        {
        public:
            /// @brief 当前绑定的上下文，没有则为空
            static Context *current_context;

        public:
            Context() = default;
            Context(ALCcontext *context);
            Context(const Context &from) = default;
            ~Context() = default;

        public:
            Context &operator=(const Context &from) = default;

        public:
            /// @brief 设置为当前上下文。如果对象为空，则会弹出错误
            virtual void make_context_current();

            /// @brief 取消当前上下文
            virtual void unmake_context_current();

            /// @brief 销毁上下文，同release()
            virtual void destroy();

        public:
            virtual void release();
        };
    } // namespace Audio

} // namespace ntk

#endif
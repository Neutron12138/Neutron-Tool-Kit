#ifndef __NEUTRON_AUDIO_CONTEXT_CPP__
#define __NEUTRON_AUDIO_CONTEXT_CPP__

#include "Context.hpp"
#include "../Instances.hpp"

namespace ntk
{
    namespace Audio
    {
        Context *Context::current_context = nullptr;

        Context::Context() : ALCObject() {}
        Context::Context(ALCcontext *context) : ALCObject(context) {}
        Context::Context(const Context &from) { *this = from; }
        Context::~Context() {}

        Context &Context::operator=(const Context &from)
        {
            ALCObject::operator=(from);
            return *this;
        }

        void Context::make_context_current()
        {
            if (m_object != nullptr)
            {
                alcMakeContextCurrent(m_object);
                current_context = this;
            }
            else
            {
                Instance::log.loge("Context","You will associate a null pointer context");
            }
        }

        void Context::unmake_context_current()
        {
            alcMakeContextCurrent(nullptr);
            current_context = nullptr;
        }

        void Context::destroy()
        {
            release();
        }

        void Context::release()
        {
            if (m_object != nullptr)
            {
                alcDestroyContext(m_object);
                m_object = nullptr;
            }
        }
    } // namespace Audio

} // namespace ntk

#endif
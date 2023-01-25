#ifndef __NEUTRON_AUDIO_DEVICE_CPP__
#define __NEUTRON_AUDIO_DEVICE_CPP__

#include "Device.hpp"
#include "../Instances.hpp"
#include "../Utils/String/StringUtils.hpp"

namespace ntk
{
    namespace Audio
    {
        Device::Device() : ALCObject() {}
        Device::Device(ALCdevice *device) : ALCObject(device) {}
        Device::Device(const Device &from) { *this = from; }
        Device::~Device() {}

        Device &Device::operator=(const Device &from)
        {
            ALCObject::operator=(from);
            return *this;
        }

        bool Device::open()
        {
            ALCdevice *device = alcOpenDevice(nullptr);
            if (device != nullptr)
            {
                m_object = device;
                return true;
            }
            else
            {
                Instance::log.loge("Device", "Unable to open default device");
                return false;
            }
        }

        bool Device::open(const String &devicename)
        {
            ALCdevice *device = alcOpenDevice(devicename.to_string().data());
            if (device != nullptr)
            {
                m_object = device;
                return true;
            }
            else
            {
                Instance::log.loge("Device", Utils::construct_string("Unable to open device:\"", devicename, "\""));
                return false;
            }
        }

        void Device::close()
        {
            release();
        }

        Context Device::create_context()
        {
            if (m_object != nullptr)
            {
                return Context(alcCreateContext(m_object, nullptr));
            }
            else
            {
                Instance::log.loge("Device", "Cannot create context on a null pointer device");
                return Context();
            }
        }

        Context Device::create_context(const ALCint *attrlist)
        {
            if (m_object != nullptr)
            {
                return Context(alcCreateContext(m_object, attrlist));
            }
            else
            {
                Instance::log.loge("Device", "Cannot create context on a null pointer device");
                return Context();
            }
        }

        void Device::release()
        {
            if (m_object != nullptr)
            {
                alcCloseDevice(m_object);
                m_object = nullptr;
            }
        }
    } // namespace Audio

} // namespace ntk

#endif
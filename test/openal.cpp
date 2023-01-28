#include <iostream>
#include <cmath>
#include <al.h>
#include <alc.h>

int main()
{
    ALCdevice *device = alcOpenDevice(nullptr);
    ALCcontext *context = nullptr;
    if (device != nullptr)
    {
        context = alcCreateContext(device, nullptr);
        alcMakeContextCurrent(context);
    }

    ALuint source, buffer;

    const ALsizei size = 800;
    ALsizei freq = 8000;
    ALboolean loop = 1;
    short data[800];
    alGenBuffers(1, &buffer);
    float max = SHRT_MAX / 4;
    float rad = 0;
    for (short &e : data)
    {
        e = (short)(max * tan(rad));
        rad += 1.f;
    }

    alBufferData(buffer, AL_FORMAT_MONO16, data, size, freq);
    alGenSources(1, &source);

    ALfloat SourcePos[] = {0.0, 0.0, 0.0};
    ALfloat SourceVel[] = {0.0, 0.0, 0.0};

    alSourcei(source, AL_BUFFER, buffer);
    alSourcef(source, AL_PITCH, 1.0f);
    alSourcef(source, AL_GAIN, 1.0f);
    alSourcefv(source, AL_POSITION, SourcePos);
    alSourcefv(source, AL_VELOCITY, SourceVel);
    alSourcei(source, AL_LOOPING, loop);

    alSourcePlay(source);
    printf("Press Enter To Stop Sound\n");
    std::getchar();
    alSourceStop(source);

    alDeleteBuffers(1, &buffer);
    alDeleteSources(1, &source);

    alcMakeContextCurrent(nullptr);
    alcDestroyContext(context);
    alcCloseDevice(device);
    return 0;
}
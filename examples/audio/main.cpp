#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

int main()
{
    std::unique_ptr<ntk::Audio::Device, ntk::Utils::ALCObjectDeleter<ntk::Audio::Device>> device;
    device.reset(new ntk::Audio::Device());
    if (!device->open())
        return EXIT_FAILURE;

    std::unique_ptr<ntk::Audio::Context, ntk::Utils::ALCObjectDeleter<ntk::Audio::Context>> context;
    context.reset(new ntk::Audio::Context());
    *context = device->create_context();
    context->make_context_current();

    std::vector<short> data(800);
    float rad = 0.0f;
    for (auto &elem : data)
    {
        elem = short(1024.0f * sin(rad));
        std::cout << elem << std::endl;
        rad += 0.1f;
    }

    std::unique_ptr<ntk::Audio::Buffer, ntk::Utils::ALObjectDeleter<ntk::Audio::Buffer>> buffer;
    buffer.reset(new ntk::Audio::Buffer());
    buffer->generate();
    buffer->bind_data(AL_FORMAT_MONO16, data, 8000);

    std::unique_ptr<ntk::Audio::Source, ntk::Utils::ALObjectDeleter<ntk::Audio::Source>> source;
    source.reset(new ntk::Audio::Source());
    source->set_buffer(*buffer);
    source->set_looping(true);
    source->generate();
    source->update();

    source->play();
    std::cout << "Press Enter To Stop Sound" << std::endl;
    std::getchar();
    source->stop();

    context->unmake_context_current();
    return 0;
}
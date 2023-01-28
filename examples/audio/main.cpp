#include <iostream>
#include "../../src/Neutron.hpp"
#include "../../src/Neutron.cpp"

int main()
{
    ntk::Utils::UniquePointer<ntk::Audio::Device, ntk::Utils::ResourceDeleter<ntk::Audio::Device>> device(new ntk::Audio::Device());
    if (!device->open())
        return EXIT_FAILURE;

    ntk::Utils::UniquePointer<ntk::Audio::Context, ntk::Utils::ResourceDeleter<ntk::Audio::Context>> context(new ntk::Audio::Context());
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

    ntk::Utils::UniquePointer<ntk::Audio::Buffer, ntk::Utils::ResourceDeleter<ntk::Audio::Buffer>> buffer(new ntk::Audio::Buffer());
    buffer->generate();
    buffer->bind_data(AL_FORMAT_MONO16, data, 8000);

    ntk::Utils::UniquePointer<ntk::Audio::Source, ntk::Utils::ResourceDeleter<ntk::Audio::Source>> source;
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
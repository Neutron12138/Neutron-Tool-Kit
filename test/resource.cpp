#include <iostream>
#include "../src/Neutron.hpp"
#include "../src/Neutron.cpp"

class MyResource : public ntk::Utils::ResourceObject
{
private:
    int m_id;

public:
    MyResource(int id) : m_id(id) {}
    ~MyResource() {}

public:
    virtual void release()
    {
        std::cout << m_id << " released" << std::endl;
    }
};

class MyGLObject : public ntk::Graphics::GLObject
{
private:
    int m_id;

public:
    MyGLObject(int id) : m_id(id) {}
    ~MyGLObject() {}

public:
    virtual void delete_object()
    {
        std::cout << m_id << " deleted" << std::endl;
    }

    virtual bool is_correct_objectID(GLuint objectID)
    {
        return false;
    }
};

int main()
{
    std::unique_ptr<MyResource, ntk::Utils::ResourceDeleter<MyResource>> ptr1(new MyResource(0));
    std::unique_ptr<MyGLObject, ntk::Utils::GLObjectDeleter<MyGLObject>> ptr2(new MyGLObject(1));

    std::shared_ptr<MyResource> ptr3(new MyResource(2), ntk::Utils::ResourceDeleter<MyResource>());
    std::shared_ptr<MyGLObject> ptr4(new MyGLObject(3), ntk::Utils::GLObjectDeleter<MyGLObject>());
    std::shared_ptr<MyResource> ptr5 = ptr3;
    std::shared_ptr<MyGLObject> ptr6 = ptr4;
    return 0;
}
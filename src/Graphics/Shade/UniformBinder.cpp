#ifndef __NEUTRON_GRAPHICS_UNIFORMBINDER_CPP__
#define __NEUTRON_GRAPHICS_UNIFORMBINDER_CPP__

#include <glm/gtc/type_ptr.hpp>
#include "UniformBinder.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        GLint UniformBinder::get_uniform_location(const std::string &name)
        {
            GLint location = glGetUniformLocation(get_program(), name.data());
            if (location == -1)
            {
                Instance::log.loge("Uniform Binder", Instance::string_utils.to_string("No uniform found:\"", name, "\""));
            }
            return location;
        }

        void UniformBinder::set_uniform(const std::string &name, GLboolean value)
        {
            set_uniform(name, static_cast<GLint>(value));
        }

        void UniformBinder::set_uniform(const std::string &name, GLint value)
        {
            glUniform1i(get_uniform_location(name), value);
        }

        void UniformBinder::set_uniform(const std::string &name, GLuint value)
        {
            glUniform1ui(get_uniform_location(name), value);
        }

        void UniformBinder::set_uniform(const std::string &name, GLfloat value)
        {
            glUniform1f(get_uniform_location(name), value);
        }

        void UniformBinder::set_uniform(const std::string &name, GLboolean x, GLboolean y)
        {
            set_uniform(name, static_cast<GLint>(x), static_cast<GLint>(y));
        }

        void UniformBinder::set_uniform(const std::string &name, GLint x, GLint y)
        {
            glUniform2i(get_uniform_location(name), x, y);
        }

        void UniformBinder::set_uniform(const std::string &name, GLuint x, GLuint y)
        {
            glUniform2ui(get_uniform_location(name), x, y);
        }

        void UniformBinder::set_uniform(const std::string &name, GLfloat x, GLfloat y)
        {
            glUniform2f(get_uniform_location(name), x, y);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::bvec2 &value)
        {
            set_uniform(name, value.x, value.y);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::ivec2 &value)
        {
            set_uniform(name, value.x, value.y);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::uvec2 &value)
        {
            set_uniform(name, value.x, value.y);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::vec2 &value)
        {
            set_uniform(name, value.x, value.y);
        }

        void UniformBinder::set_uniform(const std::string &name, GLboolean x, GLboolean y, GLboolean z)
        {
            set_uniform(name, static_cast<GLint>(x), static_cast<GLint>(y), static_cast<GLint>(z));
        }

        void UniformBinder::set_uniform(const std::string &name, GLint x, GLint y, GLint z)
        {
            glUniform3i(get_uniform_location(name), x, y, z);
        }

        void UniformBinder::set_uniform(const std::string &name, GLuint x, GLuint y, GLuint z)
        {
            glUniform3ui(get_uniform_location(name), x, y, z);
        }

        void UniformBinder::set_uniform(const std::string &name, GLfloat x, GLfloat y, GLfloat z)
        {
            glUniform3f(get_uniform_location(name), x, y, z);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::bvec3 &value)
        {
            set_uniform(name, value.x, value.y, value.z);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::ivec3 &value)
        {
            set_uniform(name, value.x, value.y, value.z);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::uvec3 &value)
        {
            set_uniform(name, value.x, value.y, value.z);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::vec3 &value)
        {
            set_uniform(name, value.x, value.y, value.z);
        }

        void UniformBinder::set_uniform(const std::string &name, GLboolean x, GLboolean y, GLboolean z, GLboolean w)
        {
            set_uniform(name, static_cast<GLint>(x), static_cast<GLint>(y), static_cast<GLint>(z), static_cast<GLint>(w));
        }

        void UniformBinder::set_uniform(const std::string &name, GLint x, GLint y, GLint z, GLint w)
        {
            glUniform4i(get_uniform_location(name), x, y, z, w);
        }

        void UniformBinder::set_uniform(const std::string &name, GLuint x, GLuint y, GLuint z, GLuint w)
        {
            glUniform4i(get_uniform_location(name), x, y, z, w);
        }

        void UniformBinder::set_uniform(const std::string &name, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
        {
            glUniform4i(get_uniform_location(name), x, y, z, w);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::bvec4 &value)
        {
            set_uniform(name, value.x, value.y, value.z, value.w);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::ivec4 &value)
        {
            set_uniform(name, value.x, value.y, value.z, value.w);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::uvec4 &value)
        {
            set_uniform(name, value.x, value.y, value.z, value.w);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::vec4 &value)
        {
            set_uniform(name, value.x, value.y, value.z, value.w);
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::mat2 &value, GLboolean transpose)
        {
            glUniformMatrix2fv(get_uniform_location(name), 1, transpose, glm::value_ptr(value));
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::mat3 &value, GLboolean transpose)
        {
            glUniformMatrix3fv(get_uniform_location(name), 1, transpose, glm::value_ptr(value));
        }

        void UniformBinder::set_uniform(const std::string &name, const glm::mat4 &value, GLboolean transpose)
        {
            glUniformMatrix4fv(get_uniform_location(name), 1, transpose, glm::value_ptr(value));
        }
    } // namespace Graphics

} // namespace ntk

#endif
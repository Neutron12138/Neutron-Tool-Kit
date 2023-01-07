#ifndef __NEUTRON_GRAPHICS_UNIFORMBINDER_HPP__
#define __NEUTRON_GRAPHICS_UNIFORMBINDER_HPP__

#include <string>
#include <glm/glm.hpp>
#include "../GL.hpp"
#include "../../Base/Object.hpp"

namespace ntk
{
    namespace Graphics
    {
        class UniformBinder : public Object
        {
        public:
            /// @brief 绑定uniform需要一个着色程序对象，用此函数来获取
            /// @return 着色程序对象
            virtual GLuint get_program() = 0;

        public:
            /// @brief 获取uniform的位置
            /// @param name uniform的名称
            /// @return uniform的位置
            virtual GLint get_uniform_location(const std::string &name);

        public:
            virtual void set_uniform(const std::string &name, GLboolean value);
            virtual void set_uniform(const std::string &name, GLint value);
            virtual void set_uniform(const std::string &name, GLuint value);
            virtual void set_uniform(const std::string &name, GLfloat value);

            virtual void set_uniform(const std::string &name, GLboolean x, GLboolean y);
            virtual void set_uniform(const std::string &name, GLint x, GLint y);
            virtual void set_uniform(const std::string &name, GLuint x, GLuint y);
            virtual void set_uniform(const std::string &name, GLfloat x, GLfloat y);

            virtual void set_uniform(const std::string &name, const glm::bvec2 &value);
            virtual void set_uniform(const std::string &name, const glm::ivec2 &value);
            virtual void set_uniform(const std::string &name, const glm::uvec2 &value);
            virtual void set_uniform(const std::string &name, const glm::vec2 &value);

            virtual void set_uniform(const std::string &name, GLboolean x, GLboolean y, GLboolean z);
            virtual void set_uniform(const std::string &name, GLint x, GLint y, GLint z);
            virtual void set_uniform(const std::string &name, GLuint x, GLuint y, GLuint z);
            virtual void set_uniform(const std::string &name, GLfloat x, GLfloat y, GLfloat z);

            virtual void set_uniform(const std::string &name, const glm::bvec3 &value);
            virtual void set_uniform(const std::string &name, const glm::ivec3 &value);
            virtual void set_uniform(const std::string &name, const glm::uvec3 &value);
            virtual void set_uniform(const std::string &name, const glm::vec3 &value);

            virtual void set_uniform(const std::string &name, GLboolean x, GLboolean y, GLboolean z, GLboolean w);
            virtual void set_uniform(const std::string &name, GLint x, GLint y, GLint z, GLint w);
            virtual void set_uniform(const std::string &name, GLuint x, GLuint y, GLuint z, GLuint w);
            virtual void set_uniform(const std::string &name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);

            virtual void set_uniform(const std::string &name, const glm::bvec4 &value);
            virtual void set_uniform(const std::string &name, const glm::ivec4 &value);
            virtual void set_uniform(const std::string &name, const glm::uvec4 &value);
            virtual void set_uniform(const std::string &name, const glm::vec4 &value);

            virtual void set_uniform(const std::string &name, const glm::mat2 &value, GLboolean transpose = GL_FALSE);
            virtual void set_uniform(const std::string &name, const glm::mat3 &value, GLboolean transpose = GL_FALSE);
            virtual void set_uniform(const std::string &name, const glm::mat4 &value, GLboolean transpose = GL_FALSE);
        };
    } // namespace Graphics

} // namespace ntk

#endif
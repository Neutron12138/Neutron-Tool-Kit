#ifndef __NEUTRON_GRAPHICS_SHADER_CPP__
#define __NEUTRON_GRAPHICS_SHADER_CPP__

#include "Shader.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        Shader::Shader(GLenum shader_type) : GLObject(), m_shader_type(shader_type) {}
        Shader::Shader(GLenum shader_type, GLuint shaderID) : m_shader_type(shader_type) { set_shaderID(shaderID); }
        Shader::Shader(const Shader &from) { *this = from; }
        Shader::~Shader() {}

        Shader &Shader::operator=(const Shader &from)
        {
            GLObject::operator=(from);
            m_shader_type = from.m_shader_type;
            return *this;
        }

        GLenum Shader::get_shader_type() const
        {
            return m_shader_type;
        }

        bool Shader::load_from_string(const std::string &source)
        {
            // 编译着色器
            const char *sourceptr = source.data();
            GLuint shaderID = glCreateShader(m_shader_type);
            glShaderSource(shaderID, 1, &sourceptr, nullptr);
            glCompileShader(shaderID);

            // 检查是否编译成功
            // 不知道为什么，我得到的success是相反的，所以改用length
            int length;
            glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
            if (length == 0)
            {
                // 赋值着色器
                // 因为glCreateShader()一定会创建一个不为0的着色器对象，所以不需要使用set_shaderID()
                m_objectID = shaderID;
            }
            else
            {
                // 输出编译日志
                char *info_log = new char[length];
                glGetShaderInfoLog(shaderID, length, nullptr, info_log);
                Instance::log.loge("Shader", info_log);
                delete[] info_log;

                // 删除着色器
                glDeleteShader(shaderID);
            }

            return length == 0;
        }

        bool Shader::load_from_stream(std::istream &is)
        {
            bool success = load_from_string(Instance::string_utils.load_string_from_stream(is));
            if (!success)
            {
                if (Instance::string_utils.load_string_from_stream_status != Utils::StringUtilsStatus::SUCCESS)
                    Instance::log.loge("Shader", Instance::string_utils.load_string_from_stream_result);
            }
            return success;
        }

        bool Shader::load_from_file(const std::string &filename)
        {
            bool success = load_from_string(Instance::string_utils.load_string_from_file(filename));
            if (!success)
            {
                if (Instance::string_utils.load_string_from_file_status != Utils::StringUtilsStatus::SUCCESS)
                    Instance::log.loge("Shader", Instance::string_utils.load_string_from_file_result);
            }
            return success;
        }

        void Shader::set_shaderID(GLuint shaderID)
        {
            // 如果shaderID不为0且类型正确
            if (shaderID != 0 && is_correct_objectID(shaderID))
            {
                m_objectID = shaderID;
            }
            // 如果shaderID类型不正确
            else if (!is_correct_objectID(shaderID))
            {
                Instance::log.loge("Shader", "The type of OpenGL object to be assigned is not a shader.");
            }
            // 如果shaderID为0
            // 若类型不正确，则会在上个分支停止，即本分支只会是shaderID为0
            else
            {
                Instance::log.logw("Shader", "You will assign a reserved value to the shader.");
                m_objectID = shaderID;
            }
        }

        bool Shader::is_correct_objectID(GLuint objectID)
        {
            return glIsShader(objectID);
        }

        void Shader::delete_object()
        {
            if (!is_null())
            {
                glDeleteShader(m_objectID);
                m_objectID = 0;
            }
        }
    } // namespace Graphics

} // namespace ntk

#endif
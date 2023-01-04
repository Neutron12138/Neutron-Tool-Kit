#ifndef __NEUTRON_GRAPHICS_PROGRAM_CPP__
#define __NEUTrON_GRAPHICS_PROGRAM_CPP__

#include "Program.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        Program *Program::current_program = nullptr;

        Program::Program() : GLObject(), m_vertex_shader(GL_VERTEX_SHADER), m_fragment_shader(GL_FRAGMENT_SHADER) {}
        Program::Program(GLuint programID) : GLObject(programID), m_vertex_shader(GL_VERTEX_SHADER), m_fragment_shader(GL_FRAGMENT_SHADER) {}
        Program::Program(const Program &from) : GLObject(), m_vertex_shader(GL_VERTEX_SHADER), m_fragment_shader(GL_FRAGMENT_SHADER) { *this = from; }
        Program::~Program() {}

        Program &Program::operator=(const Program &from)
        {
            GLObject::operator=(from);
            m_vertex_shader = from.m_vertex_shader;
            m_fragment_shader = from.m_fragment_shader;
            return *this;
        }

        const Shader &Program::get_vertex_shader() const
        {
            return m_vertex_shader;
        }

        const Shader &Program::get_fragment_shader() const
        {
            return m_fragment_shader;
        }

        bool Program::load_from_shader(const Shader &vshader, const Shader &fshader)
        {
            // 检查着色器
            GLuint vshaderID = vshader.get_objectID();
            GLuint fshaderID = fshader.get_objectID();
            if (vshaderID == 0)
            {
                Instance::log.loge("Program", Instance::string_utils.to_string("Invalid vertex shader to attach, value:", vshaderID));
                return false;
            }
            if (fshaderID == 0)
            {
                Instance::log.loge("Program", Instance::string_utils.to_string("Invalid fragment shader to attach, value:", fshaderID));
                return false;
            }

            // 创建着色程序并链接
            GLuint programID = glCreateProgram();
            glAttachShader(programID, vshaderID);
            glAttachShader(programID, fshaderID);
            glLinkProgram(programID);

            // 检查是否成功
            int length;
            glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &length);
            if (length == 0)
            {
                set_objectID(programID);
                m_vertex_shader = vshader;
                m_fragment_shader = fshader;
            }
            else
            {
                char *info_log = new char[length];
                glGetProgramInfoLog(programID, length, nullptr, info_log);
                Instance::log.loge("Program", info_log);
                delete[] info_log;

                glDeleteProgram(programID);
            }

            return length == 0;
        }

        bool Program::load_from_string(const std::string &vsource, const std::string &fsource)
        {
            // 加载两个着色器
            Shader vshader(GL_VERTEX_SHADER);
            Shader fshader(GL_FRAGMENT_SHADER);
            bool vsuccess = vshader.load_from_string(vsource);
            bool fsuccess = fshader.load_from_string(fsource);

            // 链接为着色程序
            if (vsuccess && fsuccess)
            {
                return load_from_shader(vshader, fshader);
            }
            else
            {
                return false;
            }
        }

        bool Program::load_from_stream(std::istream &vis, std::istream &fis)
        {
            // 加载两个着色器
            Shader vshader(GL_VERTEX_SHADER);
            Shader fshader(GL_FRAGMENT_SHADER);
            bool vsuccess = vshader.load_from_stream(vis);
            bool fsuccess = fshader.load_from_stream(fis);

            // 链接为着色程序
            if (vsuccess && fsuccess)
            {
                return load_from_shader(vshader, fshader);
            }
            else
            {
                return false;
            }
        }

        bool Program::load_from_file(const std::string &vfilename, const std::string &ffilename)
        {
            // 加载两个着色器
            Shader vshader(GL_VERTEX_SHADER);
            Shader fshader(GL_FRAGMENT_SHADER);
            bool vsuccess = vshader.load_from_file(vfilename);
            bool fsuccess = fshader.load_from_file(ffilename);

            // 链接为着色程序
            if (vsuccess && fsuccess)
            {
                return load_from_shader(vshader, fshader);
            }
            else
            {
                return false;
            }
        }

        void Program::set_programID(GLuint programID)
        {
            // 如果programID不为0且类型正确
            if (programID != 0 && is_correct_objectID(programID))
            {
                m_objectID = programID;
            }
            // 如果programID类型不正确
            else if (!is_correct_objectID(programID))
            {
                Instance::log.loge("Program", "The type of OpenGL object to be assigned is not a program.");
            }
            // 如果programID为0
            else
            {
                Instance::log.logw("Program", "You will assign a reserved value to the program.");
                m_objectID = programID;
            }
        }

        bool Program::is_correct_objectID(GLuint objectID)
        {
            return glIsProgram(objectID);
        }

        void Program::delete_object()
        {
            if (m_objectID != 0)
            {
                glDeleteProgram(m_objectID);
                m_objectID = 0;
            }
        }

        GLuint Program::get_program()
        {
            return m_objectID;
        }

        void Program::use_program()
        {
            if (m_objectID == 0)
            {
                Instance::log.logw("Program", "You will bind the reserved value of OpenGL.");
            }
            glUseProgram(m_objectID);
            current_program = this;
        }

        void Program::delete_shaders()
        {
            m_vertex_shader.delete_object();
            m_fragment_shader.delete_object();
        }
    } // namespace Graphics

} // namespace ntk

#endif
#ifndef __NEUTRON_BASICPROGRAM_CPP__
#define __NEUTRON_BASICPROGRAM_CPP__

#include "BasicProgram.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        BasicProgram *BasicProgram::current_program = nullptr;

        BasicProgram::BasicProgram(GLuint programID) : GLObject(programID) {}

        void BasicProgram::set_programID(GLuint programID)
        {
            // 如果programID不为0且类型正确
            if (programID != 0 && is_correct_objectID(programID))
            {
                m_objectID = programID;
            }
            // 如果programID类型不正确
            else if (!is_correct_objectID(programID))
            {
                Instance::log.loge("Basic Program", "The type of OpenGL object to be assigned is not a program.");
            }
            // 如果programID为0
            else
            {
                Instance::log.logw("Basic Program", "You will assign a reserved value to the program.");
                m_objectID = programID;
            }
        }

        bool BasicProgram::is_correct_objectID(GLuint objectID)
        {
            return glIsProgram(objectID);
        }

        GLuint BasicProgram::get_program()
        {
            return m_objectID;
        }

        void BasicProgram::generate()
        {
            m_objectID = glCreateProgram();
        }

        void BasicProgram::delete_object()
        {
            if (m_objectID != 0)
            {
                glDeleteProgram(m_objectID);
                m_objectID = 0;
            }
        }

        void BasicProgram::use_program()
        {
            if (m_objectID == 0)
            {
                Instance::log.logw("Basic Program", "You will bind the reserved value of OpenGL.");
                current_program = nullptr;
            }
            else
            {
                current_program = this;
            }
            glUseProgram(m_objectID);
        }
    } // namespace Graphics

} // namespace ntk

#endif
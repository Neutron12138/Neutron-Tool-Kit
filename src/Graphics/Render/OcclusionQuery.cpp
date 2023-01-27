#ifndef __NEUTRON_GRAPHICS_OCCLUSIONQUERY_CPP__
#define __NEUTRON_GRAPHICS_OCCLUSIONQUERY_CPP__

#include "OcclusionQuery.hpp"
#include "../../Instances.hpp"

namespace ntk
{
    namespace Graphics
    {
        OcclusionQuery::OcclusionQuery(GLuint queryID) : GLObject(queryID) {}

        OcclusionQuery::QueryType OcclusionQuery::get_query_type() const
        {
            return m_query_type;
        }

        GLint OcclusionQuery::get_result() const
        {
            if (m_objectID == 0)
                Instance::log.loge("Occlusion Query", "You try to get the result of an null occlusion query object");
            return m_result;
        }

        bool OcclusionQuery::is_result_available()
        {
            if (m_objectID != 0)
            {
                GLint available;
                glGetQueryObjectiv(m_objectID, GL_QUERY_RESULT_AVAILABLE, &available);
                return true;
            }
            else
            {
                Instance::log.loge("Occlusion Query", "You try to get whether the result of an null occlusion query object is available");
                return false;
            }
        }

        GLint OcclusionQuery::check_result()
        {
            if (is_result_available())
            {
                glGetQueryObjectiv(m_objectID, GL_QUERY_RESULT, &m_result);
                return m_result;
            }
            else
            {
                return -1;
            }
        }

        bool OcclusionQuery::any_passed()
        {
            if (is_result_available())
                return m_result != 0;
            else
                return false;
        }

        void OcclusionQuery::begin_query(OcclusionQuery::QueryType query_type)
        {
            if (m_objectID != 0)
                glBeginQuery(static_cast<GLenum>(query_type), m_objectID);
            else
                Instance::log.loge("Occlusion Query", "You tried to start an null occlusion query object");
            m_query_type = query_type;
            m_result = -1;
        }

        void OcclusionQuery::end_query()
        {
            glEndQuery(m_query_type);
        }

        void OcclusionQuery::begin_conditional_render(OcclusionQuery::ConditionalRenderType conditional_render_type)
        {
            if (m_objectID != 0)
                glBeginConditionalRender(m_objectID, static_cast<GLenum>(conditional_render_type));
            else
                Instance::log.loge("Occlusion Query", "You tried to start an null occlusion query object");
            m_conditional_render_type = conditional_render_type;
        }

        void OcclusionQuery::end_conditional_render()
        {
            glEndConditionalRender();
        }

        void OcclusionQuery::generate()
        {
            glGenQueries(1, &m_objectID);
        }

        bool OcclusionQuery::is_correct_objectID(GLuint objectID)
        {
            return glIsQuery(objectID);
        }

        void OcclusionQuery::release()
        {
            if (m_objectID != 0)
            {
                glDeleteQueries(1, &m_objectID);
                m_objectID = 0;
            }
        }
    } // namespace Graphics

} // namespace ntk

#endif
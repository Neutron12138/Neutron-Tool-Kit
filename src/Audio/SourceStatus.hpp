#ifndef __NEUTRON_AUDIO_SOURCESTATUS_HPP__
#define __NEUTRON_AUDIO_SOURCESTATUS_HPP__

#include "AL.hpp"

namespace ntk
{
    namespace Audio
    {
        /// @brief 源的状态
        namespace SourceStatus
        {
            /// @brief 状态
            enum Status
            {
                /// @brief 正在播放
                Playing = 0,

                /// @brief 已暂停
                Paused,

                /// @brief 已停止
                Stopped,

                /// @brief 未知
                Unknown,

                /// @brief 总计
                Count,
            };
        } // namespace SourceStatus

    } // namespace Audio

} // namespace ntk

#endif
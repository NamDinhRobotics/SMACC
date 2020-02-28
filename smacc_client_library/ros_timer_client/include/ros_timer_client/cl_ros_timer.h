#pragma once

#include <smacc/smacc.h>
#include <boost/signals2.hpp>
#include <boost/optional/optional_io.hpp>

namespace cl_ros_timer_client
{
template <typename TSource, typename TObjectTag>
struct EvTimer : sc::event<EvTimer<TSource, TObjectTag>>
{
    /*
    ClRosTimer *sender;
    ros::TimerEvent timedata;

    EvTimer(ClRosTimer *sender, const ros::TimerEvent &timedata)
    {
        this->sender = sender;
        this->timedata = timedata;
    }
    */
};

class ClRosTimer : public smacc::ISmaccClient
{
public:
    ClRosTimer(ros::Duration duration, bool oneshot = false);

    virtual ~ClRosTimer();

    virtual void initialize();

    template <typename T>
    boost::signals2::connection onTimerTick(void (T::*callback)(), T *object)
    {
        return this->getStateMachine()->createSignalConnection(onTimerTick_, callback, object);
    }

    template <typename TObjectTag, typename TDerived>
    void configureEventSourceTypes()
    {
        this->postTimerEvent_ = [=]() {
            this->postEvent<EvTimer<ClRosTimer, TObjectTag>>();
        };
    }

protected:
    ros::NodeHandle nh_;

    ros::Timer timer;
    ros::Duration duration;
    bool oneshot;

    void timerCallback(const ros::TimerEvent &timedata);
    std::function<void()> postTimerEvent_;
    smacc::SmaccSignal<void()> onTimerTick_;
};
} // namespace cl_ros_timer_client

#include <smacc/smacc.h>
namespace sm_dance_bot
{
struct StRotateDegrees2 : smacc::SmaccState<StRotateDegrees2, MsDanceBotRunMode>
{
  using SmaccState::SmaccState;

  typedef mpl::list<
      // Expected event
      smacc::transition<EvActionSucceeded<smacc::SmaccMoveBaseActionClient, NavigationOrthogonal>, StNavigateToWaypointsX>,

      // Error events
      //smacc::transition<smacc::EvTopicMessageTimeout<SbLidarSensor>, StAcquireSensors>,
      smacc::transition<EvActionAborted<smacc::SmaccMoveBaseActionClient, NavigationOrthogonal>, StNavigateToWaypointsX>>
      reactions;

  static void onDefinition()
  {
    static_configure<NavigationOrthogonal, SbRotate>(/*30*/ -90);
    static_configure<ToolOrthogonal, SbToolStop>();
    static_configure<ObstaclePerceptionOrthogonal, SbLidarSensor>();
  }
  
  void onInitialize()
  {
    
  }
};
}
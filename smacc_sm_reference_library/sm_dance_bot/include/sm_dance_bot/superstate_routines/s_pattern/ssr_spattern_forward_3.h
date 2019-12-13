struct SsrSPatternForward3 : public smacc::SmaccState<SsrSPatternForward3, SS>
{
  using SmaccState::SmaccState;

  typedef mpl::list<smacc::transition<EvActionSucceeded<smacc::SmaccMoveBaseActionClient, NavigationOrthogonal>, SsrSPatternRotate4>,
                    smacc::transition<EvActionAborted<smacc::SmaccMoveBaseActionClient, NavigationOrthogonal>, SsrSPatternRotate3>
                    > reactions;

  static void onDefinition()
  {
    static_configure<NavigationOrthogonal, SbNavigateForward>(SS::pitch2_lenght_meters());
    static_configure<ToolOrthogonal, SbToolStart>();
  }

  void onInitialize()
  {

  }
};
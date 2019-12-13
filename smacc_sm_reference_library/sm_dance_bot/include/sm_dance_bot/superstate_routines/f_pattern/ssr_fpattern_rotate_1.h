struct SsrFPatternRotate1 : smacc::SmaccState<SsrFPatternRotate1, SS>
{
  using SmaccState::SmaccState;

  typedef smacc::transition<EvActionSucceeded<smacc::SmaccMoveBaseActionClient, NavigationOrthogonal>, SsrFPatternForward1> reactions;

  static void onDefinition()
  {
    float angle = 0;
    if (SS::direction() == TDirection::LEFT)
      angle = 90;
    else
      angle = -90;

    static_configure<NavigationOrthogonal, SbRotate>(angle);
    static_configure<ToolOrthogonal, SbToolStop>();
  }

  void onInitialize()
  {
    
  }
};
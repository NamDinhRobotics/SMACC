struct st_rotate_degrees_1 : smacc::SmaccState<st_rotate_degrees_1, sm_dance_bot>
{
  using SmaccState::SmaccState;

  void onInitialize()
  {
    this->configure<NavigationOrthogonal>(new sb_rotate(360));
    this->configure<ToolOrthogonal>(new sb_tool_stop());
  }
};
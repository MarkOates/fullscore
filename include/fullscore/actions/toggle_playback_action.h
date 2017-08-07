#pragma once



#include <fullscore/actions/action_base.h>



class PlaybackControl;

namespace Action
{
   class TogglePlayback : public Base
   {
   private:
      PlaybackControl *playback_control;

   public:
      TogglePlayback(PlaybackControl *playback_control);
      ~TogglePlayback();
      bool execute() override;
   };
}




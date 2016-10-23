#ifndef __FULLSCORE_RESET_PLAYBACK_ACTION
#define __FULLSCORE_RESET_PLAYBACK_ACTION




#include <fullscore/actions/action_base.h>



class GUIScoreEditor;

namespace Action
{
   class ResetPlayback : public Base
   {
   private:
      GUIScoreEditor *score_editor;

   public:
      ResetPlayback(GUIScoreEditor *score_editor);
      ~ResetPlayback();
      bool execute() override;
   };
}




#endif

#ifndef __FULLSCORE_RESET_PLAYBACK_ACTION
#define __FULLSCORE_RESET_PLAYBACK_ACTION




#include <fullscore/actions/action_base.h>



class UIGridEditor;

namespace Action
{
   class ResetPlayback : public Base
   {
   private:
      UIGridEditor *score_editor;

   public:
      ResetPlayback(UIGridEditor *score_editor);
      ~ResetPlayback();
      bool execute() override;
   };
}




#endif

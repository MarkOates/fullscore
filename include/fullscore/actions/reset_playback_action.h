#ifndef __FULLSCORE_RESET_PLAYBACK_ACTION
#define __FULLSCORE_RESET_PLAYBACK_ACTION




#include <fullscore/actions/action_base.h>



class UIMeasureGridEditor;

namespace Action
{
   class ResetPlayback : public Base
   {
   private:
      UIMeasureGridEditor *score_editor;

   public:
      ResetPlayback(UIMeasureGridEditor *score_editor);
      ~ResetPlayback();
      bool execute() override;
   };
}




#endif

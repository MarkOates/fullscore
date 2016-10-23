#ifndef __FULLSCORE_TOGGLE_PLAYBACK_ACTION_HEADER
#define __FULLSCORE_TOGGLE_PLAYBACK_ACTION_HEADER




#include <fullscore/actions/action_base.h>




class GUIScoreEditor;
class UIMixer;

namespace Action
{
   class TogglePlayback : public Base
   {
   private:
      GUIScoreEditor *score_editor;
      UIMixer *ui_mixer;

   public:
      TogglePlayback(GUIScoreEditor *score_editor, UIMixer *ui_mixer);
      ~TogglePlayback();
      bool execute() override;
   };
}




#endif

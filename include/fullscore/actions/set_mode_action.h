#ifndef __FULLSCORE_SET_MODE_ACTION_HEADER
#define __FULLSCORE_SET_MODE_ACTION_HEADER




#include <fullscore/actions/action_base.h>

#include <fullscore/gui_score_editor.h>




class UICommandBar;

namespace Action
{
   class SetMode : public Base
   {
   private:
      GUIScoreEditor *score_editor;
      UICommandBar *command_bar;
      GUIScoreEditor::mode_t mode;

   public:
      SetMode(GUIScoreEditor *score_editor, UICommandBar *command_bar, GUIScoreEditor::mode_t mode);
      ~SetMode();
      bool execute() override;
   };
}




#endif

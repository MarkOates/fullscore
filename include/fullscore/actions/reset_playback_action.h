#pragma once



#include <fullscore/actions/action_base.h>



class UIGridEditor;

namespace Action
{
   class ResetPlayback : public Base
   {
   private:
      UIGridEditor *grid_editor;

   public:
      ResetPlayback(UIGridEditor *grid_editor);
      ~ResetPlayback();
      bool execute() override;
   };
}




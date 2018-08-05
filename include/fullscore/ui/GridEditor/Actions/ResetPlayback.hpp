#pragma once



#include <fullscore/actions/Base.h>



class UIGridEditor;

namespace UI::GridEditor::Actions
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




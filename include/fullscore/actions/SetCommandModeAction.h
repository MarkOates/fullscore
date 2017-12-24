#pragma once



#include <fullscore/actions/Base.h>

#include <fullscore/widgets/GridEditor.h>



class UICommandBar;

namespace Action
{
   class SetCommandMode : public Base
   {
   private:
      UIGridEditor *grid_editor;
      UICommandBar *command_bar;

   public:
      SetCommandMode(UIGridEditor *grid_editor, UICommandBar *command_bar);
      ~SetCommandMode();

      bool execute() override;
   };
}



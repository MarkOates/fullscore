#ifndef __FULLSCORE_TOGGLE_COMMAND_BAR_ACTION_HEADER
#define __FULLSCORE_TOGGLE_COMMAND_BAR_ACTION_HEADER




#include <fullscore/actions/action_base.h>



class UICommandBar;

namespace Action
{
   class ToggleCommandBar : public Base
   {
   private:
      UICommandBar *command_bar;

   public:
      ToggleCommandBar(UICommandBar *command_bar);
      ~ToggleCommandBar();
      bool execute() override;
   };
}




#endif

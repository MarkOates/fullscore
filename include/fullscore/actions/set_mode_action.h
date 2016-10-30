#ifndef __FULLSCORE_SET_MODE_ACTION_HEADER
#define __FULLSCORE_SET_MODE_ACTION_HEADER




#include <fullscore/actions/action_base.h>



class UICommandBar;

namespace Action
{
   class SetMode : public Base
   {
   private:
      UICommandBar *command_bar;

   public:
      SetMode(UICommandBar *command_bar);
      ~SetMode();
      bool execute() override;
   };
}




#endif

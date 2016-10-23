#ifndef __FULLSCORE_MOVE_CURSOR_LEFT_ACTION_HEADER
#define __FULLSCORE_MOVE_CURSOR_LEFT_ACTION_HEADER




#include <fullscore/actions/action_base.h>




namespace Action
{
   class MoveCursorLeft : public Base
   {
   public:
      MoveCursorLeft();
      ~MoveCursorLeft();
      bool execute() override;
   };
}




#endif

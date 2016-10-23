#ifndef __FULLSCORE_ACTION_BASE_HEADER
#define __FULLSCORE_ACTION_BASE_HEADER




namespace Action
{
   class Base
   {
   public:
      Base();
      ~Base();
      virtual bool execute() = 0;
   };
};




#endif

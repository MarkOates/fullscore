#pragma once



#include <vector>
#include <fullscore/actions/action_base.h>



class Note;

namespace Action
{
   namespace Transform
   {
      class ClearMeasure : public Base
      {
      private:
         std::vector<Note> *notes;

      public:
         ClearMeasure(std::vector<Note> *notes);
         ~ClearMeasure();

         bool execute() override;
      };
   };
};




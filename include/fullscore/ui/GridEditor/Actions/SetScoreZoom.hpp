#pragma once



#include <fullscore/actions/Base.h>



class UIGridEditor;
class Motion;

namespace UI::GridEditor::Actions
{
   class SetScoreZoom : public ::Action::Base
   {
   private:
      UIGridEditor *grid_editor;
      Motion *motion;
      float destination;
      float duration;

   public:
      SetScoreZoom(UIGridEditor *grid_editor, Motion *motion, float destination, float duration);
      ~SetScoreZoom();

      bool execute() override;
   };
};




#pragma once



#include <fullscore/actions/Base.h>



namespace UI::GridEditor { class Widget; }
class Motion;

namespace UI::GridEditor::Actions
{
   class SetScoreZoom : public ::Action::Base
   {
   private:
      UI::GridEditor::Widget *grid_editor;
      Motion *motion;
      float destination;
      float duration;

   public:
      SetScoreZoom(UI::GridEditor::Widget *grid_editor, Motion *motion, float destination, float duration);
      ~SetScoreZoom();

      bool execute() override;
   };
};




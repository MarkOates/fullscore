#pragma once


#include <fullscore/actions/Base.h>


namespace UI::PlotterList { class Widget; }


namespace UI::PlotterList::Actions
{
   class MoveCursorDown : public Action::Base
   {
   private:
      UI::PlotterList::Widget *widget;

   public:
      MoveCursorDown(UI::PlotterList::Widget *widget);
      ~MoveCursorDown();

      bool execute() override;
   };
};



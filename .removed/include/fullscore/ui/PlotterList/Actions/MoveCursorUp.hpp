#pragma once


#include <fullscore/actions/Base.h>


namespace UI::PlotterList { class Widget; }


namespace UI::PlotterList::Actions
{
   class MoveCursorUp : public Action::Base
   {
   private:
      UI::PlotterList::Widget *plotter_list_widget;

   public:
      MoveCursorUp(UI::PlotterList::Widget *plotter_list_widget);
      ~MoveCursorUp();

      bool execute() override;
   };
};



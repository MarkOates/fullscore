#pragma once


#include <fullscore/actions/Base.h>


namespace UI::PlotterList { class Widget; }


namespace UI::PlotterList::Actions
{
   class SelectPlotter : public Action::Base
   {
   private:
      UI::PlotterList::Widget *plotter_list_widget;

   public:
      SelectPlotter(UI::PlotterList::Widget *plotter_list_widget);
      ~SelectPlotter();

      bool execute() override;
   };
};



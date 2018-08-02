#pragma once


#include <fullscore/actions/Base.h>


class PlotterListWidget;

namespace Action
{
   namespace PlotterListWidget
   {
      class MoveCursorDownAction : public Action::Base
      {
      private:
         ::PlotterListWidget *plotter_list_widget;

      public:
         MoveCursorDownAction(::PlotterListWidget *plotter_list_widget);
         ~MoveCursorDownAction();

         bool execute() override;
      };
   }
};



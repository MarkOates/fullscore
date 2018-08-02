#pragma once


#include <fullscore/actions/Base.h>


class PlotterListWidget;

namespace Action
{
   namespace PlotterListWidget
   {
      class MoveCursorUpAction : public Action::Base
      {
      private:
         ::PlotterListWidget *plotter_list_widget;

      public:
         MoveCursorUpAction(::PlotterListWidget *plotter_list_widget);
         ~MoveCursorUpAction();

         bool execute() override;
      };
   }
};



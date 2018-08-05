#pragma once


#include <vector>
#include <fullscore/actions/Base.h>


class PlotterList;


namespace UI::GridEditor::Actions
{
   class PlotPlotterList : public Base
   {
   private:
      PlotterList *plotter_list;

   public:
      PlotPlotterList(PlotterList *plotter_list);
      ~PlotPlotterList();

      bool execute() override;
   };
};



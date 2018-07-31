#pragma once


#include <allegro_flare/gui/widget.h>
#include <fullscore/models/lists/PlotterList.hpp>


class PlotterListWidget : public UIWidget
{
private:
   int cursor_pos;
   PlotterList *plotter_list;

public:
   PlotterListWidget(UIWidget *parent, PlotterList *plotter_list, float width=300, float height=400);
   ~PlotterListWidget();

   void set_plotter_list(PlotterList *plotter_list);

   void move_cursor_up();
   void move_cursor_down();

   virtual void on_draw();
};



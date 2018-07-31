#pragma once


#include <allegro_flare/gui/widget.h>
#include <fullscore/models/plotters/Base.h>


class PlotterListWidget : public UIWidget
{
private:
   int cursor_pos;
   std::vector<Plotter::Base *> &plotters;

public:
   PlotterListWidget(UIWidget *parent, std::vector<Plotter::Base *> &plotters);
   ~PlotterListWidget();

   void move_cursor_up();
   void move_cursor_down();

   virtual void on_draw();
};



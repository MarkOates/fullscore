#ifndef __FULLSCORE_CELL_INSTANCE_HEADER
#define __FULLSCORE_CELL_INSTANCE_HEADER



#include <allegro_flare/gui/widget.h>
#include <fullscore/cell.h>

class UICellInstance : public UIWidget
{
private:
   Cell *cell;

public:
   UICellInstance(UIWidget *parent, Cell *cell, float x, float y);

   void on_draw() override;
   void on_click() override;

   void on_mouse_enter() override;
   void on_mouse_leave() override;
   void on_mouse_move(float x, float y, float dx, float dy) override;
};




#endif

#pragma once



#include <allegro_flare/placement2d.h>



class MeasureSelectionBoxRenderer
{
public:
  enum state_t
  {
     STATE_UNDEF = 0,
     STATE_NOTE_FOCUS,
     STATE_MEASURE_FOCUS
  };

private:
  state_t state;
  placement2d placement;
  float selected_note_x, selected_note_w;

public:
   MeasureSelectionBoxRenderer(state_t state, float x, float y, float w, float h, float selected_note_x, float selected_note_w);
   ~MeasureSelectionBoxRenderer();

   void render();
};







#include <fullscore/renderers/MeasureSelectionBoxRenderer.h>



#include <allegro5/allegro_primitives.h>
#include <allegro_flare/color.h>



MeasureSelectionBoxRenderer::MeasureSelectionBoxRenderer(state_t state, float x, float y, float w, float h, float selected_note_x, float selected_note_w)
   : state(state)
   , placement(x, y, w, h)
   , selected_note_x(selected_note_x)
   , selected_note_w(selected_note_w)
{
   placement.align = 0;
}



MeasureSelectionBoxRenderer::~MeasureSelectionBoxRenderer()
{
}



void MeasureSelectionBoxRenderer::render()
{
   placement.start_transform();

   float roundness = 8;
   float outline_thickness = 8;
   ALLEGRO_COLOR base_color = color::hex("fff200");

   switch(state)
   {
   case STATE_NOTE_FOCUS:
      al_draw_filled_rounded_rectangle(0, 0, placement.w, placement.h, roundness, roundness, color::color(base_color, 0.4));
      al_draw_filled_rounded_rectangle(selected_note_x, 0, selected_note_x+selected_note_w, placement.h, roundness, roundness, color::color(color::orange, 0.4));
      break;
   case STATE_MEASURE_FOCUS:
      {
         float outline_padding = outline_thickness * 0.5;
         float _thick_outline_padding = outline_padding * 1.5;
         al_draw_filled_rounded_rectangle(0, 0, placement.w, placement.h, roundness, roundness, color::color(base_color, 0.4));
         al_draw_rounded_rectangle(0-_thick_outline_padding, 0-_thick_outline_padding, placement.w+_thick_outline_padding, placement.h+_thick_outline_padding, roundness, roundness, color::color(base_color, 1), outline_thickness);
         al_draw_rounded_rectangle(0-outline_padding, 0-outline_padding, placement.w+outline_padding, placement.h+outline_padding, roundness, roundness, color::color(color::black, 0.6), 2.0);
         break;
      }
   default:
      throw std::runtime_error("MeasureSelectionBoxRenderer fell back on default state switch statement");
      break;
   };

   placement.restore_transform();
}




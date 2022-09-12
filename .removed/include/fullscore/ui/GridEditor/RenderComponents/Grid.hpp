#pragma once


class Grid;
class MusicEngraver;


namespace UI::GridEditor::RenderComponents
{
   class GridRenderComponent
   {
   private:
      Grid *grid;
      MusicEngraver *music_engraver;
      float full_measure_width;
      float staff_height;
      bool showing_debug_data;
      int focused_floating_measure_id;
      bool is_measure_target;
      int note_cursor_x;

   public:
      GridRenderComponent(Grid *grid, MusicEngraver *engraver, float full_measure_width, float staff_height, int focused_floating_measure_id, bool is_measure_target, int note_cursor_x);
      ~GridRenderComponent();

      void set_showing_debug_data(bool show);

      void render();
   };
}



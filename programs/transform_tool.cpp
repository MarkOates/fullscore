


#include <allegro_flare/allegro_flare.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/converters/stream_operators/NoteStreamOperators.h>
#include <fullscore/models/NoteSet.h>
#include <fullscore/services/MusicEngraver.h>
#include <fullscore/transforms/AddDotTransform.h>


#include <allegro_flare/render_cache.h>



class NoteSetRenderer
{
private:
   NoteSet &note_set;
   std::string output_filename;

public:
   NoteSetRenderer(NoteSet &note_set, std::string output_filename)
      : note_set(note_set)
      , output_filename(output_filename)
   {}

   void render()
   {
      ALLEGRO_BITMAP *bitmap = al_create_bitmap(800, 600);

      al_set_target_bitmap(bitmap);
      al_clear_to_color(color::white);

      MusicEngraver engraver;
      Measure::Basic measure(note_set.get_notes_ref());

      engraver.draw(&measure, 100, 100, 140);

      std::cout << "Saving file \"" << output_filename << "\"...";
      al_save_bitmap(output_filename.c_str(), bitmap);
      std::cout << "saved." << std::endl;
   }
};



int main(int argv, char **argc)
{
   NoteSet note_set({ { -2 }, { 0 }, { 1, Duration::QUARTER, true }, { 3, Duration::HALF }, { -3, Duration::EIGHTH }, { -2, Duration::EIGHTH } });
   NoteSet result_notes_set{{}};

   result_notes_set.get_notes_ref() = Transform::AddDot().transform(note_set.get_notes());

   Measure::Basic measure_before_transform(note_set.get_notes());
   Measure::Basic measure_after_transform(result_notes_set.get_notes());

   al_init();
   if (!al_init_primitives_addon()) std::cerr << "al_init_primitives_addon() failed" << std::endl;
   if (!al_init_image_addon()) std::cerr << "al_init_image_addon() failed" << std::endl;
   if (!al_init_font_addon()) std::cerr << "al_init_font_addon() failed" << std::endl;
   if (!al_init_ttf_addon()) std::cerr << "al_init_ttf_addon() failed" << std::endl;
   al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
   al_create_display(800, 600);

   NoteSetRenderer(note_set, "notes-before.bmp").render();
   NoteSetRenderer(result_notes_set, "notes-after.bmp").render();
}




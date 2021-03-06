


#include <allegro_flare/allegro_flare.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/converters/stream_operators/NoteStreamOperators.h>
#include <fullscore/models/NoteSet.h>
#include <fullscore/services/MusicEngraver.h>

#include <fullscore/transforms/AddDotTransform.h>
#include <fullscore/transforms/AppendNoteTransform.h>
#include <fullscore/transforms/TransposeTransform.h>
#include <fullscore/transforms/DoubleDurationTransform.h>


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



void render_note_set_transformed(NoteSet &note_set, Transform::Base *transform)
{
   std::stringstream filename;
   filename << transform->get_identifier() << ".bmp";

   NoteSet result_notes_set{{}};
   result_notes_set.get_notes_ref() = transform->transform(note_set.get_notes());

   NoteSetRenderer(result_notes_set, filename.str()).render();
}



void process()
{
   NoteSet note_set({ { -2 }, { 0 }, { 1, Duration::QUARTER, true }, { 3, Duration::HALF }, { -3, Duration::EIGHTH }, { -2, Duration::EIGHTH } });
   NoteSet result_notes_set{{}};

   Transform::Base *transform = nullptr;

   transform = new Transform::AddDot();
   render_note_set_transformed(note_set, transform);
   delete transform;

   transform = new Transform::Transpose(3);
   render_note_set_transformed(note_set, transform);
   delete transform;

   transform = new Transform::AppendNote(Note( { 0, Duration::HALF, false } ));
   render_note_set_transformed(note_set, transform);
   delete transform;

   transform = new Transform::DoubleDuration();
   render_note_set_transformed(note_set, transform);
   delete transform;
}



int main(int argv, char **argc)
{
   al_init();

   ALLEGRO_PATH *resource_path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
   al_change_directory(al_path_cstr(resource_path, ALLEGRO_NATIVE_PATH_SEP));
   al_destroy_path(resource_path);

   if (!al_init_primitives_addon()) std::cerr << "al_init_primitives_addon() failed" << std::endl;
   if (!al_init_image_addon()) std::cerr << "al_init_image_addon() failed" << std::endl;
   if (!al_init_font_addon()) std::cerr << "al_init_font_addon() failed" << std::endl;
   if (!al_init_ttf_addon()) std::cerr << "al_init_ttf_addon() failed" << std::endl;
   al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
   al_create_display(800, 600);

   process();
}







#include <allegro_flare/allegro_flare.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/converters/stream_operators/NoteStreamOperators.h>
#include <fullscore/models/NoteSet.h>
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
      RenderCache render_cache;
      //render_cache
      //setup_surface(int w, int h, int multisamples=0, int depth=0);
      //finish_surface();
      al_save_bitmap(output_filename.c_str(), render_cache.get_surface_bitmap());
   }
};



int main(int argv, char **argc)
{
   NoteSet note_set({ { 0 }, { 1 } });
   NoteSet result_notes_set{{}};

   result_notes_set.get_notes_ref() = Transform::AddDot().transform(note_set.get_notes());

   Measure::Basic measure_before_transform(note_set.get_notes());
   Measure::Basic measure_after_transform(result_notes_set.get_notes());

   NoteSetRenderer(note_set, "notes-before.png");
   NoteSetRenderer(result_notes_set, "notes-after.png");
}




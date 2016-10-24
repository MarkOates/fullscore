



#include <fullscore/converters/measure_grid_file_converter.h>

#include <allegro_flare/data_attr.h>
#include <allegro_flare/useful_php.h>
#include <fullscore/converters/note_string_converter.h>
#include <fullscore/models/measure_grid.h>




MeasureGridFileConverter::MeasureGridFileConverter(MeasureGrid *measure_grid, std::string filename)
   : measure_grid(measure_grid)
   , filename(filename)
{}




bool MeasureGridFileConverter::save()
{
   if (!measure_grid) return false;
   if (filename.empty()) return false;

   DataAttr state;

   state.set("grid_height", tostring(measure_grid->get_num_staves()));
   state.set("grid_width", tostring(measure_grid->get_num_measures()));
   state.set("file_format_version", "v0.0.1");

   for (int y=0; y<measure_grid->get_num_staves(); y++)
      for (int x=0; x<measure_grid->get_num_measures(); x++)
      {
         Measure *measure = measure_grid->get_measure(x, y);
         if (!measure || measure->notes.empty()) continue;
         std::string val = "";
         std::vector<std::string> notes_strs;
         for (int n=0; n<(int)measure->notes.size(); n++)
         {
            // grab the note
            Note *note = measure->operator[](n);

            // build the note into a string
            NoteStringConverter note_string_converter(note);
            std::string note_as_str = note_string_converter.write();

            // put it in the stack
            notes_strs.push_back(note_as_str);
         }

         // collapse the note-string
         val = php::implode(";", notes_strs);

         // put it in the state
         state.set(tostring(x) + "," + tostring(y), val);
      }

   return state.save(filename);
}




bool MeasureGridFileConverter::load()
{
   if (!measure_grid) return false;
   if (filename.empty()) return false;

   // unimplemented
   return false;
}





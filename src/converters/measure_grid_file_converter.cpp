



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

   DataAttr state;
   if (!state.load(filename)) return false;

   // clear out the contents of the current measure-grid
   measure_grid->voices.clear(); // TODO: fix this: mkay, this will create dangling pointers of Note* in the measures

   // check the format version
   std::string file_format_version = state.get("file_format_version");
   if (file_format_version != "v0.0.1")
   {
      std::cout << "[MeasureGrid::load(std::string filename)] could not load this format version" << std::endl;
      return false;
   }

   // the the size of the board, and resize the current measure-grid
   int grid_height = atoi(state.get("grid_height").c_str());
   int grid_width = atoi(state.get("grid_width").c_str());
   measure_grid->voices.resize(grid_height, MeasureGrid::Row(grid_width));

   // for now, remove those two elements.  The rest of the data in `state` is measure data
   state.remove("grid_height");
   state.remove("grid_width");
   state.remove("file_format_version");

   // get the
   std::map<std::string, std::string> data = state.get_copy();
   for (std::map<std::string, std::string>::iterator it = data.begin(); it!=data.end(); it++)
   {
      // get the measure x, and y (in the format "x,y")
      std::vector<std::string> parts = php::explode(",", it->first);
      if (parts.size() != 2) continue;
      Measure *measure = measure_grid->get_measure(atoi(parts[0].c_str()), atoi(parts[1].c_str()));

      // get the notes
      std::vector<std::string> notes = php::explode(";", it->second);

      for (unsigned i=0; i<notes.size(); i++)
      {
         // create a new note
         Note new_note = Note();

         // set the note from the string
         NoteStringConverter note_string_reader(&new_note);
         if (!note_string_reader.read(notes[i]))
         {
            std::cout << "[Error:] A note could not successfully be created from the parsed data" << std::endl;
         }

         // put the note into the measure
         measure->notes.push_back(new_note);
      }
   }

   return true;
}





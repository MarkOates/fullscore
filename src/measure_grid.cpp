

#include <iostream>

#include <allegro_flare/useful.h>

#include <fullscore/measure_grid.h>






MeasureGrid::Row::Row(int num_measures) : measures()
{
	measures.resize(num_measures, Measure());
}



Measure &MeasureGrid::Row::operator[](unsigned int index)
{
	if (index >= measures.size()) std::cout << "measure index out of bounds" << std::endl;
	return measures[index];
}








MeasureGrid::MeasureGrid(int num_x_measures, int num_y_staves)
{
	voices.resize(num_y_staves, Row(num_x_measures));
}



Measure *MeasureGrid::get_measure(int x_measure, int y_staff)
{
	// bounds check
	if (x_measure < 0 || x_measure >= this->get_num_measures() || this->get_num_measures() == 0) return NULL;
	if (y_staff < 0 || y_staff >= this->get_num_staves() || this->get_num_staves() == 0) return NULL;

	return &voices[y_staff][x_measure];
}



int MeasureGrid::get_num_measures()
{
	if (voices.empty()) return 0;
	return voices[0].measures.size();
}


int MeasureGrid::get_num_staves()
{
	return voices.size();
}






#include <allegro_flare/data_attr.h>
#include <fullscore/note.h>
#include <allegro_flare/useful_php.h>


bool MeasureGrid::save(std::string filename)
{
	DataAttr state;

	state.set("grid_height", tostring(get_num_staves()));
	state.set("grid_width", tostring(get_num_measures()));
	state.set("file_format_version", "v0.0.1");

	for (int y=0; y<get_num_staves(); y++)
		for (int x=0; x<get_num_measures(); x++)
		{
			Measure *measure = get_measure(x, y);
			if (!measure || measure->notes.empty()) continue;
			std::string val = "";
			std::vector<std::string> notes_strs;
			for (int n=0; n<(int)measure->notes.size(); n++)
			{
				// grab the note
				Note *note = measure->operator[](n);

				// build the note into a string
				std::string note_as_str = note->get_as_string(0);

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




bool MeasureGrid::load(std::string filename)
{
	DataAttr state;
	if (!state.load(filename)) return false;

	// clear out the contents of the current measure-grid
	this->voices.clear(); // TODO: fix this: mkay, this will create dangling pointers of Note* in the measures

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
	voices.resize(grid_height, Row(grid_width));

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
		Measure *measure = this->get_measure(atoi(parts[0].c_str()), atoi(parts[1].c_str()));

		// get the notes
		std::vector<std::string> notes = php::explode(";", it->second);

		for (unsigned i=0; i<notes.size(); i++)
		{
			// create a new note
			Note new_note = Note();

			// set the note from the string
			new_note.set_from_string(notes[i]);

			// put the note into the measure
			measure->notes.push_back(new_note);
		}
	}

	return true;
}



void MeasureGrid::insert_staff(int index)
{
	if (index < 0) index = 0;

	if (index >= (int)voices.size())
	{
		push_staff();
	}
	else 
	{
		int num_measures = (voices.empty()) ? 8 : voices[0].measures.size();
		voices.insert(voices.begin() + index, Row(num_measures)); 
	}
}



bool MeasureGrid::delete_staff(int index)
{
	if (index < 0 || index >= (int)voices.size()) return false;
	voices.erase(voices.begin() + index);
	return true;
}



void MeasureGrid::push_staff()
{
	int num_measures = (voices.empty()) ? 8 : voices[0].measures.size();
	voices.push_back(Row(num_measures));
}



void MeasureGrid::insert_measure(int index)
{
	int num_measures = get_num_measures();
	if (index < 0) index = 0;
	
	if (index >= num_measures)
	{
		push_measure();
	}
	else
	{
		for (unsigned i=0; i<voices.size(); i++)
		{
			// WARNING: this assumes all staves have the same
			// number of measures (they should)
			voices[i].measures.insert(voices[i].measures.begin() + index, Measure());
		}
	}
}

// I love you burhlayburlee <3

bool MeasureGrid::delete_measure(int index)
{
	int num_measures = get_num_measures();
	if (index < 0 || index >= num_measures) return false;
	for (unsigned i=0; i<voices.size(); i++)
		voices[i].measures.erase(voices[i].measures.begin() + index);
   return true;
}



void MeasureGrid::push_measure()
{
	for (unsigned i=0; i<voices.size(); i++)
	{
		voices[i].measures.push_back(Measure());
	}
}






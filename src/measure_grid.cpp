

#include <iostream>

#include <allegro_flare/useful.h>
#include <allegro_flare/data_attr.h>

#include <fullscore/measure_grid.h>






MeasureGrid::Staff::Staff(int num_measures) : measures()
{
	measures.resize(num_measures, Measure());
}



Measure &MeasureGrid::Staff::operator[](unsigned int index)
{
	if (index >= measures.size()) std::cout << "measure index out of bounds" << std::endl;
	return measures[index];
}








MeasureGrid::MeasureGrid(int num_x_measures, int num_y_staves)
{
	voices.resize(num_y_staves, Staff(num_x_measures));
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





bool MeasureGrid::save(std::string filename)
{
	DataAttr state;

	state.set("grid_height", tostring(get_num_staves()));
	state.set("grid_width", tostring(get_num_measures()));

	for (int y=0; y<get_num_staves(); y++)
		for (int x=0; x<get_num_measures(); x++)
		{
			Measure *measure = get_measure(x, y);
			if (!measure || measure->notes.empty()) continue;
			std::string val = "";
			for (int n=0; n<(int)measure->notes.size(); n++)
				val = tostring(measure->get_note_at(n));
			state.set(tostring(x) + " " + tostring(y), val);
		}

	state.save(filename);
}




bool MeasureGrid::load(std::string filename)
{
	// todo
	DataAttr state;
	state.load(filename);
}
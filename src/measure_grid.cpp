

#include <iostream>

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
#ifndef __FULLSCORE_MEASURE_GRID
#define __FULLSCORE_MEASURE_GRID



#include <vector>

#include <fullscore/measure.h>



class MeasureGrid
{
private:
	class Staff
	{
	public:
		std::vector<Measure> measures;
		Staff(int num_measures);
		Measure &operator[](unsigned int index);
	};

	std::vector<Staff> voices;

public:
	MeasureGrid(int num_x_measures, int num_y_staves);
	Measure *get_measure(int x_measure, int y_staff);

	int get_num_staves();
	int get_num_measures();

	bool save(std::string filename);
	bool load(std::string filename);

	void insert_staff(int index);
	bool delete_staff(int index);
	void push_staff();
};






#endif

#ifndef __FULLSCORE_MEASURE_GRID
#define __FULLSCORE_MEASURE_GRID



#include <vector>

#include <fullscore/models/measure.h>
#include <fullscore/models/time_signature.h>




class MeasureGrid
{
private:
	class Row
	{
	public:
		std::vector<Measure> measures;
		Row(int num_measures);
		Measure &operator[](unsigned int index);
	};

	std::vector<Row> voices;
	std::vector<TimeSignature> time_signatures;


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

	void insert_measure(int index);
	bool delete_measure(int index);
	void push_measure();
};






#endif

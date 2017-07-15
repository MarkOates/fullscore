#ifndef __FULLSCORE_MEASURE_GRID
#define __FULLSCORE_MEASURE_GRID



#include <vector>
#include <string>
#include <fullscore/models/measures/basic.h>
#include <fullscore/models/time_signature.h>



class MeasureGrid
{
private:
   friend class MeasureGridFileConverter;
   friend class MeasureGridHelper;

   class Row
   {
   public:
      std::string name;
      std::vector<Measure::Basic *> measures;
      Row(int num_measures);
      Measure::Basic &operator[](unsigned int index);
   };

   std::vector<Row> voices;
   std::vector<TimeSignature> time_signatures;

public:
   MeasureGrid(int num_x_measures, int num_y_staves);
   Measure::Basic *get_measure(int x_measure, int y_staff);

   int get_num_staves() const;
   int get_num_measures() const;

   void insert_staff(int index);
   bool delete_staff(int index);
   void append_staff();

   void insert_measure(int index);
   bool delete_measure(int index);
   void append_measure();

   bool set_voice_name(int row_number, std::string name);
   std::string get_voice_name(int row_number);

   bool set_time_signature(int index, TimeSignature time_signature);
   TimeSignature get_time_signature(int index);
};



#endif

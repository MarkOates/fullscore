#pragma once



#include <fullscore/models/time_signature.h>
#include <string>
#include <vector>



namespace Measure { class Base; }
namespace Staff { class Base; }



class Grid
{
private:
   friend class GridFileConverter;
   friend class GridHelper;

   std::vector<Staff::Base *> voices;
   std::vector<TimeSignature> time_signatures;

public:
   Grid(int num_x_measures, int num_y_staves);
   ~Grid();

   Measure::Base *get_measure(int x_measure, int y_staff);
   bool set_measure(int x_measure, int y_staff, Measure::Base *measure);
   bool delete_measure(int x_measure, int y_staff);

   bool in_grid_range(int x_measure, int y_staff);

   int get_num_staves() const;
   int get_num_measures() const;

   Staff::Base *get_staff(int y_staff);
   std::vector<Staff::Base *> get_staves();
   bool insert_staff(Staff::Base *staff, int index);
   bool delete_staff(int index);
   bool append_staff(Staff::Base *staff);

   void insert_column(int index);
   bool delete_column(int index);
   void append_measure();

   bool set_voice_name(int row_number, std::string name);
   std::string get_voice_name(int row_number);

   bool set_time_signature(int index, TimeSignature time_signature);
   TimeSignature get_time_signature(int index);
   TimeSignature *get_time_signature_ptr(int index); // consider removing this method (having the dependent action rely on a *grid and measure number)

   float get_height() const;
};




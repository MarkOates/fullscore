#pragma once



#include <fullscore/models/TimeSignature.hpp>
#include <string>
#include <vector>



namespace Measure { class Base; }
namespace Staff { class Base; }



class Grid
{
private:
   friend class GridHelper;

   std::vector<Staff::Base *> voices;
   std::vector<TimeSignature> time_signatures;

public:
   Grid(int num_barlines=5);
   ~Grid();

   int get_num_barlines() const;
   int get_num_staves() const;

   Staff::Base *get_staff(int y_staff);
   std::vector<Staff::Base *> get_staves();
   bool insert_staff(Staff::Base *staff, int index);
   bool delete_staff(int index);
   bool append_staff(Staff::Base *staff);

   bool set_voice_name(int row_number, std::string name);
   std::string get_voice_name(int row_number);

   bool set_time_signature(int index, TimeSignature time_signature);
   TimeSignature get_time_signature(int index);
   TimeSignature *get_time_signature_ptr(int index); // consider removing this method (having the dependent action rely on a *grid and measure number)

   float get_height() const;
};




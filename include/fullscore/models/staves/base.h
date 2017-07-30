#pragma once



#include <string>
#include <vector>



namespace Measure { class Base; }



namespace Staff
{
   class Base
   {
   private:
      std::string type;
      int id;

      // MeasureGrid::Row attributes

      std::string name;
      std::vector<Measure::Base *> measures;

   public:
      Base(std::string type, int num_measures);
      virtual ~Base();
      std::string get_type();
      bool is_type(std::string type);
      int get_id();

      // MeasureGrid::Row functions

      void set_name(std::string name);
      std::string get_name();

      int get_num_measures();
      bool set_measure(int measure_x, Measure::Base *measure);
      bool insert_measure(int at_index, Measure::Base *measure);
      bool erase_measure(int at_index);
      bool append_measure(Measure::Base *measure);

      Measure::Base *get_measure(int x_measure);
   };
};




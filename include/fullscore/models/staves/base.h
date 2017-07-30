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

   protected:
      std::vector<Measure::Base *> measures;

   public:
      Base(std::string type);
      virtual ~Base();
      std::string get_type();
      bool is_type(std::string type);
      int get_id();

      // MeasureGrid::Row functions

      void set_name(std::string name);
      std::string get_name();

      int get_num_columns();

      virtual bool set_column(int column_num, Measure::Base *measure);
      virtual bool insert_column(int at_index, Measure::Base *measure);
      virtual bool erase_column(int at_index);
      virtual bool append_column(Measure::Base *measure);

      virtual Measure::Base *get_measure(int column_num);
   };
};




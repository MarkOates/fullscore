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
      std::string name;

   public:
      Base(std::string type);
      virtual ~Base();
      std::string get_type();
      bool is_type(std::string type);
      int get_id();
      void set_name(std::string name);
      std::string get_name();

      virtual int get_num_columns() = 0;
      virtual float get_height() = 0;

      virtual bool set_column(int column_num, Measure::Base *measure) = 0;
      virtual bool insert_column(int at_index, Measure::Base *measure) = 0;
      virtual bool erase_column(int at_index) = 0;
      virtual bool append_column(Measure::Base *measure) = 0;
      virtual Measure::Base *get_measure(int column_num) = 0;
   };
};




#pragma once



#include <fullscore/models/staves/base.h>



namespace Staff
{
   class Spacer : public Base
   {
   public:
      Spacer(int num_columns);
      ~Spacer();

      virtual int get_num_columns() override;

      virtual Measure::Base *get_measure(int column_num) override;
      virtual bool set_column(int column_num, Measure::Base *measure) override;
      virtual bool insert_column(int at_index, Measure::Base *measure) override;
      virtual bool erase_column(int at_index) override;
      virtual bool append_column(Measure::Base *measure) override;
   };
};




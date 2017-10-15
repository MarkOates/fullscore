#pragma once



#include <fullscore/models/staves/base.h>
#include <fullscore/models/grid_horizontal_coordinate.h>



namespace Staff
{
   class Instrument : public Base
   {
   private:
      std::vector<int> columns_of_measure_ids;

      class PositionedMeasure
      {
      public:
         GridHorizontalCoordinate coordinate;
         int measure_id;

         PositionedMeasure(GridHorizontalCoordinate coordinate, int measure_id);
      };

      std::vector<PositionedMeasure> measures;

   public:
      Instrument(int num_columns);
      ~Instrument();

      virtual int get_num_columns() override;
      virtual float get_height() override;

      virtual Measure::Base *get_measure(int column_num) override;
      virtual bool set_column(int column_num, Measure::Base *measure) override;
      virtual bool insert_column(int at_index, Measure::Base *measure) override;
      virtual bool erase_column(int at_index) override;
      virtual bool append_column(Measure::Base *measure) override;
   };
};




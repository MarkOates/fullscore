#pragma once



#include <fullscore/models/measures/Base.hpp>



class Grid;



namespace Measure
{
   class ReferenceByID : public Base
   {
   private:
      int measure_id;

   public:
      ReferenceByID(int measure_id);

      Measure::Base *get_referenced_measure();

      virtual int get_num_notes() override;
      virtual std::vector<Note> get_notes_copy() override;
      virtual bool set_notes(std::vector<Note>) override;
      virtual std::vector<Note> *get_notes_pointer() override;
   };
};




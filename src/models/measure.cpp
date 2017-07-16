


#include <vector>
#include <fullscore/models/measures/base.h>
#include <fullscore/models/measure.h>



namespace Measure
{
   std::vector<Base *> measure_pool = {};



   int next_id = 0;



   Base *find(int id)
   {
      for (auto &measure : measure_pool)
         if (measure->get_id() == id) return measure;
      return nullptr;
   }



   bool destroy(int id)
   {
      Base *measure = Measure::find(id);
      if (measure)
      {
         delete measure;
         return true;
      }
      return false;
   }
};




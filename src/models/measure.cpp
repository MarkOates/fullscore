


#include <vector>
#include <fullscore/models/measures/base.h>
#include <fullscore/models/measure.h>



namespace Measure
{
   std::vector<Base *> measure_pool = {};



   int next_id = 0;



   bool push_back(Measure::Base *measure)
   {
      measure_pool.push_back(measure);
      return true;
   }



   int count()
   {
      return measure_pool.size();
   }



   Base *find(int id)
   {
      for (auto &measure : measure_pool)
         if (measure->get_id() == id) return measure;
      return nullptr;
   }



   bool remove(int id)
   {
      for (unsigned i=0; i<measure_pool.size(); i++)
         if (measure_pool[i]->get_id() == id)
         {
            measure_pool.erase(measure_pool.begin() + i);
            return true;
         }
      return false;
   }



   bool destroy(int id)
   {
      for (unsigned i=0; i<measure_pool.size(); i++)
         if (measure_pool[i]->get_id() == id)
         {
            delete measure_pool[i];
            return true;
         }
      return false;
   }
};




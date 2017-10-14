


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



   Base *find(int id, bool raise_not_found)
   {
      Base *found_measure = nullptr;

      for (auto &measure : measure_pool)
         if (measure->get_id() == id) { found_measure = measure; break; }

      if (raise_not_found && found_measure == nullptr)
      {
         std::stringstream error_message;
         error_message << "Looking for measure with id = " << id << " but does not exist";
         throw std::runtime_error(error_message.str());
      }

      return found_measure;
   }



   std::vector<Base *> find(std::vector<int> ids, bool include_not_found, bool raise_not_found)
   {
      std::vector<Base *> results = {};
      std::vector<int> not_found_ids = {};

      for (unsigned i=0; i<ids.size(); i++)
      {
         try
         {
            Base *found_measure = find(ids[i], raise_not_found);
            if (found_measure || include_not_found) results.push_back(found_measure);
         }
         catch (std::runtime_error const &e)
         {
            not_found_ids.push_back(ids[i]);
         }
      }

      if (!not_found_ids.empty())
      {
         std::stringstream error_message;
         error_message << "Looking for " << ids.size() << " measures but only " << results.size() << " measures found.";
         throw std::runtime_error(error_message.str());
      }

      return results;
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




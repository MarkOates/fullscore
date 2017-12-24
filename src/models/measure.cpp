


#include <vector>
#include <fullscore/models/measures/Base.h>
#include <fullscore/models/Measure.h>



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



   Base *find(int id, find_option_t find_option)
   {
      Base *found_measure = nullptr;

      for (auto &measure : measure_pool)
         if (measure->get_id() == id) { found_measure = measure; break; }

      if (find_option == FIND_OPTION_RAISE_NOT_FOUND && found_measure == nullptr)
      {
         std::stringstream error_message;
         error_message << "Looking for measure with id = " << id << " but does not exist";
         throw std::runtime_error(error_message.str());
      }

      return found_measure;
   }



   std::vector<Base *> find(std::vector<int> ids, find_option_t find_option)
   {
      std::vector<Base *> results = {};
      std::vector<int> not_found_ids = {};
      find_option_t measure_find_option = (find_option == FIND_OPTION_RAISE_NOT_FOUND) ? FIND_OPTION_RAISE_NOT_FOUND : FIND_OPTION_NONE;

      for (unsigned i=0; i<ids.size(); i++)
      {
         try
         {
            Base *found_measure = find(ids[i], measure_find_option);
            if (found_measure || (find_option == FIND_OPTION_INCLUDE_NOT_FOUND)) results.push_back(found_measure);
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



   bool destroy_all()
   {
      for (unsigned i=0; i<measure_pool.size(); i++) delete measure_pool[i];
      measure_pool.clear();
      return true;
   }
};




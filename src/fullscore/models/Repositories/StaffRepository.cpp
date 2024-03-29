


#include <fullscore/models/Repositories/StaffRepository.hpp>

#include <sstream>



namespace StaffRepository
{
   std::vector<Staff::Base *> pool = {};



   int next_id = 0;



   bool push_back(Staff::Base *element)
   {
      pool.push_back(element);
      return true;
   }



   int count()
   {
      return pool.size();
   }



   Staff::Base *find(int id, find_option_t find_option)
   {
      Staff::Base *found_element = nullptr;

      for (auto &element : pool)
         if (element->get_id() == id) { found_element = element; break; }

      if (find_option == FIND_OPTION_RAISE_NOT_FOUND && found_element == nullptr)
      {
         std::stringstream error_message;
         error_message << "Looking for element with id = " << id << " but does not exist";
         throw std::runtime_error(error_message.str());
      }

      return found_element;
   }



   std::vector<Staff::Base *> find(std::vector<int> ids, find_option_t find_option)
   {
      std::vector<Staff::Base *> results = {};
      std::vector<int> not_found_ids = {};
      find_option_t element_find_option = (find_option == FIND_OPTION_RAISE_NOT_FOUND) ? FIND_OPTION_RAISE_NOT_FOUND : FIND_OPTION_NONE;

      for (unsigned i=0; i<ids.size(); i++)
      {
         try
         {
            Staff::Base *found_element = find(ids[i], element_find_option);
            if (found_element || (find_option == FIND_OPTION_INCLUDE_NOT_FOUND)) results.push_back(found_element);
         }
         catch (std::runtime_error const &e)
         {
            not_found_ids.push_back(ids[i]);
         }
      }

      if (!not_found_ids.empty())
      {
         std::stringstream error_message;
         error_message << "Looking for " << ids.size() << " elements but only " << results.size() << " elements found.";
         throw std::runtime_error(error_message.str());
      }

      return results;
   }



   bool remove(int id)
   {
      for (unsigned i=0; i<pool.size(); i++)
         if (pool[i]->get_id() == id)
         {
            pool.erase(pool.begin() + i);
            return true;
         }
      return false;
   }



   bool destroy(int id)
   {
      for (unsigned i=0; i<pool.size(); i++)
         if (pool[i]->get_id() == id)
         {
            delete pool[i];
            return true;
         }
      return false;
   }



   bool destroy_all()
   {
      for (unsigned i=0; i<pool.size(); i++) delete pool[i];
      pool.clear();
      return true;
   }



   Staff::Base *find_first_of_type(std::string type)
   {
      for (auto &element : pool)
         if (element->get_type() == type) return element;
      return nullptr;
   }
};




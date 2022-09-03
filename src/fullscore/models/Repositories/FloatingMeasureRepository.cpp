


#include <fullscore/models/Repositories/FloatingMeasureRepository.hpp>
#include <cmath>



bool ___basically_equal(float f1, float f2, float threshold=0.00001f)
{
   return (std::abs(f1 - f2) < threshold);
}



static bool __compare_floating_measure_x_location(FloatingMeasureRepository *m1, FloatingMeasureRepository *m2)
{
   if (m1->get_grid_coordinate().get_grid_horizontal_coordinate().get_barline_num() == m2->get_grid_coordinate().get_grid_horizontal_coordinate().get_barline_num())
   {
      float m1_x_offset = m1->get_grid_coordinate().get_grid_horizontal_coordinate().get_beat_coordinate().get_x_offset();
      float m2_x_offset = m2->get_grid_coordinate().get_grid_horizontal_coordinate().get_beat_coordinate().get_x_offset();

      if (___basically_equal(m1_x_offset, m2_x_offset)) return (m1->get_id() < m2->get_id());
      return (m1_x_offset < m2_x_offset);
   }
   return (m1->get_grid_coordinate().get_grid_horizontal_coordinate().get_barline_num() < m2->get_grid_coordinate().get_grid_horizontal_coordinate().get_barline_num());
}



FloatingMeasureRepository::FloatingMeasureRepository(GridCoordinate grid_coordinate, int measure_id)
   : id(FloatingMeasureRepository::next_id++)
   , grid_coordinate(grid_coordinate)
   , measure_id(measure_id)
{
   pool_elements.push_back(this);
}



FloatingMeasureRepository::~FloatingMeasureRepository()
{
   std::vector<FloatingMeasureRepository *>::iterator it = std::find(pool_elements.begin(), pool_elements.end(), this);
   if (it == pool_elements.end())
   {
      std::stringstream error_message;
      error_message << "Could not find floating measure (where id = " << id << ") to remove from FloatingMeasureRepository pool_elements";
      throw std::runtime_error(error_message.str());
   }
   pool_elements.erase(it);
}



GridCoordinate FloatingMeasureRepository::get_grid_coordinate()
{
   return grid_coordinate;
}



int FloatingMeasureRepository::get_measure_id()
{
   return measure_id;
}



int FloatingMeasureRepository::get_id()
{
   return id;
}



int FloatingMeasureRepository::next_id = 0;



std::vector<FloatingMeasureRepository *> FloatingMeasureRepository::pool_elements;



int FloatingMeasureRepository::get_next_id()
{
   return next_id;
}



FloatingMeasureRepository *FloatingMeasureRepository::find(int id, find_option_t find_option)
{
   FloatingMeasureRepository *found_element = nullptr;

   for (auto &element : pool_elements)
      if (element->get_id() == id) { found_element = element; break; }

   if (find_option == FIND_OPTION_RAISE_NOT_FOUND && found_element == nullptr)
   {
      std::stringstream error_message;
      error_message << "Looking for FloatingMeasureRepository with id = " << id << " but does not exist";
      throw std::runtime_error(error_message.str());
   }

   return found_element;
}



std::vector<FloatingMeasureRepository *> FloatingMeasureRepository::find_at_staff_and_barline(int staff_id, int barline_num)
{
   std::vector<FloatingMeasureRepository *> results;

   for (auto &element : pool_elements)
   {
      if (element->grid_coordinate.get_staff_id() == staff_id && element->grid_coordinate.get_grid_horizontal_coordinate().get_barline_num() == barline_num)
         results.push_back(element);
   }

   return results;
}



std::vector<FloatingMeasureRepository *> FloatingMeasureRepository::find_in_staff_after_barline(int staff_id, int barline_num, bool sort)
{
   std::vector<FloatingMeasureRepository *> results;

   for (auto &element : pool_elements)
   {
      if (element->grid_coordinate.get_staff_id() == staff_id && element->grid_coordinate.get_grid_horizontal_coordinate().get_barline_num() >= barline_num)
         results.push_back(element);
   }

   if (sort) std::sort(results.begin(), results.end(), __compare_floating_measure_x_location);

   return results;
}



FloatingMeasureRepository *FloatingMeasureRepository::find_first_in_staff_after_barline(int staff_id, int barline_num)
{
   std::vector<FloatingMeasureRepository *> potential_results;

   for (auto &element : pool_elements)
   {
      if (element->grid_coordinate.get_staff_id() == staff_id && element->grid_coordinate.get_grid_horizontal_coordinate().get_barline_num() >= barline_num)
         potential_results.push_back(element);
   }

   if (potential_results.empty()) return nullptr;

   std::sort(potential_results.begin(), potential_results.end(), __compare_floating_measure_x_location);

   return potential_results[0];
}



std::vector<FloatingMeasureRepository *> FloatingMeasureRepository::find_in_staff(int staff_id, bool sort)
{
   std::vector<FloatingMeasureRepository *> results;

   for (auto &element : pool_elements)
      if (element->grid_coordinate.get_staff_id() == staff_id) results.push_back(element);

   if (sort) std::sort(results.begin(), results.end(), __compare_floating_measure_x_location);

   return results;
}



std::vector<FloatingMeasureRepository *> FloatingMeasureRepository::get_pool_elements()
{
   return pool_elements;
}



bool FloatingMeasureRepository::destroy(int id)
{
   for (unsigned i=0; i<pool_elements.size(); i++)
      if (pool_elements[i]->get_id() == id)
      {
         delete pool_elements[i];
         return true;
      }
   return false;
}



bool FloatingMeasureRepository::destroy_all()
{
   for (auto &element : pool_elements) delete element;
   pool_elements.clear();
   return true;
}



int FloatingMeasureRepository::get_num_pool_elements()
{
   return pool_elements.size();
}




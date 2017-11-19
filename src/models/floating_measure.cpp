


#include <fullscore/models/floating_measure.h>



FloatingMeasure::FloatingMeasure(GridCoordinate grid_coordinate, int measure_id)
   : id(FloatingMeasure::next_id++)
   , grid_coordinate(grid_coordinate)
   , measure_id(measure_id)
{
   pool_elements.push_back(this);
}



FloatingMeasure::~FloatingMeasure()
{
   std::vector<FloatingMeasure *>::iterator it = std::find(pool_elements.begin(), pool_elements.end(), this);
   if (it == pool_elements.end())
   {
      std::stringstream error_message;
      error_message << "Could not find floating measure (where id = " << id << ") to remove from FloatingMeasure pool_elements";
      throw std::runtime_error(error_message.str());
   }
   pool_elements.erase(it);
}



GridCoordinate FloatingMeasure::get_grid_coordinate()
{
   return grid_coordinate;
}



int FloatingMeasure::get_measure_id()
{
   return measure_id;
}



int FloatingMeasure::get_id()
{
   return id;
}



int FloatingMeasure::next_id = 0;



std::vector<FloatingMeasure *> FloatingMeasure::pool_elements;



int FloatingMeasure::get_next_id()
{
   return next_id;
}



FloatingMeasure *FloatingMeasure::find(int id, find_option_t find_option)
{
   FloatingMeasure *found_element = nullptr;

   for (auto &element : pool_elements)
      if (element->get_id() == id) { found_element = element; break; }

   if (find_option == FIND_OPTION_RAISE_NOT_FOUND && found_element == nullptr)
   {
      std::stringstream error_message;
      error_message << "Looking for FloatingMeasure with id = " << id << " but does not exist";
      throw std::runtime_error(error_message.str());
   }

   return found_element;
}



std::vector<FloatingMeasure *> FloatingMeasure::find_at_staff_and_barline(int staff_id, int barline_num)
{
   std::vector<FloatingMeasure *> results;

   for (auto &element : pool_elements)
   {
      if (element->grid_coordinate.get_staff_id() == staff_id && element->grid_coordinate.get_grid_horizontal_coordinate().get_barline_num() == barline_num)
         results.push_back(element);
   }

   return results;
}



std::vector<FloatingMeasure *> FloatingMeasure::get_pool_elements()
{
   return pool_elements;
}



bool FloatingMeasure::destroy_all()
{
   for (auto &element : pool_elements) delete element;
   pool_elements.clear();
   return true;
}



int FloatingMeasure::get_num_pool_elements()
{
   return pool_elements.size();
}




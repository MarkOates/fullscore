


#include <fullscore/widgets/measure_inspector.h>

#include <allegro_flare/gui/surface_areas/box.h>
#include <allegro_flare/gui/widgets/text_list.h>
#include <allegro_flare/gui/style_assets.h>
#include <fullscore/models/measures/stack.h>



UIMeasureInspector::UIMeasureInspector(UIWidget *parent)
   : UIWidget(parent, "UIMeasureInspector", new UISurfaceAreaBox(0, 0, 300, 600))
   , measure(nullptr)
{
   place.align = vec2d(1.0, 0.0);
}



void UIMeasureInspector::set_measure(Measure::Base *measure)
{
   this->measure = measure;
}



Measure::Base *UIMeasureInspector::get_measure()
{
   return measure;
}




std::string UIMeasureInspector::_get_measure_string()
{
   std::stringstream ss;
   Measure::Base *measure = get_measure();

   if (!measure)
   {
      ss << "[no measure selected]";
   }
   else
   {
      std::string measure_type = measure->get_type();
      ss << "type: " << measure_type << std::endl;
      if (measure_type == "stack")
      {
         Measure::Stack *stack_measure = static_cast<Measure::Stack *>(measure);
         for (auto &transform : stack_measure->transformations.get_transformations())
         {
            if (transform) ss << transform->get_identifier() << std::endl;
         }
      }
   }

   return ss.str();
}



void UIMeasureInspector::on_draw()
{
   UIStyleAssets::draw_outset(0, 0, place.size.x, place.size.y);

   std::string str = _get_measure_string();

   ALLEGRO_FONT *font = UIStyleAssets::get_text_font();
   al_draw_multiline_text(font, color::white, 0, 0, place.size.x, al_get_font_line_height(font), ALLEGRO_ALIGN_LEFT, str.c_str());
}




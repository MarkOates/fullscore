



#include <allegro_flare/allegro_flare.h>

#include <allegro_flare/drawing_interfaces/drawing_interface_allegro5.h>

#include <fullscore/models/projection_set.h>
#include <fullscore/models/index_set.h>



IndexSet str_to_index_set(std::string str)
{
   IndexSet result({});

   std::vector<std::string> tokens = php::explode(" ", str);
   std::vector<int> ints;
   for (auto &token : tokens)
      if (!token.empty()) ints.push_back(atoi(token.c_str()));

   for (auto &i : ints)
      result.pitches.push_back(ProjectionPitch(i));

   return result;
}



std::string index_set_to_engraver_str(IndexSet &index_set)
{
   std::stringstream ss;
   for (auto &pitch : index_set.pitches)
      ss << "(" << pitch.pitch << ")";
   return ss.str();
}



class UITextInputKeypress : public UITextInput
{
public:
   using UITextInput::UITextInput;

   void on_key_char() override
   {
      UITextInput::on_key_char();
      send_message_to_parent("keydown");
   }
};



class ProjectionCalculator : public UIScreen
{
private:
   UICamera *camera;

   UITextInputKeypress *index_set_input;
   UIMusicNotation *index_set_notation;


public:
   ProjectionCalculator(Display *display)
      : UIScreen(display)
      , camera(new UICamera(this, 0, 0, 0, 0))
      , index_set_input(new UITextInputKeypress(camera, 0, 0, 600, 60))
      , index_set_notation(new UIMusicNotation(camera, 0, 100))
   {
      camera->place.position = vec2d(display->width()/2, display->height()/2);
   }

   void update_calculation()
   {
      // update calculations
      IndexSet index_set = str_to_index_set(index_set_input->get_text());
      index_set_notation->set_val(index_set_to_engraver_str(index_set));
   }

   void on_message(UIWidget *sender, std::string message) override
   {
      if (sender == index_set_input) update_calculation();
   }
};




int main(int, char**)
{
   Framework::initialize();
   Display *display = Framework::create_display(1200, 1200);
   ProjectionCalculator projection_calculator = ProjectionCalculator(display);
   Framework::run_loop();
   return 0;
}






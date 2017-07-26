



#include <allegro_flare/allegro_flare.h>

#include <allegro_flare/drawing_interfaces/drawing_interface_allegro5.h>

#include <fullscore/models/projection_set.h>
#include <fullscore/models/index_set.h>
#include <fullscore/services/pitch_projector.h>



int only_ints_to_int(std::string str)
{
   std::string result = "";

   std::size_t found = str.find_first_of("0123456789");
   while (found!=std::string::npos)
   {
      result.push_back(str[found]);
      found = str.find_first_of("0123456789",found+1);
   }

   found = str.find_first_of("-");
   int result_int = atoi(result.c_str()) * (found == std::string::npos ? 1 : -1);

   return result_int;
}



IndexSet str_to_index_set(std::string str)
{
   IndexSet result({});

   std::vector<std::string> tokens = php::explode(" ", str);
   for (auto &token : tokens)
   {
      if (token.empty()) continue;

      int num_flats = std::count(token.begin(), token.end(), 'b');
      int num_sharps = std::count(token.begin(), token.end(), '#');
      int ints_only_int = only_ints_to_int(token);

      result.pitches.push_back(ProjectionPitch(ints_only_int, num_sharps-num_flats));
   }

   return result;
}



std::string index_set_to_engraver_str(IndexSet &set)
{
   std::stringstream ss;
   ss << "  ";
   for (auto &pitch : set.pitches)
   {
      ss << (pitch.accidental < 0 ? "-" : pitch.accidental > 0 ? "+" : "");
      ss << "(" << pitch.pitch << ")";
   }
   ss << "  ";
   return ss.str();
}




ProjectionSet str_to_projection_set(std::string str, std::string extension_str)
{
   int extension = atoi(extension_str.c_str());
   ProjectionSet result({}, extension);

   std::vector<std::string> tokens = php::explode(" ", str);
   for (auto &token : tokens)
   {
      if (token.empty()) continue;

      int num_flats = std::count(token.begin(), token.end(), 'b');
      int num_sharps = std::count(token.begin(), token.end(), '#');
      int ints_only_int = only_ints_to_int(token);

      result.pitches.push_back(ProjectionPitch(ints_only_int, num_sharps-num_flats));
   }

   return result;
}



std::string projection_set_to_engraver_str(ProjectionSet &set)
{
   std::stringstream ss;
   ss << "  ";
   for (auto &pitch : set.pitches)
   {
      ss << (pitch.accidental < 0 ? "-" : pitch.accidental > 0 ? "+" : "");
      ss << "(" << pitch.pitch << ")";
   }
   ss << "  ";
   return ss.str();
}



class UITextInputKeypress : public UITextInput
{
public:
   using UITextInput::UITextInput;

   void on_key_char() override
   {
      UITextInput::on_key_char();

      if (focused) send_message_to_parent("keydown");
   }
};



class ProjectionCalculator : public UIScreen
{
private:
   UICamera *camera;

   UITextInputKeypress *index_set_input;
   UIMusicNotation *index_set_notation;

   UITextInputKeypress *projection_set_input;
   UITextInputKeypress *projection_set_extension_input;
   UIMusicNotation *projection_set_notation;

   UIText *result_text;
   UIMusicNotation *result_notation;


public:
   ProjectionCalculator(Display *display)
      : UIScreen(display)
      , camera(new UICamera(this, 0, 0, 0, 0))
      , index_set_input(new UITextInputKeypress(camera, 0, 0, 600, 60))
      , index_set_notation(new UIMusicNotation(camera, 0, 100))
      , projection_set_input(new UITextInputKeypress(camera, 0, 300, 600, 60))
      , projection_set_extension_input(new UITextInputKeypress(camera, 0, 400, 100, 60))
      , projection_set_notation(new UIMusicNotation(camera, 0, 500))
      , result_text(new UIText(camera, 100, 600, ""))
      , result_notation(new UIMusicNotation(camera, 0, 700))
   {
      camera->place.position = vec2d(display->width()/2, display->height()-1000);
   }

   void update_calculation()
   {
      // update calculations
      IndexSet index_set = str_to_index_set(index_set_input->get_text());
      index_set_notation->set_val(index_set_to_engraver_str(index_set));

      ProjectionSet projection_set = str_to_projection_set(projection_set_input->get_text(),
            projection_set_extension_input->get_text());
      projection_set_notation->set_val(projection_set_to_engraver_str(projection_set));

      // calculate the projection
      PitchProjector pitch_projector(projection_set, index_set);
      IndexSet projection_result = pitch_projector.get_projection();
      std::string engraver_string = index_set_to_engraver_str(projection_result);

      // set the result
      result_text->set_text(engraver_string);
      result_notation->set_val(engraver_string);
   }

   void on_message(UIWidget *sender, std::string message) override
   {
      if (
            (
               sender == index_set_input
               || sender == projection_set_input
               || sender == projection_set_extension_input
            )
            &&
            (
               message == "keydown"
            )
         )
      {
         update_calculation();
      }
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






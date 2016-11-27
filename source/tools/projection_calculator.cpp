



#include <allegro_flare/allegro_flare.h>

#include <allegro_flare/drawing_interfaces/drawing_interface_allegro5.h>

#include <fullscore/models/projection_set.h>
#include <fullscore/models/index_set.h>
#include <fullscore/pitch_projector.h>



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




class ProjectionCalculator : public UIScreen
{
private:
   DrawingInterfaceAllegro5 drawing_interface_allegro5;
   MusicNotation music_notation;
   std::string music_notation_content_string;
   int notation_width;
   UITextInput *text_input;

public:
   ProjectionCalculator(Display *display)
      : UIScreen(display)
      , drawing_interface_allegro5()
      , music_notation(&drawing_interface_allegro5, 12)
      , music_notation_content_string("")
      , notation_width(0)
      , text_input(new UITextInput(this, display->width()/2, display->height()-120, display->width()/2, 60))
   {
      text_input->set_text("0 1 2 3 4 5");
   }

   void on_timer() override
   {
      // update calculations
      IndexSet index_set = str_to_index_set(text_input->get_text());
      music_notation_content_string = index_set_to_engraver_str(index_set);
   }

   void on_draw() override
   {
      notation_width = music_notation.draw(display->width()/2 - notation_width/2, 300, music_notation_content_string);
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






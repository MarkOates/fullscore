


#include <allegro_flare/allegro_flare.h>


#include <fullscore/models/plotters/destination.h>
#include <fullscore/UI/PlotterEditor/Widget.hpp>
#include <fullscore/actions/Base.h>
#include <fullscore/UI/PlotterEditor/ActionFactory.hpp>


class Project : public UIScreen
{
private:
   Plotter::Destination destination_plotter;
   UI::PlotterEditor::Widget *plotter_editor_widget;

public:
   Project(Display *display)
      : UIScreen(display)
      , destination_plotter()
      , plotter_editor_widget(new UI::PlotterEditor::Widget(this, &destination_plotter))
   {
      plotter_editor_widget->place.position = vec2d(display->width()/2, display->height()/2);
      plotter_editor_widget->place.align = vec2d(0.5, 0.5);
      plotter_editor_widget->place.scale = vec2d(2, 2);

      std::vector<Note> notes = { 1, 2, 3, 4 };
      destination_plotter.set_destinations({ { 3 } });
      destination_plotter.set_notes(notes);
   }

   void key_char_func() override
   {
      UIScreen::key_char_func();

      auto keycode       = Framework::current_event->keyboard.keycode;
      auto shift_pressed = Framework::key_shift;
      auto alt_pressed   = Framework::key_alt;
      auto ctrl_pressed  = Framework::key_ctrl;

      std::vector<std::string> identifiers;

      //if (plotter_editor_widget && plotter_editor_widget->is_focused())
      //{
         identifiers = plotter_editor_widget->get_keyboard_action_mapping(keycode, shift_pressed, ctrl_pressed, alt_pressed);
      //}

      for (auto &identifier : identifiers)
      {
         Action::Base *action = nullptr;

         //if (plotter_editor_widget && plotter_editor_widget->is_focused())
         action = UI::PlotterEditor::ActionFactory::create_action(plotter_editor_widget, identifier);

         if (action)
         {
            try
            {
               if (!action->execute()) throw std::runtime_error("Generic could-not-execute-action exception");
            }
            catch (const std::runtime_error& e)
            {
               std::cout << "Exception caught while trying to run action "
                         << "\"" << action->get_action_name() << "\""
                         << " with the following message \""
                         << e.what()
                         << "\""
                         << std::endl;
            }
            delete action;
         }
         else
         {
            std::stringstream error_message;
            error_message << "Action could not be found with the identifier \"" << identifier << "\". It should be creatable in the ActionFactory." << std::endl;
            throw std::runtime_error(error_message.str());
         }
      }
   }
};



int main(int argc, char *argv[])
{
   Framework::initialize();
   Display *d = Framework::create_display(1920, 1080);
   Project app_controller(d);
   Framework::run_loop();

   return 0;
}




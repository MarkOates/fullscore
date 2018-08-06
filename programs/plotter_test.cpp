


#include <allegro_flare/allegro_flare.h>

//#include <fullscore/AppController.hpp>


#include <fullscore/models/lists/PlotterList.hpp>
#include <fullscore/UI/PlotterList/Widget.hpp>
#include <fullscore/actions/Base.h>
#include <fullscore/UI/PlotterList/ActionFactory.hpp>
#include <fullscore/models/plotters/Destination.h>


class Project : public UIScreen
{
private:
   PlotterList plotter_list;
   UI::PlotterList::Widget *plotter_list_widget;

public:
   Project(Display *display)
      : UIScreen(display)
      , plotter_list()
      , plotter_list_widget(new UI::PlotterList::Widget(this, &plotter_list))
   {
      plotter_list.append(new Plotter::Destination({ 5, 6, 8 }));
      plotter_list.append(new Plotter::Destination({ 5, 6, 8 }));
      plotter_list.append(new Plotter::Destination({ 5, 6, 8 }));
      plotter_list_widget->bring_to_front();
      plotter_list_widget->set_as_focused();
   }

   void key_char_func() override
   {
      UIScreen::key_char_func();

      auto keycode       = Framework::current_event->keyboard.keycode;
      auto shift_pressed = Framework::key_shift;
      auto alt_pressed   = Framework::key_alt;
      auto ctrl_pressed  = Framework::key_ctrl;

      std::vector<std::string> identifiers;

      if (plotter_list_widget && plotter_list_widget->is_focused())
      {
         identifiers = plotter_list_widget->get_keyboard_action_mapping(keycode, shift_pressed, ctrl_pressed, alt_pressed);
      }

      for (auto &identifier : identifiers)
      {
         Action::Base *action = nullptr;

         if (plotter_list_widget && plotter_list_widget->is_focused())
            action = UI::PlotterList::ActionFactory::create_action(plotter_list_widget, identifier);

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






#include <fullscore/AppController.hpp>

#include <allegro_flare/framework.h>
#include <fullscore/factories/GridFactory.h>
#include <fullscore/UI/GridEditor/ActionFactory.hpp>
#include <fullscore/UI/PlotterList/ActionFactory.hpp>
#include <fullscore/models/FloatingMeasure.h>
#include <fullscore/models/GridCoordinate.h>
#include <fullscore/models/Measure.h>
#include <fullscore/models/Staff.h>
#include <fullscore/Action.h>


#include <fullscore/transforms/RetrogradeTransform.h>
#include <fullscore/models/plotters/Basic.h>
#include <fullscore/models/plotters/Destination.h>

static void init_app_based_on_setup_config(AppController *app)
{
   if (!app) throw std::runtime_error("nullptr app!");


   // usually:
   // std::string init_template_identifier = config.get_or_default_str("FULLSCORE_SETTINGS", "init_template", "string_quartet");


   // init grid
   app->set_current_grid_editor_widget(app->create_new_grid_editor("full_score"));
   

   // init plotter list

   std::vector<Note> notes_to_plot = {
      Note(-1, Duration(Duration::QUARTER, 1)),
      Note(0, Duration(Duration::QUARTER, 1)),
      Note(1, Duration(Duration::EIGHTH)),
      Note(2, Duration(Duration::EIGHTH)),
   };

   auto notes_retrograde = Transform::Retrograde().transform(notes_to_plot);

   Grid &grid = app->current_grid_editor_widget->grid;

   app->plotter_list->append(new Plotter::Basic(&grid, 3, notes_to_plot));
   app->plotter_list->append(new Plotter::Basic(&grid, 5, notes_retrograde));

   app->plotter_list->append(
      new Plotter::Destination(
         { { 2, 4 }, { 5, 7 }, { 8, 4 }, }, {
         5, 6, 8
         }
      )
   );
}


AppController::AppController(Display *display, Config &config)
   : UIScreen(display)
   , config(config)
   , simple_notification_screen(new SimpleNotificationScreen(display, Framework::font("DroidSans.ttf 20")))
   , action_queue("master_queue")
   , follow_camera(this)
   , current_grid_editor_widget(nullptr)
   , grid_editor_widgets()
   , command_bar(new UICommandBar(this))
   , plotter_list(new PlotterList)
   , plotter_list_widget(new UI::PlotterList::Widget(this, plotter_list, 300))
   , yank_measure_buffer()
{
   UIScreen::draw_focused_outline = false;

   init_app_based_on_setup_config(this);
   plotter_list_widget->bring_to_front();
}


void AppController::key_char_func()
{
   UIScreen::key_char_func();

   auto keycode       = Framework::current_event->keyboard.keycode;
   auto shift_pressed = Framework::key_shift;
   auto alt_pressed   = Framework::key_alt;
   auto ctrl_pressed  = Framework::key_ctrl;

   std::vector<std::string> identifiers;

   if (plotter_list_widget && plotter_list_widget->is_focused())
      identifiers = plotter_list_widget->get_keyboard_action_mapping(keycode, shift_pressed, ctrl_pressed, alt_pressed);
   else if (current_grid_editor_widget && current_grid_editor_widget->is_focused())
      identifiers = current_grid_editor_widget->get_keyboard_action_mapping(keycode, shift_pressed, ctrl_pressed, alt_pressed);

   for (auto &identifier : identifiers)
   {
      Action::Base *action = nullptr;

      if (plotter_list_widget && plotter_list_widget->is_focused())
         action = UI::PlotterList::ActionFactory::create_action(plotter_list_widget, identifier);
      else if (current_grid_editor_widget && current_grid_editor_widget->is_focused())
         action = UI::GridEditor::ActionFactory::create_action(this, current_grid_editor_widget, identifier);

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


UI::GridEditor::Widget *AppController::create_new_grid_editor(std::string name)
{
   static int new_x = 0;
   static int new_y = 0;

   UI::GridEditor::Widget *new_grid_editor = new UI::GridEditor::Widget(&follow_camera);
   new_grid_editor->grid = GridFactory::create(name);

   new_grid_editor->place.position = vec2d(new_x, new_y);
   new_grid_editor->place.align = vec2d(0.0, 0.0);

   grid_editor_widgets.push_back(new_grid_editor);

   new_y += 300;

   return new_grid_editor;
}


bool AppController::set_current_grid_editor_widget(UI::GridEditor::Widget *editor)
{
   if (std::find(grid_editor_widgets.begin(), grid_editor_widgets.end(), editor) == grid_editor_widgets.end()) return false;

   for (auto &e : grid_editor_widgets)
      e->set_state(e == editor ? UI::GridEditor::Widget::STATE_ACTIVE : UI::GridEditor::Widget::STATE_INACTIVE);

   current_grid_editor_widget = editor;

   // move the camera to the new current_grid_editor_widget
   follow_camera.target.position = -current_grid_editor_widget->place.position + vec2d(200, 200);

   return true;
}


UI::GridEditor::Widget *AppController::get_next_grid_editor_widget()
{
   if (!current_grid_editor_widget || grid_editor_widgets.size() <= 1) return nullptr;

   std::vector<UI::GridEditor::Widget *>::iterator it = std::find(grid_editor_widgets.begin(), grid_editor_widgets.end(), current_grid_editor_widget);

   if (it == grid_editor_widgets.end()) return nullptr; // does not exist in list
   if (it == grid_editor_widgets.end()-1) return grid_editor_widgets.front(); // loop back to first element
   ++it;
   return *it;
}



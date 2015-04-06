#include <allegro_flare/allegro_flare.h>
#include <flare_gui/flare_gui.h>




#include <fullscore/gui_score_editor.h>


#include <fullscore/playback_device_win_midi.h>




class Project : public FGUIScreen
{
public:
	GUIScoreEditor *score_editor;
	FGUIWindow *help_window;
	FGUINotificationBubble *notification_bubble;
	bool showing_help_menu;

	Project(Display *display)
		: FGUIScreen(display)
		, score_editor(NULL)
		, help_window(NULL)
		, notification_bubble(NULL)
		, showing_help_menu(false)
	{
		FGUIScreen::draw_focused_outline = true;
		FGUIScreen::clear_to_background_color = false;

		score_editor = new GUIScoreEditor(this, display, new PlaybackDeviceWinMIDI());
		notification_bubble = new FGUINotificationBubble(this, "Press F1 for help", display->width()-30, display->height()-30);

		create_help_window();
	}
	void create_help_window()
	{
		help_window = new FGUIWindow(this, -600, -100, 550, 700);

		FGUIText *help_title = new FGUIText(help_window, 25, 25, af::fonts["DroidSans.ttf 34"], "Controls");
		FGUITextBox *help_paragraph = new FGUITextBox(help_window, af::fonts["DroidSans.ttf 20"], php::file_get_contents("data/documents/help.txt"), 25, 25+50, 500, 500);

		help_paragraph->set_text_color(color::white);

		help_title->place.align = vec2d(0, 0);
		help_paragraph->place.align = vec2d(0, 0);
	}
	void key_down_func() override
	{
		FGUIScreen::key_down_func();

		switch(af::current_event->keyboard.keycode)
		{
		case ALLEGRO_KEY_F1:
			{
				if (showing_help_menu)
				{
					// hide the help menu
					af::motion.cmove_to(&help_window->place.position.x, -600, 0.4);
					af::motion.cmove_to(&help_window->place.position.y, -100, 0.4);
					af::motion.cmove_to(&help_window->place.rotation, -0.1, 0.4);
					showing_help_menu = false;
				}
				else
				{
					// show the help menu
					af::motion.cmove_to(&help_window->place.position.x, display->center(), 0.4);
					af::motion.cmove_to(&help_window->place.position.y, display->middle(), 0.4);
					af::motion.cmove_to(&help_window->place.rotation, 0, 0.4);
					showing_help_menu = true;
				}
			}
			break;
		case ALLEGRO_KEY_F2:
			{
				// toggle showing the debug data on the editor
				score_editor->showing_debug_data = !score_editor->showing_debug_data;
			}
			break;
		case ALLEGRO_KEY_SPACE:
			{
				// toggle playback
				score_editor->playback_control.toggle_playback();
			}
			break;
		case ALLEGRO_KEY_OPENBRACE:
			{
				// toggle playback
				score_editor->playback_control.reset();
			}
			break;
		}
	}
};





int main(int argc, char *argv[])
{
	af::initialize();
	Display *d = af::create_display(1600, 800);
	Project *proj = new Project(d);
	af::run_loop();
}
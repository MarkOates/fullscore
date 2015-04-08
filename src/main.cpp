#include <allegro_flare/allegro_flare.h>
#include <flare_gui/flare_gui.h>




#include <allegro_flare/screens/simple_notification_screen.h>

#include <fullscore/gui_score_editor.h>


#include <fullscore/playback_device_win_midi.h>




class GUIPlaybackControls : public FGUIWindow
{
public:
	FGUIScaledText *time;
	FGUIScaledText *title;
	FGUIButton *play_button;
	FGUIButton *rewind_button;
	FGUIDraggableRegion *draggable_region;

	GUIPlaybackControls(FGUIParent *parent, float x, float y)
		: FGUIWindow(parent, x, y, 500, 90)
		, title(NULL)
		, time(NULL)
		, play_button(NULL)
		, draggable_region(NULL)
	{
		title = new FGUIScaledText(this, 10, 10, "DroidSans.ttf 18", "Playback Controls");
		title->place.align = vec2d(0, 0);
		title->set_font_color(color::color(color::white, 0.3));

		draggable_region = new FGUIDraggableRegion(this, 0, 0, place.size.x, place.size.y);
		draggable_region->place.align = vec2d(0, 0);

		play_button = new FGUIButton(this, "", af::fonts["DroidSans.ttf 20"], place.size.x-20-50, place.size.y-10-20, 100, 40);
		play_button->attr.set("on_click_send_message", "toggle_playback");
		play_button->set_icon(af::bitmaps["play_icon.png"]);
		play_button->place.align = vec2d(0.5, 0.5);

		rewind_button = new FGUIButton(this, "", af::fonts["DroidSans.ttf 20"], place.size.x-130-25, place.size.y-10-20, 50, 40);
		rewind_button->attr.set("on_click_send_message", "reset_playback");
		rewind_button->set_icon(af::bitmaps["rewind_icon.png"]);
		rewind_button->place.align = vec2d(0.5, 0.5);

		time = new FGUIScaledText(this, 20, place.size.y-10, "minisystem.ttf 36", "4:33.263");
		time->place.align = vec2d(0, 1.0);
		time->set_font_color(color::aliceblue);
	}
	void set_time(double time_in_sec)
	{
		int min = (int)floor(time_in_sec / 60.0);
		int seconds = (int)floor(time_in_sec) - min;
		int msec = (time_in_sec - floor(time_in_sec)) * 1000;
		std::stringstream time_str;
		time_str << std::setfill('0');
		time_str << std::setw(2) << min << ":";
		time_str << std::setw(2) << seconds << ".";
		time_str << std::setw(3) << msec;
		time->set_text(time_str.str());
	}
	void receive_message(std::string message) override
	{
		// right now... the message is just being passed up to the next widget
		// there is certainly a better way to do this (*cough* signals and slots)
		parent->receive_message(message);
	}
};





class Project : public FGUIScreen
{
public:
	SimpleNotificationScreen *simple_notification_screen;

	GUIScoreEditor *score_editor;
	GUIPlaybackControls *gui_playback_controls;
	FGUIWindow *help_window;
	bool showing_help_menu;

	Project(Display *display)
		: FGUIScreen(display)
		, simple_notification_screen(new SimpleNotificationScreen(display, af::fonts["DroidSans.ttf 20"]))
		, score_editor(NULL)
		, gui_playback_controls(NULL)
		, help_window(NULL)
		, showing_help_menu(false)
	{
		FGUIScreen::draw_focused_outline = true;
		FGUIScreen::clear_to_background_color = false;

		score_editor = new GUIScoreEditor(this, display, new PlaybackDeviceWinMIDI());
		gui_playback_controls = new GUIPlaybackControls(this, display->center(), 70);

		simple_notification_screen->spawn_notification("Press F1 for help");

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
	void primary_timer_func() override
	{
		FGUIScreen::primary_timer_func();
		gui_playback_controls->set_time(score_editor->playback_control.position);
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
		case ALLEGRO_KEY_1:
			{
				score_editor->measure_grid.save("score_filename.fs");
				simple_notification_screen->spawn_notification("score saved as \"score_filename.fs\"");
			}
			break;
		case ALLEGRO_KEY_2:
			{
				score_editor->measure_grid.load("score_filename.fs");
				simple_notification_screen->spawn_notification("score loaded from \"score_filename.fs\"");
			}
			break;
		}
	}
	void receive_message(std::string message) override
	{
		std::cout << "message: " << message << std::endl;
		if (message == "toggle_playback") score_editor->playback_control.toggle_playback();
		if (message == "reset_playback") score_editor->playback_control.reset();
	}
};





int main(int argc, char *argv[])
{
	af::initialize();
	Display *d = af::create_display(1600, 800);
	Project *proj = new Project(d);
	af::run_loop();
}
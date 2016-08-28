#include <allegro_flare/allegro_flare.h>




#include <cmath>
#include <iomanip>

#include <allegro_flare/screens/simple_notification_screen.h>

#include <fullscore/gui_score_editor.h>


#include <fullscore/playback_device_generic.h>





class GUIMixer : public UIFramedWindow
{
public:
	class Channel
	{
	public:
		int channel_num;
		int patch;
		Channel(int channel_num, int patch)
			: channel_num(channel_num)
			, patch(patch)
		{}
	};

private:

	class GUIPatchTextInput : public UITextInput
	{
	public:
		int channel_num;
		GUIPatchTextInput(UIWidget *parent, int channel_num, float x, float y)
			: UITextInput(parent, x, y, 50, 30, "0")
			, channel_num(channel_num)
		{}
		void on_change() override
		{
			GUIMixer *mixer = static_cast<GUIMixer *>(UIWidget::family.parent);
			mixer->channels[channel_num].patch = atoi(get_text().c_str());
		} 
	};

	std::vector<Channel> channels;
public:
	GUIMixer(UIWidget *parent, float x_, float y_, int num_channels=8)
		: UIFramedWindow(parent, x_, y_, 300, 376)
		, channels()
	{
		this->set_title("Mixer & Channel Settings");

		// create the channels
		for (unsigned i=0; i<num_channels; i++) channels.push_back(Channel(i, 0));

		// create the input boxes
		float x = 150;
		float y = 100;
		float spacing_y = 30;
		for (unsigned c=0; c<channels.size(); c++)
		{
			UIText *text = new UIText(this, x-10, y, "Channel " + tostring(c+1));
			text->place.align = vec2d(1, 1);

			UITextInput *text_input = new GUIPatchTextInput(this, c, x, y);
			text_input->place.align = vec2d(0, 1);
			text_input->attr.set("select_all_on_focus", "true");

			y += spacing_y;
		}
	}
	Channel *get_channel(int channel_num)
	{
		if (channels.empty() || channel_num < 0 || channel_num >= channels.size()) return NULL;
		return &channels[channel_num];
	}
	int get_patch_num(int channel_num)
	{
		if (channels.empty() || channel_num < 0 || channel_num >= channels.size()) return 0;
		return channels[channel_num].patch;
	}
};





class UIControllerBar : public UIWidget
{
public:
	UIScaledText *time;
	UIButton *play_button;
	UIButton *rewind_button;

	UIControllerBar(UIWidget *parent)
		: UIWidget(parent, "UIControllerBar", new UISurfaceAreaBox(0, 0, parent->place.size.x, 66))
		, time(NULL)
		, play_button(NULL)
	{
      this->place.align = {0.0, 0.0};

		play_button = new UIButton(this, place.size.x-20-50, place.size.y-10-20, 100, 40, "");
		play_button->attr.set("on_click_send_message", "toggle_playback");
		play_button->set_icon(Framework::bitmap("play_icon.png"));
		play_button->place.align = vec2d(0.5, 0.5);

		rewind_button = new UIButton(this, place.size.x-130-25, place.size.y-10-20, 50, 40, "");
		rewind_button->attr.set("on_click_send_message", "reset_playback");
		rewind_button->set_icon(Framework::bitmap("rewind_icon.png"));
		rewind_button->place.align = vec2d(0.5, 0.5);

		time = new UIScaledText(this, 20, place.size.y-10, "4:33.263");
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
   void on_draw() override
   {
      UIStyleAssets::draw_outset(0, 0, place.size.x, place.size.y);
   }
	void on_message(UIWidget *sender, std::string message) override
	{
		// right now... the message is just being passed up to the next widget
		// there is certainly a better way to do this (*cough* signals and slots)
		family.parent->on_message(sender, message);
	}
};





class Project : public UIScreen
{
public:
	SimpleNotificationScreen *simple_notification_screen;

	GUIScoreEditor *score_editor;
	UIControllerBar *gui_controller_bar;
	GUIMixer *gui_mixer;
	UIFramedWindow *help_window;
	bool showing_help_menu;

	Project(Display *display)
		: UIScreen(display)
		, simple_notification_screen(new SimpleNotificationScreen(display, Framework::font("DroidSans.ttf 20")))
		, score_editor(NULL)
		, gui_controller_bar(NULL)
		, gui_mixer(NULL)
		, help_window(NULL)
		, showing_help_menu(false)
	{
		UIScreen::draw_focused_outline = false;

		score_editor = new GUIScoreEditor(this, display, new PlaybackDeviceGeneric());
		gui_mixer = new GUIMixer(this, 1350, 500);
		gui_controller_bar = new UIControllerBar(this);

		simple_notification_screen->spawn_notification("Press F1 for help");

		create_help_window();
	}
	void create_help_window()
	{
		help_window = new UIFramedWindow(this, -600, -100, 550, 700);
		help_window->set_title("Help");

		UIText *help_title = new UIText(help_window, 25, 25, "Controls");
		UITextBox *help_paragraph = new UITextBox(help_window, 25, 25+70, 500, 500, php::file_get_contents("data/documents/help.txt"));

		help_paragraph->set_text_color(color::white);

		help_title->place.align = vec2d(0, 0);
		help_paragraph->place.align = vec2d(0, 0);
	}
	void primary_timer_func() override
	{
		UIScreen::primary_timer_func();
		gui_controller_bar->set_time(score_editor->playback_control.position);
	}
	void key_down_func() override
	{
		UIScreen::key_down_func();

		switch(Framework::current_event->keyboard.keycode)
		{
		case ALLEGRO_KEY_F1:
			{
				if (showing_help_menu)
				{
					// hide the help menu
					Framework::motion().cmove_to(&help_window->place.position.x, -600, 0.4);
					Framework::motion().cmove_to(&help_window->place.position.y, -100, 0.4);
					Framework::motion().cmove_to(&help_window->place.rotation, -0.1, 0.4);
					showing_help_menu = false;
				}
				else
				{
					// show the help menu
					Framework::motion().cmove_to(&help_window->place.position.x, display->center(), 0.4);
					Framework::motion().cmove_to(&help_window->place.position.y, display->middle(), 0.4);
					Framework::motion().cmove_to(&help_window->place.rotation, 0, 0.4);
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
				// send the patches before play
				PlaybackDeviceInterface *device = score_editor->playback_control.playback_device;
				for (unsigned i=0; i<score_editor->measure_grid.get_num_staves(); i++)
				{
					device->patch_change(i, gui_mixer->get_patch_num(i));
				}
				// toggle playback
				score_editor->playback_control.toggle_playback();
			}
			break;
		case ALLEGRO_KEY_Q:
			{
				// toggle playback
				score_editor->playback_control.reset();
			}
			break;
		case ALLEGRO_KEY_F7:
			{
				score_editor->measure_grid.save("score_filename.fs");
				simple_notification_screen->spawn_notification("saved score as \"score_filename.fs\"");
			}
			break;
		case ALLEGRO_KEY_F8:
			{
				score_editor->measure_grid.load("score_filename.fs");
				simple_notification_screen->spawn_notification("loaded score from \"score_filename.fs\"");
			}
			break;
		}
	}
	void on_message(UIWidget *sender, std::string message) override
	{
		std::cout << "message: " << message << std::endl;
		if (message == "toggle_playback") score_editor->playback_control.toggle_playback();
		if (message == "reset_playback") score_editor->playback_control.reset();
	}
};





int main(int argc, char *argv[])
{
	Framework::initialize();
	Display *d = Framework::create_display(1920, 1080);
	Project *proj = new Project(d);
	Framework::run_loop();

   return 0;
}

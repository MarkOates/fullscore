#include <allegro_flare/allegro_flare.h>
#include <flare_gui/flare_gui.h>



#include <fullscore/measure.h>
#include <fullscore/note.h>
#include <fullscore/globals.h>
#include <fullscore/measure_grid.h>
#include <fullscore/music_engraver.h>



class GUIScoreEditor : public FGUIParent
{
public:
	MeasureGrid measure_grid;

	int measure_cursor_x;
	int measure_cursor_y;
	float cursor_x;
	float cursor_y;

	FontBin fonts;
	ALLEGRO_FONT *text_font;

	placement2d camera;

	MusicEngraver music_engraver;

	bool showing_debug_data;

	GUIScoreEditor(FGUIParent *parent, Display *display)
		// the widget is placed in the center of the screen with a padding of 10 pixels to the x and y edges
		: FGUIParent(parent,
			new FGUICollisionBox(display->center(), display->middle(), display->width()-20, display->height()-20))
		, measure_grid(20, 6)
		, measure_cursor_x(-1)
		, measure_cursor_y(-1)
		, cursor_x(0)
		, cursor_y(0)
		, fonts("data/fonts")
		, text_font(fonts["DroidSans.ttf 20"])
		, camera(200, 200, 1, 1)
		, music_engraver()
		, showing_debug_data(false)
	{
		attr.set(FGUI_ATTR__FGUI_WIDGET_TYPE, "GUIScoreEditor");
		attr.set("id", "GUIScoreEditor" + tostring(widget_count));

		measure_grid.get_measure(3,2).notes.push_back(new Note());
		measure_grid.get_measure(3,2).notes.push_back(new Note());
		measure_grid.get_measure(1,3).notes.push_back(new Note());

		camera.align = vec2d(0, 0);
	}
	void on_draw() override
	{
		camera.start_transform();

		// draw a background for the score
		al_draw_filled_rectangle(-30, -30, MEASURE_WIDTH * 20 + 30, STAFF_HEIGHT * 6 + 30, color::color(color::blanchedalmond, 0.2));
		
		// draw barlines
		for (int x=0; x<NUM_X_MEASURES; x++)
		{
			Measure *measure = &measure_grid.get_measure(x, 0);
			al_draw_line(x * MEASURE_WIDTH, 0, x * MEASURE_WIDTH, STAFF_HEIGHT * 6, color::brown, 1.0);
		}

		// draw a box under the focused measure
		if (get_hovered_measure())
			al_draw_filled_rounded_rectangle(measure_cursor_x*MEASURE_WIDTH, measure_cursor_y*STAFF_HEIGHT, 
				measure_cursor_x*MEASURE_WIDTH+MEASURE_WIDTH, measure_cursor_y*STAFF_HEIGHT+STAFF_HEIGHT,
				4, 4, color::color(color::aliceblue, 0.2));
		
		// draw the notes and measures
		Note *hovered_note = get_hovered_note();

		for (int y=0; y<NUM_Y_MEASURES; y++)
			for (int x=0; x<NUM_X_MEASURES; x++)
			{
				Measure *measure = &measure_grid.get_measure(x,y);
				music_engraver.draw(measure, x*MEASURE_WIDTH, y*STAFF_HEIGHT + STAFF_HEIGHT/2, MEASURE_WIDTH);

				// draw the notes
				float x_cursor = 0;
				for (unsigned i=0; i<measure->notes.size(); i++)
				{
					int xx = x * MEASURE_WIDTH;
					int yy = y * STAFF_HEIGHT;
					Note *note = measure->notes[i];
					float width = note->get_duration_width() * MEASURE_WIDTH;

					al_draw_filled_rounded_rectangle(xx+x_cursor, yy, xx+x_cursor+width, yy+STAFF_HEIGHT,
						3, 3, color::color(color::pink, (note==hovered_note) ? 0.4 : 0.2));

					if (showing_debug_data)
					{
						// scale degree
						al_draw_text(text_font, color::white, xx+x_cursor, yy, 0, tostring(note->scale_degree).c_str());
						// duration
						al_draw_text(text_font, color::white, xx+x_cursor, yy+20, 0, tostring(note->duration).c_str());
					}

					x_cursor += width;
				}
			}

		camera.restore_transform();
	}
	Measure *get_hovered_measure()
	{
		if (!FGUIParent::focused) return NULL;

		if (measure_cursor_x < 0 || measure_cursor_x >= NUM_X_MEASURES) return NULL;
		if (measure_cursor_y < 0 || measure_cursor_y >= NUM_Y_MEASURES) return NULL;

		return &measure_grid.get_measure(measure_cursor_x, measure_cursor_y);
	}
	Note *get_hovered_note()
	{
		Measure *focused_measure = get_hovered_measure();
		if (!focused_measure) return NULL;

		float local_cursor_x = cursor_x - measure_cursor_x * MEASURE_WIDTH;

		float width_traversed = 0;
		for (unsigned i=0; i<focused_measure->notes.size(); i++)
		{
			width_traversed += focused_measure->notes[i]->get_duration_width() * MEASURE_WIDTH;
			if (local_cursor_x < width_traversed) return focused_measure->notes[i];
		}
		return NULL;
	}
	void on_click() override
	{
		if (!FGUIParent::focused) return;

		// append a note into the focused measure

		if (af::current_event->mouse.button == 1)
		{
			Measure *focused_measure = get_hovered_measure();
			if (focused_measure) focused_measure->notes.push_back(new Note());
		}
	}
	void on_mouse_move(float x, float y, float dx, float dy) override
	{
		if (!FGUIParent::focused) return;

		cursor_x = x;
		cursor_y = y;

		place.transform_coordinates(&cursor_x, &cursor_y);
		camera.transform_coordinates(&cursor_x, &cursor_y);

		measure_cursor_x = cursor_x / MEASURE_WIDTH;
		measure_cursor_y = cursor_y / STAFF_HEIGHT;

		// do a bounds check on the board & hovered measure
		if (measure_cursor_x < 0 || measure_cursor_y < 0
			|| measure_cursor_x >= this->measure_grid.get_num_measures()
			|| measure_cursor_y >= this->measure_grid.get_num_staves())
			measure_cursor_x = measure_cursor_y = -1;
	}
	void on_key_down() override
	{
		if (!FGUIParent::focused) return;

		Motion &motion = *gimmie_motion();

		switch(af::current_event->keyboard.keycode)
		{
		case ALLEGRO_KEY_W:
			{
				Note *focused_note = get_hovered_note();
				if (!focused_note) break;
				focused_note->scale_degree++;
			}
			break;
		case ALLEGRO_KEY_S:
			{
				Note *focused_note = get_hovered_note();
				if (!focused_note) break;
				focused_note->scale_degree--;
			}
			break;
		case ALLEGRO_KEY_A:
			{
				Note *focused_note = get_hovered_note();
				if (!focused_note) break;
				focused_note->duration *= 2;
				focused_note->duration = limit<int>(1, 64, focused_note->duration);
			}
			break;
		case ALLEGRO_KEY_D:
			{
				Note *focused_note = get_hovered_note();
				if (!focused_note) break;
				focused_note->duration /= 2;
				focused_note->duration = limit<int>(1, 64, focused_note->duration);
			}
			break;
		case ALLEGRO_KEY_R:
			{
				Note *focused_note = get_hovered_note();
				if (!focused_note) break;
				focused_note->is_rest = !focused_note->is_rest;
			}
			break;
		case ALLEGRO_KEY_E:
				// erase the focused note
			{
				Measure *focused_measure = get_hovered_measure();
				if (!focused_measure) break;

				Note *focused_note = get_hovered_note();
				if (!focused_note) break;
				
				for (unsigned i=0; i<focused_measure->notes.size(); i++)
					if (focused_measure->notes[i]==focused_note)
					{
						delete focused_note;
						focused_measure->notes.erase(focused_measure->notes.begin() + i);
						i--;
					}
			}
			break;

		// some basic camera controls

		case ALLEGRO_KEY_UP:
			{
				motion.cmove(&camera.position.y, 200, 0.4);
			}
			break;
		case ALLEGRO_KEY_DOWN:
			{
				motion.cmove(&camera.position.y, -200, 0.4);
			}
			break;
		case ALLEGRO_KEY_RIGHT:
			{
				motion.cmove(&camera.position.x, -200, 0.4);
			}
			break;
		case ALLEGRO_KEY_LEFT:
			{
				motion.cmove(&camera.position.x, 200, 0.4);
			}
			break;
		case ALLEGRO_KEY_EQUALS:
			{
				if (af::key_shift)
				{
					motion.cmove_to(&camera.scale.x, 1, 0.3);
					motion.cmove_to(&camera.scale.y, 1, 0.3);
				}
				else
				{
					motion.cmove(&camera.scale.x, 0.1, 0.4);
					motion.cmove(&camera.scale.y, 0.1, 0.4);
				}
			}
			break;
		case ALLEGRO_KEY_MINUS:
			{
				motion.cmove(&camera.scale.x, -0.1, 0.4);
				motion.cmove(&camera.scale.y, -0.1, 0.4);
			}
			break;
		default:
			break;
		}
	}
};





class Project : public FGUIScreen
{
public:
	GUIScoreEditor *score_editor;
	FGUIWindow *help_window;
	bool showing_help_menu;

	Project(Display *display)
		: FGUIScreen(display)
		, score_editor(NULL)
		, help_window(NULL)
		, showing_help_menu(true)
	{
		FGUIScreen::draw_focused_outline = true;
		FGUIScreen::clear_to_background_color = false;

		score_editor = new GUIScoreEditor(this, display);

		create_help_window();
	}
	void create_help_window()
	{
		float x = 100;
		float y = 100;

		help_window = new FGUIWindow(this, display->center(), display->middle(), 550, 600);

		FGUIText *help_title = new FGUIText(help_window, 25, 25, fonts["DroidSans.ttf 34"], "Controls");
		FGUITextBox *help_paragraph = new FGUITextBox(help_window, fonts["DroidSans.ttf 20"], php::file_get_contents("data/documents/help.txt"), 25, 25+50, 500, 500);

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
					motion.cmove_to(&help_window->place.position.x, -600, 0.4);
					motion.cmove_to(&help_window->place.position.y, -100, 0.4);
					motion.cmove_to(&help_window->place.rotation, -0.1, 0.4);
					showing_help_menu = false;
				}
				else
				{
					// show the help menu
					motion.cmove_to(&help_window->place.position.x, display->center(), 0.4);
					motion.cmove_to(&help_window->place.position.y, display->middle(), 0.4);
					motion.cmove_to(&help_window->place.rotation, 0, 0.4);
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
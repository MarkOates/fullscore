#include <allegro_flare/allegro_flare.h>
#include <flare_gui/flare_gui.h>



#include <fullscore/measure.h>
#include <fullscore/note.h>
#include <fullscore/globals.h>
#include <fullscore/measure_grid.h>
#include <fullscore/music_engraver.h>



class Project : public Screen
{
public:
	MeasureGrid measure_grid;

	int measure_cursor_x;
	int measure_cursor_y;
	float cursor_x;
	float cursor_y;

	int type_cursor_pos;

	FontBin fonts;
	ALLEGRO_FONT *text_font;

	placement2d camera;
	Motion motion;

	MusicEngraver music_engraver;

	Project(Display *display)
		: Screen(display)
		, measure_grid(20, 6)
		, measure_cursor_x(-1)
		, measure_cursor_y(-1)
		, cursor_x(0)
		, cursor_y(0)
		, fonts("data/fonts")
		, text_font(fonts["DroidSans.ttf 20"])
		, type_cursor_pos(0) // << YOU WERE HERE :)
		, camera(display->width()/2, display->height()/2, display->width(), display->height())
		, motion()
		, music_engraver()
	{
		measure_grid.get_measure(3,2).notes.push_back(new Note());
		measure_grid.get_measure(3,2).notes.push_back(new Note());
		measure_grid.get_measure(1,3).notes.push_back(new Note());
	}
	void primary_timer_func() override
	{
		motion.update(af::time_now);
		camera.start_transform();

		// draw a background for the score
		al_draw_filled_rectangle(-30, -30, MEASURE_WIDTH * 20 + 30, STAFF_HEIGHT * 6 + 30, color::color(color::blanchedalmond, 0.2));
		
		// draw barlines
		for (int x=0; x<NUM_X_MEASURES; x++)
		{
			Measure *measure = &measure_grid.get_measure(x, 0);
			al_draw_line(x * MEASURE_WIDTH, 0, x * MEASURE_WIDTH, STAFF_HEIGHT * 6, color::brown, 1.0);
		}

		for (int y=0; y<NUM_Y_MEASURES; y++)
			for (int x=0; x<NUM_X_MEASURES; x++)
			{
				Measure *measure = &measure_grid.get_measure(x,y);
				measure->draw(x*MEASURE_WIDTH, y*STAFF_HEIGHT, text_font);
				music_engraver.draw(measure, x*MEASURE_WIDTH, y*STAFF_HEIGHT + STAFF_HEIGHT/2);
			}

		al_draw_rectangle(measure_cursor_x*MEASURE_WIDTH, measure_cursor_y*STAFF_HEIGHT, 
			measure_cursor_x*MEASURE_WIDTH+MEASURE_WIDTH, measure_cursor_y*STAFF_HEIGHT+STAFF_HEIGHT, color::avajowhite, 2.0);
		
		camera.restore_transform();
	}
	Measure *get_focused_measure()
	{
		if (measure_cursor_x < 0 || measure_cursor_x >= NUM_X_MEASURES) return NULL;
		if (measure_cursor_y < 0 || measure_cursor_y >= NUM_Y_MEASURES) return NULL;

		return &measure_grid.get_measure(measure_cursor_x, measure_cursor_y);
	}
	Note *get_focused_note()
	{
		Measure *focused_measure = get_focused_measure();
		if (!focused_measure) return NULL;

		float local_cursor_x = cursor_x - measure_cursor_x * MEASURE_WIDTH;

		float width_traversed = 0;
		for (unsigned i=0; i<focused_measure->notes.size(); i++)
		{
			width_traversed += focused_measure->notes[i]->get_width();
			if (local_cursor_x < width_traversed) return focused_measure->notes[i];
		}
		return NULL;
	}
	void mouse_down_func() override
	{
		Measure *focused_measure = get_focused_measure();
		if (!focused_measure) return;

		focused_measure->notes.push_back(new Note());
	}
	void mouse_axes_func() override
	{
		cursor_x = af::current_event->mouse.x;
		cursor_y = af::current_event->mouse.y;

		camera.transform_coordinates(&cursor_x, &cursor_y);

		measure_cursor_x = cursor_x / MEASURE_WIDTH;
		measure_cursor_y = cursor_y / STAFF_HEIGHT;
	}
	void key_down_func() override
	{
		switch(af::current_event->keyboard.keycode)
		{
		case ALLEGRO_KEY_W:
			{
				Note *focused_note = get_focused_note();
				if (!focused_note) break;
				focused_note->scale_degree++;
			}
			break;
		case ALLEGRO_KEY_S:
			{
				Note *focused_note = get_focused_note();
				if (!focused_note) break;
				focused_note->scale_degree--;
			}
			break;
		case ALLEGRO_KEY_A:
			{
				Note *focused_note = get_focused_note();
				if (!focused_note) break;
				focused_note->duration *= 2;
				focused_note->duration = limit<int>(1, 64, focused_note->duration);
			}
			break;
		case ALLEGRO_KEY_D:
			{
				Note *focused_note = get_focused_note();
				if (!focused_note) break;
				focused_note->duration /= 2;
				focused_note->duration = limit<int>(1, 64, focused_note->duration);
			}
			break;
		case ALLEGRO_KEY_E:
				// erase the focused note
			{
				Measure *focused_measure = get_focused_measure();
				if (!focused_measure) break;

				Note *focused_note = get_focused_note();
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





int main(int argc, char *argv[])
{
	af::initialize();
	Display *d = af::create_display(1600, 800);
	Project *proj = new Project(d);
	af::run_loop();
}
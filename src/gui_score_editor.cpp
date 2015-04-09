




#include <fullscore/gui_score_editor.h>

#include <allegro_flare/allegro_flare.h>

#include <flare_gui/collision_box.h>







GUIScoreEditor::GUIScoreEditor(FGUIParent *parent, Display *display, PlaybackDeviceInterface *playback_device)
	// the widget is placed in the center of the screen with a padding of 10 pixels to the x and y edges
	: FGUIParent(parent,
		new FGUICollisionBox(display->center(), display->middle(), display->width()-20, display->height()-20))
	, measure_grid(20, 3)
	, playback_control(&measure_grid, playback_device)
	, measure_cursor_x(-1)
	, measure_cursor_y(-1)
	, cursor_x(0)
	, cursor_y(0)
	, camera(200, 200, 1, 1)
	, music_engraver()
	, showing_debug_data(false)
	, STAFF_HEIGHT(80)
	, MEASURE_WIDTH(music_engraver.music_notation.get_quarter_note_spacing()*4)
{
	attr.set(FGUI_ATTR__FGUI_WIDGET_TYPE, "GUIScoreEditor");
	attr.set("id", "GUIScoreEditor" + tostring(widget_count));

	// twinkle twinkle, little star
	measure_grid.get_measure(0,0)->notes.push_back(new Note(0));
	measure_grid.get_measure(0,0)->notes.push_back(new Note(0));
	measure_grid.get_measure(0,0)->notes.push_back(new Note(4));
	measure_grid.get_measure(0,0)->notes.push_back(new Note(4));
	measure_grid.get_measure(1,0)->notes.push_back(new Note(5));
	measure_grid.get_measure(1,0)->notes.push_back(new Note(5));
	measure_grid.get_measure(1,0)->notes.push_back(new Note(4, 2));

	measure_grid.get_measure(2,1)->notes.push_back(new Note(0));
	measure_grid.get_measure(2,1)->notes.push_back(new Note(0));
	measure_grid.get_measure(2,1)->notes.push_back(new Note(-1));
	measure_grid.get_measure(2,1)->notes.push_back(new Note(-1));
	measure_grid.get_measure(3,1)->notes.push_back(new Note(-2));
	measure_grid.get_measure(3,1)->notes.push_back(new Note(-2));
	measure_grid.get_measure(3,1)->notes.push_back(new Note(-3, 2));

	camera.align = vec2d(0, 0);
}




void GUIScoreEditor::on_draw()
{
	camera.start_transform();

	// draw a background for the score
	al_draw_filled_rectangle(-30, -30,
		MEASURE_WIDTH * measure_grid.get_num_measures() + 30, STAFF_HEIGHT * measure_grid.get_num_staves() + 30,
		color::color(color::blanchedalmond, 0.2));
		
	// draw barlines
	for (int x=0; x<measure_grid.get_num_measures(); x++)
	{
		Measure *measure = measure_grid.get_measure(x, 0);
		al_draw_line(x * MEASURE_WIDTH, 0, x * MEASURE_WIDTH, STAFF_HEIGHT * measure_grid.get_num_staves(), color::color(color::white, 0.2), 1.0);
	}

	// draw a box under the focused measure (if the alt key is pressed)
	if (af::key_alt)
		if (get_hovered_measure())
			al_draw_filled_rounded_rectangle(measure_cursor_x*MEASURE_WIDTH, measure_cursor_y*STAFF_HEIGHT, 
				measure_cursor_x*MEASURE_WIDTH+MEASURE_WIDTH, measure_cursor_y*STAFF_HEIGHT+STAFF_HEIGHT,
				4, 4, color::color(color::aliceblue, 0.2));

	// draw the notes and measures
	Note *hovered_note = get_hovered_note();

	for (int y=0; y<measure_grid.get_num_staves(); y++)
		for (int x=0; x<measure_grid.get_num_measures(); x++)
		{
			Measure *measure = measure_grid.get_measure(x,y);
			music_engraver.draw(measure, x*MEASURE_WIDTH, y*STAFF_HEIGHT + STAFF_HEIGHT/2, MEASURE_WIDTH);

			// draw the notes
			float x_cursor = 0;
			for (unsigned i=0; i<measure->notes.size(); i++)
			{
				int xx = x * MEASURE_WIDTH;
				int yy = y * STAFF_HEIGHT;
				Note *note = measure->notes[i];
				float width = note->get_duration_width() * MEASURE_WIDTH;

				// draw a hilight box under the focused note
				if (!af::key_alt && (note == hovered_note))
					al_draw_filled_rounded_rectangle(xx+x_cursor, yy, xx+x_cursor+width, yy+STAFF_HEIGHT,
							3, 3, color::color(color::pink, (note==hovered_note) ? 0.4 : 0.2));

				if (showing_debug_data)
				{
					ALLEGRO_FONT *text_font = af::fonts["DroidSans.ttf 20"];
					// scale degree
					al_draw_text(text_font, color::white, xx+x_cursor, yy, 0, tostring(note->scale_degree).c_str());
					// duration
					al_draw_text(text_font, color::white, xx+x_cursor, yy+20, 0, (tostring(note->duration) + "(" + tostring(note->dots) + ")").c_str());
					// start and end times
					al_draw_text(text_font, color::white, xx+x_cursor, yy+40, 0, tostring(note->start_time).c_str());
					al_draw_text(text_font, color::white, xx+x_cursor, yy+60, 0, tostring(note->end_time).c_str());
				}

				x_cursor += width;
			}
		}

	// draw the playhead
	float playhead_x = playback_control.position * MEASURE_WIDTH;
	al_draw_line(playhead_x, -40, playhead_x, STAFF_HEIGHT * measure_grid.get_num_staves() + 40, color::color(color::lightcyan, 0.5), 3);
	al_draw_filled_triangle(playhead_x-8, -48, playhead_x+8, -48, playhead_x, -40+6, color::lightcyan);
	al_draw_filled_rectangle(playhead_x-8, -48-14, playhead_x+8, -48, color::lightcyan);

	camera.restore_transform();
}




void GUIScoreEditor::on_timer()
{
	FGUIParent::on_timer();

	playback_control.update(af::time_now);
}




Measure *GUIScoreEditor::get_hovered_measure()
{
	if (!FGUIParent::focused) return NULL;

	if (measure_cursor_x < 0 || measure_cursor_x >= measure_grid.get_num_measures()) return NULL;
	if (measure_cursor_y < 0 || measure_cursor_y >= measure_grid.get_num_staves()) return NULL;

	return measure_grid.get_measure(measure_cursor_x, measure_cursor_y);
}




Note *GUIScoreEditor::get_hovered_note()
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




void GUIScoreEditor::on_click()
{
	if (!FGUIParent::focused) return;

	// append a note into the focused measure

	if (af::current_event->mouse.button == 1)
	{
		Measure *focused_measure = get_hovered_measure();
		if (focused_measure) focused_measure->notes.push_back(new Note());
	}
}




void GUIScoreEditor::on_mouse_move(float x, float y, float dx, float dy)
{
	if (!FGUIParent::focused) return;

	cursor_x = x;
	cursor_y = y;

	place.transform_coordinates(&cursor_x, &cursor_y);
	camera.transform_coordinates(&cursor_x, &cursor_y);

	measure_cursor_x = cursor_x / MEASURE_WIDTH;
	measure_cursor_y = cursor_y / STAFF_HEIGHT;

	// do a bounds check on the board & hovered measure
	if (cursor_x < 0 || cursor_y < 0
		|| measure_cursor_x >= this->measure_grid.get_num_measures()
		|| measure_cursor_y >= this->measure_grid.get_num_staves())
		measure_cursor_x = measure_cursor_y = -1;
}




void GUIScoreEditor::on_key_down()
{
	if (!FGUIParent::focused) return;

	switch(af::current_event->keyboard.keycode)
	{
	case ALLEGRO_KEY_W:
			// transpose up
		{
			if (af::key_alt)
			{
				// transpose the whole measure
				Measure *focused_measure = get_hovered_measure();
				if (!focused_measure) break;

				if (af::key_shift) focused_measure->transpose(7);
				else if (af::key_ctrl); // nothing (this add flats to the whole measure? .. probably not a feature to have)
				else focused_measure->transpose(1);
			}
			else
			{
				// transpose the focused note
				Note *focused_note = get_hovered_note();
				if (!focused_note) break;

				if (af::key_shift) focused_note->scale_degree += 7;
				else if (af::key_ctrl) focused_note->accidental = std::min(1, focused_note->accidental+1);
				else focused_note->scale_degree++;
			}
		}
		break;
	case ALLEGRO_KEY_S:
			// transpose down
		{
			if (af::key_alt)
			{
				// transposes the whole measure
				Measure *focused_measure = get_hovered_measure();
				if (!focused_measure) break;

				if (af::key_shift) focused_measure->transpose(-7);
				else if (af::key_ctrl); // nothing (this add flats to the whole measure? .. probably not a feature to have)
				else focused_measure->transpose(-1);
			}
			else
			{
				// transposes a single note
				Note *focused_note = get_hovered_note();
				if (!focused_note) break;

				if (af::key_shift) focused_note->scale_degree -= 7;
				else if (af::key_ctrl) focused_note->accidental = std::max(-1, focused_note->accidental-1);
				else focused_note->scale_degree--;
			}
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
	case ALLEGRO_KEY_I:
			// invert the measure
		{
			Measure *focused_measure = get_hovered_measure();
			if (!focused_measure) break;

			focused_measure->invert(0);
		}
		break;
	case ALLEGRO_KEY_P:
			// retrograde the measure
		{
			Measure *focused_measure = get_hovered_measure();
			if (!focused_measure) break;

			focused_measure->retrograde();
		}
		break;
	case ALLEGRO_KEY_FULLSTOP:
			// add a dot
		{
			Note *focused_note = get_hovered_note();
			if (!focused_note) break;
			focused_note->dots = std::min(2, focused_note->dots+1);
		}
		break;
	case ALLEGRO_KEY_COMMA:
			// remove a dot
		{
			Note *focused_note = get_hovered_note();
			if (!focused_note) break;
			focused_note->dots = std::max(0, focused_note->dots-1);
		}
		break;

	// some basic camera controls

	case ALLEGRO_KEY_UP:
		{
			af::motion.cmove(&camera.position.y, 200, 0.4);
		}
		break;
	case ALLEGRO_KEY_DOWN:
		{
			af::motion.cmove(&camera.position.y, -200, 0.4);
		}
		break;
	case ALLEGRO_KEY_RIGHT:
		{
			af::motion.cmove(&camera.position.x, -200, 0.4);
		}
		break;
	case ALLEGRO_KEY_LEFT:
		{
			af::motion.cmove(&camera.position.x, 200, 0.4);
		}
		break;
	case ALLEGRO_KEY_EQUALS:
		{
			if (af::key_shift)
			{
				af::motion.cmove_to(&camera.scale.x, 1, 0.3);
				af::motion.cmove_to(&camera.scale.y, 1, 0.3);
			}
			else
			{
				af::motion.cmove(&camera.scale.x, 0.1, 0.4);
				af::motion.cmove(&camera.scale.y, 0.1, 0.4);
			}
		}
		break;
	case ALLEGRO_KEY_MINUS:
		{
			af::motion.cmove(&camera.scale.x, -0.1, 0.4);
			af::motion.cmove(&camera.scale.y, -0.1, 0.4);
		}
		break;
	default:
		break;
	}
}

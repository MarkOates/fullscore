



#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <allegro_flare/useful.h>

#include <fullscore/measure.h>
#include <fullscore/note.h>
#include <fullscore/globals.h>


void Measure::draw(float x, float y, ALLEGRO_FONT *font)
{
	if (notes.empty()) return;

	float x_cursor = 0;
	for (unsigned i=0; i<notes.size(); i++)
	{
		float width = notes[i]->get_width();

		al_draw_rectangle(x+x_cursor, y, x+x_cursor+width, y+STAFF_HEIGHT, color::pink, 2);
		// scale degree
		al_draw_text(font, color::white, x+x_cursor, y, 0, tostring(notes[i]->scale_degree).c_str());
		// duration
		al_draw_text(font, color::white, x+x_cursor, y+20, 0, tostring(notes[i]->duration).c_str());

		x_cursor += width;
	}
}


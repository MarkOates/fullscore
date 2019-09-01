

#include <fullscore/FrontEnd.hpp>



namespace fullscore
{


FrontEnd::FrontEnd(Display* display)
   : UIScreen(display)
   , display(display)
{
}


FrontEnd::~FrontEnd()
{
}


void FrontEnd::on_draw()
{
static placement2d place;
place.rotation = place.rotation += 0.01;
place.start_transform();
al_draw_filled_rectangle(300, 400, 900, 1200, al_color_name("green"));
place.restore_transform();
return;

}
} // namespace fullscore





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
al_draw_filled_rectangle(300, 400, 900, 1200, al_color_name("green"));
return;

}
} // namespace fullscore





#include <fullscore/UI/PlotterEditor/Widget.hpp>

#include <fullscore/UI/PlotterEditor/Actions.hpp>
#include <allegro_flare/allegro_flare.h>


namespace UI::PlotterEditor
{


Widget::Widget(UIWidget *parent)
   : UIWidget(parent, "PlotterEditor", new UISurfaceAreaBoxPadded(0, 0, 300, 200, 30, 30, 30, 30))
{
   _set_keyboard_mappings();
}


void Widget::_set_keyboard_mappings()
{
   keyboard_commands.set_mapping(ALLEGRO_KEY_H, false, false, false, {Actions::SAY_HELLO_ACTION_IDENTIFIER});
}


std::vector<std::string> Widget::get_keyboard_action_mapping(int al_keycode, bool shift, bool ctrl, bool alt)
{
   return {};
}


} // namespace UI::PlotterEditor



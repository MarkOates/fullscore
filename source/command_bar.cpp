



#include <fullscore/command_bar.h>




UICommandBar::UICommandBar(UIWidget *parent)
   : UIWidget(parent, "UICommandBar", new UISurfaceAreaBox(0, parent->place.size.y-66, parent->place.size.x, 66))
{
   this->place.align = {0.0, 0.0};

   text_input = new UITextInput(this, 10, 10, 800, 40);
   text_input->place.align = {0, 0};
}




void UICommandBar::on_draw()
{
   UIStyleAssets::draw_outset(0, 0, place.size.x, place.size.y);
}




void UICommandBar::on_message(UIWidget *sender, std::string message)
{
   // right now... the message is just being passed up to the next widget
   // there is certainly a better way to do this (*cough* signals and slots)
   send_message_to_parent(message, sender);
}




void UICommandBar::on_key_down()
{
   switch (Framework::current_event->keyboard.keycode)
   {
   case ALLEGRO_KEY_ENTER:
      send_message_to_parent(text_input->get_text(), this);
      text_input->set_text("");
      break;
   default:
      break;
   }
}





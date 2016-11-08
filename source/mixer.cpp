



#include <fullscore/mixer.h>




UIMixer::Channel::Channel(int channel_num, int patch)
   : channel_num(channel_num)
   , patch(patch)
{}




// GUIPatchTextInput




UIMixer::GUIPatchTextInput::GUIPatchTextInput(UIWidget *parent, int channel_num, float x, float y)
   : UITextInput(parent, x, y, 50, 30, "0")
   , channel_num(channel_num)
{}




void UIMixer::GUIPatchTextInput::on_change()
{
   UIMixer *mixer = static_cast<UIMixer *>(UIWidget::family.parent);
   mixer->channels[channel_num].patch = atoi(get_text().c_str());
}




// UIMixer




UIMixer::UIMixer(UIWidget *parent, float x_, float y_, int num_channels)
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




UIMixer::Channel *UIMixer::get_channel(int channel_num)
{
   if (channels.empty() || channel_num < 0 || channel_num >= channels.size()) return NULL;
   return &channels[channel_num];
}




int UIMixer::get_patch_num(int channel_num)
{
   if (channels.empty() || channel_num < 0 || channel_num >= channels.size()) return 0;
   return channels[channel_num].patch;
}






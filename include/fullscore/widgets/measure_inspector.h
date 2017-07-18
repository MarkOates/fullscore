#pragma once



#include <allegro_flare/gui/widget.h>
#include <fullscore/models/measures/base.h>



class UIMeasureInspector : public UIWidget
{
private:
   Measure::Base *measure;
   std::string _get_measure_string();

public:
   UIMeasureInspector(UIWidget *parent);

   void set_measure(Measure::Base *measure);
   Measure::Base *get_measure();

   virtual void on_draw();
};




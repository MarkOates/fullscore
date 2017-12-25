



#include <fullscore/helpers/DurationHelper.h>

#include <fullscore/models/TimeSignature.h>




float DurationHelper::get_length(int duration, int dots)
{
   float width = 1.0f / duration;
   float dots_percentage = 0.0f;
   float previous_ammount = 1.0f;
   for (int i=0; i<dots; i++)
   {
      previous_ammount *= 0.5f;
      dots_percentage += previous_ammount;
   }

   return width + width * dots_percentage;
}




float DurationHelper::get_length(const TimeSignature &time_signature)
{
   float denominator_duration_width = get_length(time_signature.get_denominator().get_denominator(), time_signature.get_denominator().get_dots());
   return denominator_duration_width * time_signature.get_numerator();
}





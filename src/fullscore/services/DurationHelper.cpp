



#include <fullscore/services/DurationHelper.hpp>

#include <fullscore/models/TimeSignature.hpp>




float DurationHelper::get_length(Duration duration)
{
   float width = 1.0f / duration.get_denominator();
   float dots_percentage = 0.0f;
   float previous_ammount = 1.0f;
   for (int i=0; i<duration.get_dots(); i++)
   {
      previous_ammount *= 0.5f;
      dots_percentage += previous_ammount;
   }

   return width + width * dots_percentage;
}




float DurationHelper::get_length(const TimeSignature &time_signature)
{
   float denominator_duration_width = get_length(time_signature.get_denominator());
   return denominator_duration_width * time_signature.get_numerator();
}




Duration::denominator_t DurationHelper::half_duration(Duration::denominator_t denominator)
{
   if (denominator >= Duration::SIXTYFOURTH) return Duration::SIXTYFOURTH;
   return (Duration::denominator_t)((int)denominator * 2);
}



Duration::denominator_t DurationHelper::double_duration(Duration::denominator_t denominator)
{
   if (denominator <= Duration::WHOLE) return Duration::WHOLE;
   return (Duration::denominator_t)((int)denominator / 2);
}




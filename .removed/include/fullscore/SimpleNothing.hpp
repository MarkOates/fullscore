#pragma once


#include <fullscore/Cursor.hpp>


namespace fullscore
{
   class SimpleNothing
   {
   private:
      fullscore::Cursor cursor;

   public:
      SimpleNothing();
      ~SimpleNothing();

      void set_cursor(fullscore::Cursor cursor);

      fullscore::Cursor get_cursor();
   void output_message();
   };
}




#pragma once




namespace fullscore
{
   class Cursor
   {
   private:
      int x;
      int y;

   public:
      Cursor();
      ~Cursor();

      void set_x(int x);
      void set_y(int y);

      int get_x();
      int get_y();
   };
}




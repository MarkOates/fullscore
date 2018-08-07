#pragma once


namespace UI::AppNavigator { class Widget; }


namespace UI::AppNavigator::RenderComponents
{
   class Widget
   {
   private:
      UI::AppNavigator::Widget *widget;

   public:
      Widget(UI::AppNavigator::Widget *widget);
      ~Widget();

      void render();
   };
}



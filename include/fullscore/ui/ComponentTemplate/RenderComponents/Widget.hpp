#pragma once


namespace UI::ComponentTemplate { class Widget; }


namespace UI::ComponentTemplate::RenderComponents
{
   class Widget
   {
   private:
      UI::ComponentTemplate::Widget *widget;

   public:
      Widget(UI::ComponentTemplate::Widget *widget);
      ~Widget();

      void render();
   };
}



#pragma once


namespace UI::PlotterEditor { class Widget; }


namespace UI::PlotterEditor::RenderComponents
{
   class Widget
   {
   private:
      UI::PlotterEditor::Widget *widget;

   public:
      Widget(UI::PlotterEditor::Widget *widget=nullptr);
      ~Widget();

      void render();
   };
}



#pragma once


#include <fullscore/UI/GridEditor/Widget.hpp>


namespace UI::GridEditor::RenderComponents
{
   class UIGridEditorRenderComponent
   {
   private:
      ::UI::GridEditor::Widget &ui_grid_editor;

   public:
      UIGridEditorRenderComponent(::UI::GridEditor::Widget &ui_grid_editor);
      ~UIGridEditorRenderComponent();

      void render();
   };
} // namespace UI::GridEditor::RenderComponents



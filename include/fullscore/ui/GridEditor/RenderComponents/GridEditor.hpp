#pragma once


#include <fullscore/UI/GridEditor/Widget.hpp>


namespace UI::GridEditor::RenderComponents
{
   class GridEditor
   {
   private:
      ::UI::GridEditor::Widget &grid_editor;

   public:
      GridEditor(::UI::GridEditor::Widget &grid_editor);
      ~GridEditor();

      void render();
   };
} // namespace UI::GridEditor::RenderComponents



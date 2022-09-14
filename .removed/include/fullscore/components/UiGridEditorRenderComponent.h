#pragma once



#include <fullscore/widgets/GridEditor.hpp>



class UIGridEditorRenderComponent
{
private:
   UIGridEditor &ui_grid_editor;

public:
   UIGridEditorRenderComponent(UIGridEditor &ui_grid_editor);
   ~UIGridEditorRenderComponent();

   void render();
};




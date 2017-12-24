#pragma once



#include <fullscore/widgets/GridEditor.h>



class UIGridEditorRenderComponent
{
private:
   UIGridEditor &ui_grid_editor;

public:
   UIGridEditorRenderComponent(UIGridEditor &ui_grid_editor);
   ~UIGridEditorRenderComponent();

   void render();
};




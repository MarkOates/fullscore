#pragma once



#include <fullscore/widgets/grid_editor.h>



class UIGridEditorRenderComponent
{
private:
   UIGridEditor &ui_grid_editor;

public:
   UIGridEditorRenderComponent(UIGridEditor &ui_grid_editor);
   ~UIGridEditorRenderComponent();

   void render();
};




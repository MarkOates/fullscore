#pragma once



#include <fullscore/actions/action_base.h>



class AppController;
class UIMeasureGridEditor;

namespace Action
{
   class SetCurrentUIMeasureGridEditor : public Base
   {
   private:
      AppController *app_controller;
      UIMeasureGridEditor *measure_grid_editor;

   public:
      SetCurrentUIMeasureGridEditor(AppController *app_controller, UIMeasureGridEditor *measure_grid_editor);
      ~SetCurrentUIMeasureGridEditor();

      bool execute() override;
   };
};





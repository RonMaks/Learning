#include "MainScreenController.h"

MainScreenController::MainScreenController(MainScreenModel* model) : _model(model)
{

}

void MainScreenController::start() {
  if (_kbhit()) {
      _model->FillLines(_getch());
  }
}

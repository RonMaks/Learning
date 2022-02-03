#include "MainScreenView.h"

MainScreenView::MainScreenView(MainScreenModel* model) : _model(model) {
  _model->addSubscriber(this);
}

void MainScreenView::draw() {
  COORD coord = {0, 0};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
  BoardView view(&_model->GetBoard());
  view.draw();
  cout << "    __Score__" << endl;
  cout << "White: " << _model->GetWhiteScore() << "  ";
  cout << "Black: " << _model->GetBlackScore() << endl << endl;
  cout << "  __" << _model->GetCurrentPlayer() << " move__" << endl;
  cout << "From: ";
  cout << _model->GetCurrentLine1() << _model->GetCurrentLine2() << "    " << endl;
}

void MainScreenView::onUpdate(Publisher* o) {
  _model = static_cast<MainScreenModel*>(o);
}

#include "BoardView.h"

BoardView::BoardView(Board* model) : _model(model)
{
  _model->addSubscriber(this);
}

void BoardView::draw() {
  cout << "        __Board__" << endl << " ";
  for (size_t i = 0; i < _model->GetBoardSize(); i++) {
    cout << i << "  ";
  }
  cout << endl;
  for (size_t i = 0; i < _model->GetBoardSize(); i++) {
    for (size_t j = 0; j < _model->GetBoardSize(); j++) {
      Figure figureType(_model->GetMap().at(pair<size_t, size_t>(i, j)));
      FigureView* cellview = new FigureView(&figureType);
      cellview->draw();
    }
    cout << " " << i << endl;
  }
  cout << endl;
}

void BoardView::onUpdate(Publisher* o) {
  _model = static_cast<Board*>(o);
}

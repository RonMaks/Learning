#include "FigureView.h"

FigureView::FigureView(Figure* model) : _model(model) {
  _model->addSubscriber(this);
}

void FigureView::draw() {
  cout << "(";
  cout << _model->DrawColorType();
  cout << ")";
}

void FigureView::onUpdate(Publisher* o) {
  _model = static_cast<Figure*>(o);
}

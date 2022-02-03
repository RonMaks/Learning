#pragma once

#include "Board.h"
#include "../../common/IView.h"
#include "../../ui/Figure/FigureView.h"
#include "../../common/Subscriber.h"
#include "../../common/Publisher.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class BoardView: public IView {
public:
  BoardView(Board* model);
  virtual void draw();
  virtual void onUpdate(Publisher* o);
private:
  Board* _model;
};

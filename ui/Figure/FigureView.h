#pragma once

#include "Figure.h"
#include "../../common/IView.h"
#include "../../common/Subscriber.h"
#include "../../common/Publisher.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class FigureView: public IView {
public:
  FigureView(Figure* model);
  virtual void draw();
  virtual void onUpdate(Publisher* o);
private:
  Figure* _model;
};

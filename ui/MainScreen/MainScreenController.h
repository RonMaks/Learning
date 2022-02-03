#pragma once

#include "../../common/IController.h"
#include "../../store/Store.h"
#include "MainScreenModel.h"
#include "../Figure/Figure.h"
#include "../Board/Board.h"

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <cmath>
#include <algorithm>

class MainScreenController : public IController
{
public:
  MainScreenController(MainScreenModel* model);
  void start();

private:
  MainScreenModel* _model;
};

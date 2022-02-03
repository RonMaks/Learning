#pragma once

#define STD_OUTPUT_HANDLE (DWORD)(0xfffffff5)

#include "MainScreenModel.h"
#include "../../store/Store.h"
#include "../../common/Subscriber.h"
#include "../../common/Publisher.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <windows.h>
using namespace std;

double fps = 15;
double MS_PER_FRAME = 1000 / fps;

class MainScreenView: public IView {
public:
   MainScreenView(MainScreenModel* model);
   virtual void draw();
   virtual void onUpdate(Publisher* o);
private:
   MainScreenModel* _model;
};

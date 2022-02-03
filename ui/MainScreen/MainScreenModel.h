#pragma once

#include "../../common/IModel.h"
#include "../Figure/Figure.h"
#include "../../store/Store.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class MainScreenModel : public IModel {
public:
   MainScreenModel(Store* model);
   void update();
   Board& GetBoard();
   size_t GetWhiteScore();
   size_t GetBlackScore();
   string GetCurrentPlayer() const;
   Store::Player GetWinner() const;
   bool GetDirection() const;
   pair<pair<size_t, size_t>, pair<size_t, size_t>> GetMove();
   void UpdateScore();
   void SwitchPlayer();
   string CastPlayer(Store::Player player) const;
   void FillLines(char c);
   bool CheckLines();
   string GetCurrentLine1() const;
   string GetCurrentLine2() const;
private:
   Store* _model;
};

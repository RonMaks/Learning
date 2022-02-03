#pragma once

#include "../Figure/Figure.h"
#include "../../common/IModel.h"
#include "../../ui/Figure/FigureView.h"

#include <map>
using namespace std;

class Board : public IModel {
public:
  enum class MoveResult { GOOD_MOVE, GOOD_FIGHT, BAD_MOVE, END };
  Board();
  void FillMap();
  MoveResult CheckMove(const pair<size_t, size_t>& startPos, const pair<size_t, size_t>& endPos, bool direction);
  MoveResult MakeMove(const pair<size_t, size_t>& startPos, const pair<size_t, size_t>& endPos, bool direction, bool forceCombat = false);
  map<pair<size_t, size_t>, Figure>& GetMap();
  void update();
  size_t GetBoardSize();
private:
  size_t BoardSize;
  map<pair<size_t, size_t>, Figure> BoardMap;
};

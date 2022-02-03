#pragma once

#include "../ui/Board/Board.h"
#include "../ui/Board/BoardView.h"

class Store {
public:
  Store();
  enum class Player { BLACK, WHITE, NONE };
  Board board;
  BoardView* v;
  size_t WhiteScore;
  size_t BlackScore;
  Player LastPlayer;
  std::string line1;
  std::string line2;
};

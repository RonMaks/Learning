#include "Store.h"

Store::Store() : WhiteScore(0), BlackScore(0), LastPlayer(Player::NONE) {
  board.FillMap();
  v = new BoardView(&board);
  line1 = "";
  line2 = "";
}

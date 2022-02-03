#include "store/Store.h"
#include "store/Store.cpp"
#include "ui/MainScreen/MainScreenModel.h"
#include "ui/MainScreen/MainScreenModel.cpp"
#include "ui/MainScreen/MainScreenView.h"
#include "ui/MainScreen/MainScreenView.cpp"
#include "ui/Figure/FigureView.h"
#include "ui/MainScreen/MainScreenController.h"
#include "ui/MainScreen/MainScreenController.cpp"
#include "ui/Board/BoardView.cpp"
#include "ui/Board/Board.cpp"
#include "ui/Figure/FigureView.cpp"
#include "ui/Figure/Figure.cpp"

#include <iostream>
#include <iomanip>
#include <ctime>
#include "windows.h"

int main() {
  Store store;
  MainScreenModel model(&store);
  MainScreenView view(&model);
  MainScreenController controller(&model);
  while (model.GetWinner() == Store::Player::NONE) {
    double start = clock();
    controller.start();
    model.notifyUpdate();
    view.draw();
    Board::MoveResult moveResult(Board::MoveResult::BAD_MOVE);
    bool direction = model.GetDirection();
    if (model.CheckLines()) {
        auto newMove = std::move(model.GetMove());
        moveResult = model.GetBoard().MakeMove(newMove.first, newMove.second, direction);
    }
    if (moveResult == Board::MoveResult::GOOD_FIGHT) {
        model.UpdateScore();
    }
    if (moveResult == Board::MoveResult::GOOD_MOVE) {
        model.SwitchPlayer();
    }
    if (clock() - start < MS_PER_FRAME) {
        Sleep(((double)MS_PER_FRAME + start - clock()));
    }
  }
  return 0;
}

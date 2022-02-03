#include "Board.h"

Board::Board() : BoardSize(8) {
}

void Board::FillMap() {
  for (size_t i = 0; i < BoardSize; i++) {
    for (size_t j = 0; j < BoardSize; j++) {
      Figure::ColorType state(Figure::ColorType::NONE);
      if (i == 0 && j % 2 != 0) {
        state = Figure::ColorType::WHITE;
      }
      else if (i == 1 && j % 2 == 0) {
        state = Figure::ColorType::WHITE;
      }
      else if (i == 2 && j % 2 != 0) {
        state = Figure::ColorType::WHITE;
      }
      else if (i == 5 && j % 2 == 0) {
        state = Figure::ColorType::BLACK;
      }
      else if (i == 6 && j % 2 != 0) {
        state = Figure::ColorType::BLACK;
      }
      else if (i == 7 && j % 2 == 0) {
        state = Figure::ColorType::BLACK;
      }
      const pair<size_t, size_t> position = pair<size_t, size_t>(i, j);
      Figure cell = Figure(state);
      BoardMap.insert({ move(position), move(cell) });
    }
  }
}

Board::MoveResult Board::CheckMove(const pair<size_t, size_t>& startPos, const pair<size_t, size_t>& endPos, bool direction) {
  Board::MoveResult result = Board::MoveResult::BAD_MOVE;
  const int dY = endPos.first - startPos.first;
  const int dX = endPos.second - startPos.second;
  if (dX == 0 && dY == 0 && endPos.first == 0 && endPos.second == 0) {
    result = Board::MoveResult::END;
  }
  else if (endPos.first >= 0 && endPos.first < BoardSize && endPos.second >= 0 && endPos.second < BoardSize) {
    auto targetCellState = BoardMap.at(endPos).GetColorType();
    if (targetCellState == Figure::ColorType::NONE) {
      if (abs(dX) == 2 && abs(dY) == 2) {
        pair<size_t, size_t> victimPos((startPos.first + endPos.first) / 2, (startPos.second + endPos.second) / 2);
        auto victimCellState = BoardMap.at(victimPos).GetColorType();
        auto startCellState = BoardMap.at(startPos).GetColorType();
        result = targetCellState != victimCellState && startCellState != victimCellState ? Board::MoveResult::GOOD_FIGHT : result;
      }
      else if ((abs(dX) == 1 && dY == 1 && direction) || (abs(dX) == 1 && dY == -1 && !direction)) {
        result = Board::MoveResult::GOOD_MOVE;
      }
    }
  }
  return result;
}

Board::MoveResult Board::MakeMove(const pair<size_t, size_t>& startPos, const pair<size_t, size_t>& endPos, bool direction, bool forceCombat) {
  auto moveResult = CheckMove(startPos, endPos, direction);
  switch(moveResult) {
  case Board::MoveResult::GOOD_MOVE:
    BoardMap.at(endPos).SetColorType(BoardMap.at(startPos).GetColorType());
    BoardMap.at(startPos).SetColorType(Figure::ColorType::NONE);
    break;
  case Board::MoveResult::GOOD_FIGHT:
    BoardMap.at(endPos).SetColorType(BoardMap.at(startPos).GetColorType());
    BoardMap.at(startPos).SetColorType(Figure::ColorType::NONE);
    BoardMap.at(pair<size_t, size_t>((startPos.first + endPos.first) / 2, (startPos.second + endPos.second) / 2)).SetColorType(Figure::ColorType::NONE);
    break;
  }
  return moveResult;
}

map<pair<size_t, size_t>, Figure>& Board::GetMap() {
  return BoardMap;
}

void Board::update() {
  notifyUpdate();
}

size_t Board::GetBoardSize() {
  return BoardSize;
}

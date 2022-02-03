#include "MainScreenModel.h"

MainScreenModel::MainScreenModel(Store* model) : _model(model) {
}

void MainScreenModel::update() {
  notifyUpdate();
}

Board& MainScreenModel::GetBoard() {
  return _model->board;
}

size_t MainScreenModel::GetWhiteScore() {
  return _model->WhiteScore;
}

size_t MainScreenModel::GetBlackScore() {
  return _model->BlackScore;
}

string MainScreenModel::GetCurrentPlayer() const {
  string player;
  if (_model->LastPlayer == Store::Player::WHITE) {
    player = "Black";
  }
  else {
    player = "White";
  }
  return move(player);
}

Store::Player MainScreenModel::GetWinner() const {
  Store::Player winner(Store::Player::NONE);
  if (_model->WhiteScore == 12) {
    winner = Store::Player::WHITE;
  }
  else if (_model->BlackScore == 12) {
      winner = Store::Player::BLACK;
  }
  return winner;
}

bool MainScreenModel::GetDirection() const {
  bool direction;
  switch(_model->LastPlayer) {
    case Store::Player::WHITE:
    direction = false;
    break;
    default:
    direction = true;
    break;
  }
  return direction;
}

pair<pair<size_t, size_t>, pair<size_t, size_t>> MainScreenModel::GetMove() {
  pair<pair<size_t, size_t>, pair<size_t, size_t>> position;
  size_t p1, p2;
  bool isLine1Number = true, isLine2Number = true;
  for_each(_model->line1.cbegin(), _model->line1.cend(), [&](char c) { if (!isdigit(c)) isLine1Number = false; });
  for_each(_model->line2.cbegin(), _model->line2.cend(), [&](char c) { if (!isdigit(c)) isLine2Number = false; });
  if (!isLine1Number || !isLine2Number) {
    position.first.first = 1;
    position.first.second = 1;
    position.second.first = 1;
    position.second.second = 1;
  }
  else {
    p1 = static_cast<size_t>(stoi(_model->line1));
    p2 = static_cast<size_t>(stoi(_model->line2));
    position.first.first = p1 / 10;
    position.first.second = p1 - 10 * position.first.first;
    position.second.first = p2 / 10;
    position.second.second = p2 - 10 * position.second.first;
  }
  _model->line1 = "";
  _model->line2 = "";
  return move(position);
}

void MainScreenModel::UpdateScore() {
  if (_model->LastPlayer == Store::Player::WHITE) {
    _model->BlackScore++;
  }
  else {
    _model->WhiteScore++;
  }
}

void MainScreenModel::SwitchPlayer() {
  if (_model->LastPlayer == Store::Player::WHITE) {
    _model->LastPlayer = Store::Player::BLACK;
  }
  else {
    _model->LastPlayer = Store::Player::WHITE;
  }
}

string MainScreenModel::CastPlayer(Store::Player player) const {
  string playerStr;
    switch (player) {
      case Store::Player::WHITE:
      playerStr = "White player";
      break;
      default:
      playerStr = "Black player";
      break;
    }
    return playerStr;
}

void MainScreenModel::FillLines(char c) {
  if (_model->line1.size() < 2) {
    _model->line1 += c;
  }
  else if (_model->line2.size() < 2) {
   _model->line2 += c;
  }
}

bool MainScreenModel::CheckLines() {
  if (_model->line1.size() == 2 && _model->line2.size() == 2) {
    return true;
  }
  return false;
}

string MainScreenModel::GetCurrentLine1() const {
  return _model->line1;
}

string MainScreenModel::GetCurrentLine2() const {
  return _model->line2;
}

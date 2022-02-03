#include "Figure.h"

Figure::Figure(ColorType type) : colorType(type) {
}

string Figure::DrawColorType() {
  if (colorType == ColorType::BLACK) {
    return "B";
  }
  else if (colorType == ColorType::WHITE) {
    return "W";
  }
  else {
    return " ";
  }
}

Figure::ColorType Figure::GetColorType() const {
  return colorType;
}

void Figure::SetColorType(ColorType type) {
  colorType = type;
}

void Figure::update() {
  notifyUpdate();
}

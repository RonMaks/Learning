#pragma once

#include "../../common/IModel.h"

#include <utility>
#include <string>
using namespace std;

class Figure : public IModel {
public:
  enum class ColorType { BLACK, WHITE, NONE };
  Figure(ColorType type);
  ColorType GetColorType() const;
  void SetColorType(ColorType type);
  string DrawColorType();
  void update();
private:
  ColorType colorType;
};

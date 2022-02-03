#pragma once

#include "Publisher.h"

class Publisher;

class Subscriber {
public:
  virtual void draw() = 0;
  virtual void onUpdate(Publisher* o) = 0;
};

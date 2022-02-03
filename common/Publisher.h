#pragma once

#include "IView.h"
#include "Subscriber.h"

#include <vector>

class Publisher {
public:
  void addSubscriber(Subscriber* subscriber);
  void notifyUpdate();
private:
  std::vector<Subscriber*> _subscribers;
};

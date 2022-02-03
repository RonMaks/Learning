#include "Publisher.h"

void Publisher::addSubscriber(Subscriber* subscriber) {
  _subscribers.push_back(subscriber);
}

void Publisher::notifyUpdate() {
  int size = _subscribers.size();
  for (int i = 0; i < size; i++) {
    _subscribers[i]->onUpdate(this);
  }
}

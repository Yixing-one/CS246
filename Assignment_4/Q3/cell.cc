#include "subject.h"
#include "observer.h"
#include "cell.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }
int Cell::getRow() const { return r; }
int Cell::getCol() const { return c; }

void Cell::setOn() {
}

void Cell::toggle() {
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Cell & whoNotified) {
}

void Cell::notifyObservers(SubscriptionType t) {
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}

std::string Cell::getName() const {
  
}


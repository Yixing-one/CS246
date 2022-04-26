#include <iostream>
#include "subject.h"

void Subject::attach(Observer *o) {
    observers.push_back(o);
}

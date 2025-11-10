#include "timer.h"

#include <iostream>
using namespace std;

Timer::Timer(std::string description): description(description) {}

void Timer::start() {
  // FΙXМΕ: set begin appropriately
  begin = clock();
}

void Timer::stop() {
  // FΙXМΕ: set end appropriately
  end = clock();
}

double Timer::getSecondsElapsed() const {
  // FΙXМΕ: calculate the number of seconds between start() and stop()
  double seconds;

  seconds = (end - begin) / 1000000.0;
  
  return seconds;
}

void Timer::printData() const {
  cout << description << ": " << getSecondsElapsed() << " seconds" << endl;
}


#include <Arduino.h>

#ifndef COMMAND_H
#define COMMAND_H



// basic actions for now
enum Action {
  PIN_MODE,
  DIGITAL_WRITE
};

struct Command {
  Action action;
  String value;
};


#endif
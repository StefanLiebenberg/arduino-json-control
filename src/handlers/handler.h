
#include "../parsers/command.h"

#ifndef HANDLER_H
#define HANDLER_H

class Handler {
  public:
    virtual bool canHandle(Command& command);
    virtual void handle(Command& command);
};

#endif
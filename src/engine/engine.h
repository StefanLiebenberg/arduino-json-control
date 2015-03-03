
#include "../handlers/handler.h";
#include "../parsers/command.h";
#include <LinkedList.h>;


#ifndef ENGINE_H
#define ENGINE_H

class Engine {
  private:
    LinkedList<Handler*> handlerList;
  public:
    void addHandler(Handler * handler);
    void handle(Command & command);
};

#endif
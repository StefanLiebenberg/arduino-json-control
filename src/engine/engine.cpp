
#include "engine.h";
#include "../handlers/handler.h";
#include "../parsers/command.h";


void Engine::addHandler(Handler * handler) {
   handlerList.add(handler);
};

void Engine::handle(Command & cmd) {
  for(int i = 0; i < handlerList.size(); i++) {
    Handler * handler = handlerList.get(i);
    if(handler->canHandle(cmd)) {
       handler->handle(cmd);
    }
  }
};

#include "../handlers/handler.h"
#include "../parsers/command.h"


#ifndef PIN_MODE_HANDLER_H
#define PIN_MODE_HANDLER_H

class PinModeHandler  : public Handler {
  public:
    bool canHandle(Command & cmd) {
      return cmd.action == PIN_MODE;
    }
    void handle(Command & cmd) {
            String val(""), pin("");
      bool comma = false;
      int i = 0;
      for(; i < cmd.value.length() && !comma; i++) {
        char c = cmd.value[i];
        switch(c) {
          case ',':
            comma = true;
            break;
          default:
            pin +=c;
        }
      }
      for(;i < cmd.value.length(); i++) {
        val += cmd.value[i];
      }
      if(val == "OUTPUT") {
         pinMode(pin.toInt(), OUTPUT);
      } else if (val == "INPUT") {
         pinMode(pin.toInt(), INPUT);
      }
    };
};
#endif
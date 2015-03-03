
#include "../handlers/handler.h";
#include "../parsers/command.h";
#include <Arduino.h>;

#ifndef DIGITAL_WRITE_HANDLER_H
#define DIGITAL_WRITE_HANDLER_H

class DigitalWriteHandler : public Handler {

   public:

     bool canHandle(Command & cmd) {
       return cmd.action == DIGITAL_WRITE;
     };

     void handle(Command& cmd) {
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
       if(val == "HIGH") {
          digitalWrite(pin.toInt(), HIGH);
       } else if (val == "LOW") {
          digitalWrite(pin.toInt(), LOW);
       }
     };
};

#endif
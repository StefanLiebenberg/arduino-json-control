
#include "stream_parser.h";
#include <Arduino.h>

bool StreamParser::parse(Stream & str) {
  while(str.available() && !cmdParser.isComplete()) {
    char c = str.read();
    Serial.println("parse " + String(c));
    if(!cmdParser.parse(c)) {
      Serial.println("error?");
      return false;
    }
  }
  return true;
}

bool StreamParser::isComplete() {
  return cmdParser.isComplete();
}

void StreamParser::reset() {
  cmdParser.reset();
}

bool StreamParser::hasError() {
  return cmdParser.hasError();
}

void StreamParser::getResult(Command & cmd) {
 cmdParser.getResult(cmd);
}
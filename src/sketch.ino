
#include "parsers/stream_parser.h";
#include "engine/engine_factory.h";
#include "engine/engine.h";
#include "parsers/command.h";

int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

String status() {
    return "Free Ram: " + String(freeRam());
}

StreamParser streamParser;

EngineFactory factory;
Engine engine;

void setup(){
   Serial.begin(9600);
   factory.create(engine);
   Serial.println(status());
}

int step = 0;
Command cmd;
void loop() {
  if(streamParser.parse(Serial) && !streamParser.hasError()) {
    if(streamParser.isComplete()) {
      streamParser.getResult(cmd);
      streamParser.reset();
      engine.handle(cmd);
      cmd.~Command(); // try destructing it
    }
  } else {
    Serial.println("Failure to parse... reseting..");
    Serial.flush();
    streamParser.reset();
  }

  Serial.println(status());
  delay(1000);
}

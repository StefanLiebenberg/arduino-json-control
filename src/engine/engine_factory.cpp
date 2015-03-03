
#include "engine_factory.h";
#include "engine.h";
#include "../handlers/pin_mode_handler.h";
#include "../handlers/digital_write_handler.h";
#include "../handlers/handler.h";

void EngineFactory::create(Engine & engine) {
  engine.addHandler(new PinModeHandler());
  engine.addHandler(new DigitalWriteHandler());
};
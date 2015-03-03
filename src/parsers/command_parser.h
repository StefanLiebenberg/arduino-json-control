#include <Arduino.h>;
#include "command.h";

#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H


class CommandParser {
  private:
    Action currentAction;
    String currentValue;
    String entryKey;
    String entryValue;
    void saveCommand(String name);
    void saveValue(String name);
    void save(String k, String v);
    bool keyComplete;
    bool keyStarted;
    bool separatorComplete;
    bool valueStarted;
    bool valueComplete;
    bool entryListComplete;
    bool entryListStarted;
    bool entryStarted;
    bool entryComplete;
    bool entryError;
    bool parseEntry(char c);
    bool isImportantKey(String key);
  public:
    bool parse(char c);
    void reset();
    bool hasError();
    bool isStarted();
    bool isComplete();
    bool hasResult();
    void getResult(Command & cmd);


};

#endif

#include "command_parser.h";
#include "util.hpp"

void CommandParser::saveCommand(String commandName) {
  if(commandName == "pinMode") {
    currentAction = PIN_MODE;
  } else if(commandName == "digitalWrite") {
     currentAction = DIGITAL_WRITE;
  }
};

void CommandParser::saveValue(String value) {
  currentValue = value;
}

void CommandParser::save(String key, String value) {
  if(key == "command") {
     saveCommand(value);
  } else if(key == "value") {
     saveValue(value);
  }
}

bool CommandParser::parseEntry(char c) {
  if(entryComplete) return true;
  if(entryError) return false;

  if(!entryStarted) {
    if(util::isWhitespaceTrash(c)) return true;
    switch(c) {
       case '\"':
         entryStarted = true;
         return true;
       default:
         entryError = true;
         return false;
    }
  }

  // todo, add checks for escaped \" values.
  if(!keyComplete) {
    switch(c) {
      case '\"':
        keyComplete = true;
        return true;
      default:
        entryKey += c;
        return true;
    }
  }

  if(!separatorComplete) {
    if(util::isWhitespaceTrash(c)) return true;
    switch(c) {
      case ':':
        separatorComplete = true;
        return true;
      default:
        entryError = true;
        return false;
    }
  }

  if(!isImportantKey(entryKey)) {
    return false;
  }

  if(!valueStarted) {
    if(util::isWhitespaceTrash(c)) return true;
    switch(c) {
      case '\"':
        valueStarted = true;
        return true;
      default:
        entryError = true;
        return false;
    }
  }

  if(!valueComplete) {
    switch(c) {
      case '\"':
        valueComplete =true;
        return true;
      default:
        entryValue += c;
        return true;
    }
  }

  entryComplete = true;
  return true;
}

bool CommandParser::parse(char c) {


   if(entryListComplete) return true;
   if(entryError) return false;


   if(!entryListStarted) {
     if(util::isWhitespaceTrash(c)) return true;
     switch(c) {
       case '{':
         entryListStarted = true;
         return true;
       default:
         entryError = true;
         return false;
     }
   }

   if(parseEntry(c)) {
     if(entryComplete) {
       save(entryKey, entryValue);
       if(util::isWhitespaceTrash(c)) return true;
       switch(c) {
         case '}':
           entryListComplete = true;
           return true;
         case ',':
           entryKey = "";
           entryValue = "";
           entryComplete = false;
           entryStarted = false;
           separatorComplete = false;
           keyComplete = false;
           valueComplete = false;
           valueStarted = false;
           return true;
         default:
           entryError = true;
           return false;
       }
     }
     return true;
   } else {
     entryError = true;
     return false;
   }
}



bool CommandParser::isImportantKey(String key) {
  if(key == "command" || key == "value") {
    return true;
  }
  return false;
}

void CommandParser::reset() {
  currentAction;
  currentValue;

  entryKey = "";
  entryValue = "";
  keyComplete = false;
  keyStarted = false;
  separatorComplete = false;

    valueStarted = false;
    valueComplete = false;

    entryListComplete=  false;
    entryListStarted = false;

    entryStarted=  false;
    entryComplete = false;
    entryError= false;

}


void CommandParser::getResult(Command & cmd) {
  cmd.action = currentAction;
  cmd.value = currentValue;
}

bool CommandParser::hasError() {
    return entryError;
}

bool CommandParser::isComplete() {
  return entryComplete;
}



#include "command_parser.h";
#include <Stream.h>

#ifndef STREAM_PARSER_H
#define STREAM_PARSER_H

class StreamParser {
  private:
    CommandParser cmdParser;
  public :
    bool parse(Stream & str);
    void reset();
    bool isComplete();
    bool hasError();
    void getResult(Command & cmd);
};

#endif
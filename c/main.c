#include <stdbool.h>
#include <stdio.h>

#include "scanner.h"
#include "vm.h"

int main(int argc, const char * argv[]) {
//  const char* source = "([{)]},;.!";
//  const char* source = "+-*/% = == != < > <= >=";
//  const char* source = "1 // comment\n + // comment\n2";
//  const char* source = "an and andy";
//  const char* source = "1234 0 000 -123 12.34 .45 56. 1.2.3 4..5";
//  const char* source = "\"\" \"string\"";
//  Scanner scanner;
//  initScanner(&scanner, source);
//  
//  while (true) {
//    Token token = nextToken(&scanner);
//    printf("%d '%.*s'\n", token.type, token.length, token.start);
//    if (token.type == TOKEN_EOF) break;
//  }
  
  VM vm;
  initVM(&vm);
  
  for (double d = 100.0; d < 200.0; d++) {
    pushNumber(&vm, d);
    pop(&vm);
  }
  
  pushNumber(&vm, 1.0);
  pushNumber(&vm, 2.0);
  pushPair(&vm);
  pushNumber(&vm, 3.0);
  pushNumber(&vm, 4.0);
  pushPair(&vm);
  pushPair(&vm);
  
  collectGarbage(&vm);
  printStack(&vm);
  
  return 0;
}
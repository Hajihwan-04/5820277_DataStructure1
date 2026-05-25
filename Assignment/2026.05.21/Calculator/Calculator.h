#include <stdio.h>
#include <stdlib.h>

extern int inFixToPostfix(char* infix, char* postfix);
extern int evalPostfix(char* postfix);
extern int precedence(char op);
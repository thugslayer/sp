%{
#include<stdio.h>
%}
LETTER [a-zA-Z]
DIGIT [0-9]
%%
begin { printf("Recognized Keyword: %s\n", yytext); }
if { printf("Recognized Keyword: %s\n", yytext); }
[a-z]+([A-Z]|[0-9])* { printf("Recognized ID: %s\n", yytext); }
.+ { printf("Unrecognized Input: %s\n", yytext); } // This will match any other character
%%
int main()
{
yylex();
return 0;
}

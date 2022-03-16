#include "token.h"

#define MAX_STR_LEN 1024
#define MAX_TOKENS 16
#define TOKENS "+-*\"

struct lexer_
{
    char str[MAX_STR_LEN + 1];
    char tokens[MAX_TOKENS];
    int position;
}

lexer *
tokenConstrutor(char *str)
{
    Lexer *lexer = (lexer *)malloc(sizeof(lexer));

    if (lexer != NULL)
    {
        char tokens[] = TOKENS;

        if (str != NULL)
        {
            strcpy(lexer->str, str);
        }
        else
        {
            lexer->str[0] = '\0';
        }

        strcpy(lexer->tokens, TOKENS);

        lexer->position = 0;
    }

    return lexer;
}

void
lexerDestrutor(Lexer *lexer)
{
    free(lexer);
}

void
getNext(char *str, char* data)
{
    while(!checkCharIsToken())
    {

    }
}

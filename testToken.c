#include <assert.h>
#include <string.h>
#include "token.h"

void testGetNextStrNull()
{
    lexer *lexer;
    char *str = NULL
    char data[TOKEN_KIND_MAX_LEN + 1][TOKEN_MAX_LEN + 1];

    lexer = lexerContrutor(str);

    getNext(token, data);

    assert(strcmp(data[0], "END OF INPUT") == 0);
    assert(strcmp(data[1], "") == 0);

    tokenDestrutor(token);
}

/*void testGetNext()
{
    tokenStruct token;
    char str[] = "10"
    char data[TOKEN_KIND_MAX_LEN + 1][TOKEN_MAX_LEN + 1];
    char tokens[] = {' ', '.'};

    token = tokenContrutor(str, tokens);

    getNext(token, data);

    assert(strcmp(data[0], "NUMBER") == 0);
    assert(strcmp(data[1], "10") == 0);

    getNext(token, data);

    assert(strcmp(data[0], "END OF INPUT") == 0);
    assert(strcmp(data[1], "") == 0);

    tokenDestrutor(token);
}*/

int main()
{
    testGetNextStrNull();

    //testGetNext();

    return 0;
}

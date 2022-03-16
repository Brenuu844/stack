#define TOKEN_MAX_LEN 128
#define TOKEN_KIND_MAX_LEN 16

typedef struct lexer_ Lexer;

lexer *tokenConstrutor(char *str);

void lexerDestrutor(Lexer *lexer);

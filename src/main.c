/*
this is a scripting language. why? so you could embed it in mostly everything
why not lua? because lua is hard to embed, but if you want, you can do that
too. now enjoy our spaghetti code, thanks.
*/
#include "lexer.h" // include the lexer

int main(int argc, char* argv[])
{
    const char *input = "if (x + 3) return 42";
    const char *current = input;

    Token token;
    do {
        token = getNextToken(&current);
        switch (token.type) {
            case TOKEN_NUMBER:
                printf("NUMBER: %s\n", token.value);
                break;
            case TOKEN_IDENTIFIER:
                printf("IDENTIFIER: %s\n", token.value);
                break;
            case TOKEN_KEYWORD:
                printf("KEYWORD: %s\n", token.value);
                break;
            case TOKEN_OPERATOR:
                printf("OPERATOR: %s\n", token.value);
                break;
            case TOKEN_EOF:
                printf("EOF\n");
                break;
            default:
                printf("INVALID TOKEN\n");
                break;
        }
    } while (token.type != TOKEN_EOF);

    return 0;
};
/*
THIS is the lexer file. i hate this one so much, that's
why it will take me a lot of commits to finish this one.
*/
#include "lexer.h" // include the lexer .h file

// first, we define all the keywords
const char *keywords[] = {"if",
                          "else",
                          "while",
                          "return"};

int num_keywords = sizeof(keywords) / sizeof(keywords[0]); // get total size

// now, some helping functions
int is_keyword(const char *str)
{
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1; // true..
        }
    }
    return 0; // not true..
};

Token getNextToken(const char **input)
{
    // why is intellisense drunk again? - Moon
    Token token;
    token.type = TOKEN_INVALID; // default: invalid

    while (isspace(**input)) {
        (*input)++;
    }

    if (**input == '\0') {
        token.type = TOKEN_EOF; // set to EOF
        return token;
    }

    if (isdigit(**input)) {
        token.type = TOKEN_NUMBER; // set to number
        int i = 0;
        while (isdigit(**input)) {
            token.value[i++] = *(*input)++;
        }
        token.value[i] = '\0'; // null-termination wow
        return token;
    }

    if (isalpha(**input)) {
        int i = 0;
        while (isalnum(**input)) {
            token.value[i++] = *(*input)++;
        }
        token.value[i] = '\0'; // null-termination wow

        if (is_keyword(token.value)) {
            token.type = TOKEN_KEYWORD; // set to keyword
        } else {
            token.type = TOKEN_IDENTIFIER; // set to identifier
        }
        return token;
    }
    if (strchr("+-*/=><!", **input)) {
        token.type = TOKEN_OPERATOR;
        token.value[0] = *(*input)++;
        token.value[1] = '\0'; // null-termination wow
        return token;
    }

    return token; // invalid token
};
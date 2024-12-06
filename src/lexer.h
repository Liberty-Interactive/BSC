/*
another part of the lexer, huh. welp, ok.
*/
#ifndef LEXER_H
#define LEXER_H
#ifdef _WIN32
#pragma once
#endif

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// asdasasasA
typedef enum {
    TOKEN_INVALID,
    TOKEN_NUMBER,
    TOKEN_IDENTIFIER,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char value[64];
} Token;

// i hate extern's
extern const char *keywords[];
extern int num_keywords;

// funcs
Token getNextToken(const char **input);
int is_keyword(const char *str);

#endif

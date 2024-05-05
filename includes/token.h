#ifndef TOKEN_H
#define TOKEN_H
typedef enum
    {
        TOKEN_INT,
        TOKEN_ID,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_CHAR,
        TOKEN_STAR,
        TOKEN_LSQUARE,
        TOKEN_RSQUARE,
        TOKEN_LBRACE,
        TOKEN_RBRACE,
        TOKEN_COMMA,
        TOKEN_SEMI,
        TOKEN_RET,
        TOKEN_ARROW,
        TOKEN_EOF
    }Type;

typedef struct TOKEN_STRUCT
{
    char *value;
    Type type;
}token;

token *init_token(char *value, Type type);
#endif
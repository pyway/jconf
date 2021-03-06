/**
 * JConf Parser
 *
 * Copyright 2015 Mayank Sindwani
 * Released under the MIT License:
 * http://opensource.org/licenses/MIT
 *
 * Description: JConf parses JSON files to c struct tokens.
 * Author: Mayank Sindwani
 * Date: 2015-06-23
 */

#ifndef __JCONF_H__
#define __JCONF_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include "array.h"
#include "map.h"

// Ctype macros.

#define jconf_isdigit(c) ((c>= '0') && (c <= '9')) ? 1 : 0
#define jconf_isspace(c) ((c>=0x09 && c<=0x0D) || (c==0x20)) ? 1 : 0
#define jconf_isxdigit(c) (jconf_isdigit(c) || ((c >= 'A') && (c <= 'F')) || ((c >= 'a') && (c <= 'f'))) ? 1 : 0
#define jconf_isctrl(c)  ((c == 'n') || (c == '\"') || (c == '\\') || (c == '/') || (c == 'b') || (c == 'f') || (c == 'r') || (c == 't') || (c == 'u')) ? 1 : 0

// Token Error Codes.
typedef enum _j_err_code
{
    JCONF_NO_ERROR = 0,
    JCONF_INVALID_CTRL_SEQUENCE,
    JCONF_HEX_REQUIRED,
    JCONF_INVALID_HEX,
    JCONF_UNEXPECTED_TOK,
    JCONF_UNEXPECTED_EXPR,
    JCONF_UNEXPECTED_EOF,
    JCONF_EXPECTED_EOF,
    JCONF_INVALID_NUMBER,
    JCONF_OUT_OF_MEMORY

} J_ERROR_CODE;

// Token Type Values.
typedef enum _j_tok_type
{
    JCONF_FALSE = 0,
    JCONF_NULL,
    JCONF_TRUE,
    JCONF_ARRAY,
    JCONF_OBJECT,
    JCONF_STRING,
    JCONF_DOUBLE,
    JCONF_INT

} jType;

// jToken struct definition.
typedef struct _j_token
{
    jType type;
    void* data;

} jToken;

// jArgs struct definition.
typedef struct _j_args
{
    J_ERROR_CODE e;
    int line;
    int pos;

} jArgs;

// JConf API.
jToken* jconf_json2c(const char*, int, jArgs*);
jToken* jconf_get(jToken*, const char*, ...);
void jconf_free_token(jToken*);

#ifdef __cplusplus
}
#endif

#endif
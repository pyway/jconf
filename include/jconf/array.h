/**
 * JConf Array
 *
 * Copyright 2015 Mayank Sindwani
 * Released under the MIT License:
 * http://opensource.org/licenses/MIT
 *
 * Description: A dynamic array implementation to represent JSON arrays.
 * Author: Mayank Sindwani
 * Date: 2015-07-11
 */

#ifndef __ARRAY_JCONF_H__
#define __ARRAY_JCONF_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>  // For standard macros and dynamic memory allocation.

// jArray struct definition.
typedef struct _j_array
{
    int size, end, expand;
    void** values;

} jArray;

// jArray API.
int   jconf_init_array(jArray*, int, int);
void  jconf_destroy_array(jArray*);

int   jconf_array_push(jArray*, void*);
void* jconf_array_pop(jArray*);

int   jconf_array_set(jArray*, int, void*);
void* jconf_array_get(jArray*, int);

#ifdef __cplusplus
}
#endif

#endif
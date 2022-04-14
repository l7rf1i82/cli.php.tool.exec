//
// Created by Alexandr on 14.04.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "callback.h"


char * getCallbackString(char * callback_name)
{
    char * callback_name_d;

    if(strlen(callback_name) == 0)
    {
        callback_name_d = malloc(2);
        strcat(callback_name_d, "");

        return callback_name_d;
    }

    callback_name_d = malloc(strlen(callback_name) + 24);

    strcat(callback_name_d, "\n");
    strcat(callback_name_d, callback_name);
    strcat(callback_name_d, "($argc, $argv);");

    return callback_name_d;
}
//
// Created by Alexandr on 14.04.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "argument.h"


char * getArgString(char * argv[])
{
    char * str_argv_current_copy;
    char * str_argv_current;

    char * str_argv_copy;
    char * str_argv;

    for (int i = 3; argv[i] != (void *)0; ++i)
    {
        str_argv_current_copy = malloc((strlen(argv[i]) + 4) * 4 + 8);
        str_argv_current      = malloc((strlen(argv[i]) + 4) * 4 + 8);
        strcpy(str_argv_current, argv[i]);

        if (str_argv != NULL)
        {
            str_argv_copy = malloc(strlen(str_argv) + 8);
            strcpy(str_argv_copy, str_argv);
            free(str_argv);
        }

        if (str_argv_copy != NULL)
        {
            str_argv      = malloc(strlen(str_argv_copy) + (strlen(str_argv_current) + 4) * 4 + 8);
            strcpy(str_argv, str_argv_copy);
            free(str_argv_copy);
        }
        else
        {
            str_argv      = malloc((strlen(str_argv_current) + 4) * 4 + 8);
        }

        if(i > 3)
        {
            strcat(str_argv, " ");
        }
        strcpy(str_argv_current_copy, "\"");
        strcat(str_argv_current_copy, str_argv_current);
        strcat(str_argv_current_copy, "\"");
        free(str_argv_current);

        str_argv_current = malloc(strlen(str_argv_current_copy) * 4 + 8);
        strcpy(str_argv_current, str_argv_current_copy);
        free(str_argv_current_copy);

        strcat(str_argv, str_argv_current);
        free(str_argv_current);
    }

    return str_argv;
}
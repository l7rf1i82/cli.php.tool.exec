//
// Created by Alexandr on 11.04.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "lib/callback.h"
#include "lib/argument.h"


#define LINE_LENGTH_MAX 128


int main(int argc, char * argv[])
{
    FILE * fp;

    char line[LINE_LENGTH_MAX];
    int line_count = 0;

    char * code_d;
    char * command_d;
    char * command_d_copy;


    // 1. copy code from file to command
    fp = fopen(argv[1], "r");

    while (fgets(line, LINE_LENGTH_MAX, fp)) {
        line_count++;
    }
    code_d    = malloc(LINE_LENGTH_MAX * line_count);
    command_d = malloc(LINE_LENGTH_MAX * line_count + 32);

    rewind(fp);

    while (fgets(line, LINE_LENGTH_MAX, fp)) {
        strcat(code_d, line);
    }

    fclose(fp);

    strcat(command_d, "php -r '");
    strcat(command_d, code_d);
    free(code_d);


    // 2. copy callback to command
    if(argc >= 3)
    {
        char * callback_str = getCallbackString(argv[2]);

        command_d_copy = malloc(strlen(command_d) + 8);
        strcpy(command_d_copy, command_d);

        // extend command size
        command_d = malloc(strlen(command_d_copy) + strlen(callback_str) + 8);

        strcpy(command_d, command_d_copy);
        free(command_d_copy);
        strcat(command_d, callback_str);
        free(callback_str);
    }

    strcat(command_d, "' ");


    // 3. copy args to command
    if(argc >= 4)
    {
        char * argv_str = getArgString(argv);

        command_d_copy = malloc(strlen(command_d) + 8);
        strcpy(command_d_copy, command_d);

        // extend command size
        command_d = malloc(strlen(command_d_copy) + strlen(argv_str) + 8);

        strcpy(command_d, command_d_copy);
        free(command_d_copy);
        strcat(command_d, argv_str);
        free(argv_str);
    }


    system(command_d);
    free(command_d);

    return 0;
}
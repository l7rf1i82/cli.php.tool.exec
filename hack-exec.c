/*
    MacOS Catalina
    Apple clang version 12.0.0 (clang-1200.0.32.29)

    gcc -o ./bin/hack-exec ./hack-exec.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LINE_LENGTH_MAX 128


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

char * getArgString(char * argv[])
{

    char * str_argv_current;

    char * str_argv_copy;
    char * str_argv;

    for (int i = 3; argv[i] != (void *)0; ++i)
    {
        str_argv_current = malloc(strlen(argv[i]) + 4);
        strcpy(str_argv_current, argv[i]);

        if (str_argv != NULL)
        {
            str_argv_copy = malloc(strlen(str_argv) + 4);
            strcpy(str_argv_copy, str_argv);
        }

        if (str_argv_copy != NULL)
        {
            str_argv      = malloc(strlen(str_argv_copy) + strlen(str_argv_current)  + 4);
            strcpy(str_argv, str_argv_copy);
        }
        else
        {
            str_argv      = malloc(strlen(str_argv_current)  + 8);
        }

        if(i > 3)
        {
            strcat(str_argv, " ");
        }
            strcat(str_argv, str_argv_current);
    }

    free(str_argv_current);
    free(str_argv_copy);

    return str_argv;
}

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
    command_d = malloc(LINE_LENGTH_MAX * line_count + 16);

    rewind(fp);

    while (fgets(line, LINE_LENGTH_MAX, fp)) {
        strcat(code_d, line);
    }

    fclose(fp);

    strcat(command_d, "php -r ");
    strcat(command_d, "'");
    strcat(command_d, code_d);
    free(code_d);


    // 2. copy callback to command
    if(argc >= 3)
    {
        char * callback_str = getCallbackString(argv[2]);

        command_d_copy = malloc(strlen(command_d));
        strcpy(command_d_copy, command_d);

        // extend command size
        command_d = malloc(strlen(command_d_copy) + strlen(callback_str));

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

        command_d_copy = malloc(strlen(command_d));
        strcpy(command_d_copy, command_d);

        // extend command size
        command_d = malloc(strlen(command_d_copy) + strlen(argv_str));

        strcpy(command_d, command_d_copy);
        free(command_d_copy);
        strcat(command_d, argv_str);
        free(argv_str);
    }


    system(command_d);
    free(command_d);

    return 0;
}
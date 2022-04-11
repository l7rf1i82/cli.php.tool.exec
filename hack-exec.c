/*
    MacOS Catalina
    gcc -o ./hack-exec ./hack-exec.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH_MAX 128


int main(int argc, char * argv[])
{
    FILE * fp;
    fp = fopen(argv[1], "r");

    char line[LINE_LENGTH_MAX];
    int line_count = 0;

    char * code_d;
    char * command_d;

    // calc lines count
    while (fgets(line, LINE_LENGTH_MAX, fp)) {
        line_count++;
    }
    code_d    = malloc(LINE_LENGTH_MAX*line_count);
    command_d = malloc(LINE_LENGTH_MAX*line_count + 16);

    //replace fp pointer
    rewind(fp);
    // copy line to var
    while (fgets(line, LINE_LENGTH_MAX, fp)) {
        strcat(code_d, line);
    }

    fclose(fp);

    strcat(command_d, "php -r ");
    strcat(command_d, "'");
    strcat(command_d, code_d);
    strcat(command_d, "'");


    system(command_d);

    free(code_d);
    free(command_d);

    return 0;
}
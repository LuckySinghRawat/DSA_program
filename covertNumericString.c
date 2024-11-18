#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char charval[100] = "40 8 / 5 2 * -";


    char *token = strtok(charval, " ");
    /*strtok[string.h] insert a null character at the end of the string

It also modifies the original string by replacing the delimiter (space) with a null terminator ('\0')*/
    
    
    
    int intval = atoi(token), i;
    //atoi[stdlib.h] converts a string to an integer



    while (token != '\0')
    {
        //print current token
        printf("%s ", token);


        //get next token
        token = strtok(NULL, " ");
    }
        printf("--%d--", intval);
}
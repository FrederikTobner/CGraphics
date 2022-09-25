#include "utilities.h"

#include <stdlib.h>
#include <stdio.h>

void write_log(const char* msg)
{
    char *filename = "log.txt";
    FILE *fp = fopen(filename, "a");

   /* Write content to file */
   fprintf(fp, "%s\n", msg);
}

char* extract_name(const char* full)
{
    size_t lastBackSlashIndex = 0;
    char * cp;
    for(cp = (char*)full; *cp; cp++)
        if(*cp == '\\')
            lastBackSlashIndex = cp - full;
    if(!lastBackSlashIndex)
        return (char*)full;
    size_t length = (cp - full) - lastBackSlashIndex;
    char * name = malloc(length * sizeof(char));
    cp = (char*)full + lastBackSlashIndex + 1;
    for (size_t s = 0; s < length; s++)
        name[s] = cp[s];    
    return name;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1000

int main(int argc, char *argv[])
{
    FILE *source;
    FILE *shortFile;
    FILE *longFile;
    char line[MAX_LINE];
    int shortCount = 0;
    int longCount = 0;

    if (argc != 4)
    {
        printf("Usage: %s source short-output long-output\n", argv[0]);
        return 1;
    }

    source = fopen(argv[1], "r");
    shortFile = fopen(argv[2], "w");
    longFile = fopen(argv[3], "w");

    if (source == NULL || shortFile == NULL || longFile == NULL)
    {
        printf("Error opening one or more files.\n");

        if (source != NULL)
            fclose(source);
        if (shortFile != NULL)
            fclose(shortFile);
        if (longFile != NULL)
            fclose(longFile);

        return 1;
    }

    while (fgets(line, MAX_LINE, source) != NULL)
    {
        size_t length = strlen(line);

        if (length > 0 && line[length - 1] == '\n')
            length--;

        if (length < 20)
        {
            for (int i = 0; line[i] != '\0'; i++)
                line[i] = toupper((unsigned char) line[i]);

            fputs(line, shortFile);
            shortCount++;
        }
        else
        {
            for (int i = 0; line[i] != '\0'; i++)
                line[i] = tolower((unsigned char) line[i]);

            fputs(line, longFile);
            longCount++;
        }
    }

    fclose(source);
    fclose(shortFile);
    fclose(longFile);

    printf("%d lines written to %s\n", shortCount, argv[2]);
    printf("%d lines written to %s\n", longCount, argv[3]);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INPUT_SIZE 101
#define NAME_SIZE  400

void removeNewline(char text[]);
void formatWords(char text[]);
int containsCheese(const char text[]);

int main(void)
{
    char color[INPUT_SIZE];
    char snack[INPUT_SIZE];
    char animal[INPUT_SIZE];

    char band1[NAME_SIZE];
    char band2[NAME_SIZE];
    char comboWord[INPUT_SIZE];
    char band3[NAME_SIZE];
    char bonus[NAME_SIZE];

    printf("Enter your favorite color: ");
    fgets(color, sizeof(color), stdin);

    printf("Enter your favorite snack: ");
    fgets(snack, sizeof(snack), stdin);

    printf("Enter your favorite animal: ");
    fgets(animal, sizeof(animal), stdin);

    removeNewline(color);
    removeNewline(snack);
    removeNewline(animal);

    formatWords(color);
    formatWords(snack);
    formatWords(animal);

    /* The Color Snack */
    strcpy(band1, "The ");
    strcat(band1, color);
    strcat(band1, " ");
    strcat(band1, snack);

    /* The Color Animal */
    strcpy(band2, "The ");
    strcat(band2, color);
    strcat(band2, " ");
    strcat(band2, animal);

    /* First 3 snack letters + first 2 animal letters + s */
    strncpy(comboWord, snack, 3);
    comboWord[3] = '\0';
    strncat(comboWord, animal, 2);
    strcat(comboWord, "s");

    /* Keep only the first letter capitalized */
    for (int i = 1; comboWord[i] != '\0'; i++)
    {
        comboWord[i] = tolower((unsigned char) comboWord[i]);
    }

    strcpy(band3, "The ");
    strcat(band3, comboWord);

    printf("\nPresenting ... %s!\n", band1);
    printf("Tonight only ... %s!\n", band2);
    printf("Get ready for ... %s!\n", band3);

    /* Optional cheese Easter egg */
    if (containsCheese(snack))
    {
        strcpy(bonus, "The Cheesy ");
        strcat(bonus, animal);

        printf("\nBonus band name unlocked:\n");
        printf("%s!\n", bonus);
    }

    return 0;
}

void removeNewline(char text[])
{
    text[strcspn(text, "\n")] = '\0';
}

void formatWords(char text[])
{
    int beginningOfWord = 1;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace((unsigned char) text[i]))
        {
            beginningOfWord = 1;
        }
        else if (beginningOfWord)
        {
            text[i] = toupper((unsigned char) text[i]);
            beginningOfWord = 0;
        }
        else
        {
            text[i] = tolower((unsigned char) text[i]);
        }
    }
}

int containsCheese(const char text[])
{
    char lowercase[INPUT_SIZE];

    strcpy(lowercase, text);

    for (int i = 0; lowercase[i] != '\0'; i++)
    {
        lowercase[i] = tolower((unsigned char) lowercase[i]);
    }

    return strstr(lowercase, "cheese") != NULL;
}
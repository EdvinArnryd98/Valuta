#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char currency[20];
    int penny;

} Money;

int main()
{
    FILE *file;
    file = fopen("test.txt", "r");

    if (file == NULL)
    {
        printf("Error!");
        return 1;
    }

    Money moneys[100];
    int read = 0;
    int records = 0;

    do
    {
        Money *p = moneys + records;
        read = fscanf(file, "%s %d\n", &p->currency, &p->penny);

        if (read == 2)
            records++;

        if (read != 2 && !feof(file))
        {
            printf("File format incorrect\n");
            return 1;
        }
        if (ferror(file))
        {
            printf("Error reading file.\n");
            return 1;
        }

    } while (!feof(file));

    fclose(file);

    printf("\n%d  records read.\n\n", records);

    for (int i = 0; i < records; i++)
    {

        if (i == records - 1)
        {
            printf("1 %s costs %d pennys.", moneys[i].currency, moneys[i].penny);
            // printf("\n");
        }
        else
        {
            printf("1 %s costs %d pennys, ", moneys[i].currency, moneys[i].penny);
            // printf("\n");
        }
    }
    return 0;
}

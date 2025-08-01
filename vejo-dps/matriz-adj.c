#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAXCHAR 1000

int main(void) {

    FILE *fp;
    char row[MAXCHAR];
    char *token;

    fp = fopen("cidades.csv","r");


    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        printf("Linha: %s", row);

        token = strtok(row, ",");

        while(token != NULL)
        {
            printf("Token: %s\n", token);
            token = strtok(NULL, ",");
        }

    }
    

    return 0;

}

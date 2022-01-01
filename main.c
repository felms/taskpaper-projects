#include <stdio.h>
#include <string.h>

int main() {


    // Lê o nome do projeto
    char projectName[256];
    printf("Name of the project: ");
    fgets(projectName, sizeof projectName, stdin);
    strtok(projectName, "\n"); // fgets adiciona um \n na string lida. Aqui eu retiro isso

    // Lê o nome da ação a ser executada
    char action[256];
    printf("Action that will be performed: ");
    fgets(action, sizeof action, stdin);
    strtok(action, "\n"); // fgets adiciona um \n na string lida. Aqui eu retiro isso

    // Lê o número de dias
    int numberOfDays;
    printf("Number of days: ");
    scanf("%d", &numberOfDays);    


    // Monta o projeto no formato taskpaper
    char project[4096]; //valor arbitrário, duvido que algum dos meus projetos seja maior que isso
    strcpy(project, projectName);
    strcat(project, "\n");
    
    for (int i = 1; i <= numberOfDays; i++) {
        char row[256];
        sprintf(row, "\t- %s %d of %d\n", action, i, numberOfDays);                
        strcat(project, row);
    }

    // Imprime tudo
    puts(project);
    
    return 0;
}
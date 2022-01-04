#include <stdio.h>
#include <string.h>

#include <stdbool.h>

void daysOfX(char* project, size_t bufferSize);

int main() {


    char project[4096]; //valor arbitrário, duvido que algum dos meus projetos seja maior que isso

    daysOfX(project, sizeof project);
    
    // Salva tudo em arquivo
    FILE *outputFile = fopen("output.txt", "a+");
    if(outputFile != NULL) {
        fputs(project, outputFile);
        fclose(outputFile);
    }

    return 0;
}


// Cria um projeto de um tipo de ação repetida por vários dias.
void daysOfX(char* project, size_t bufferSize) {

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

    // Vê se serão utlizados metadados
    bool metadata;
    char mData[2];
    printf("Parallel? (y/n) "); 
    fgets(mData, sizeof mData, stdin);
    if (mData[0] == 'n' || mData[0] == 'N') {
        metadata = false;
    }

    // Lê o número de dias
    int numberOfDays;
    printf("Number of days: ");
    scanf("%d", &numberOfDays);
    

    // Monta o projeto no formato taskpaper
    strcpy(project, projectName);
    if(!metadata) {
        strcat(project, " @parallel(false)");
    }
    strcat(project, "\n");
    
    for (int i = 1; i <= numberOfDays; i++) {
        char row[256];
        sprintf(row, "\t- %s %d of %d\n", action, i, numberOfDays);                
        strcat(project, row);
    }

    project[bufferSize - 1] = '\0'; // Caracter de término

}
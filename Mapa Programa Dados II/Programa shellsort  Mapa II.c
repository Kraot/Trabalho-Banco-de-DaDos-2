#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024
#define MAX_BOOKS 100

struct book{
    int codigo;
	char titulo[50];
	char acao[50]; 
	char classe[50];
	char contem[50];
};
struct book books[MAX_BOOKS];
void shellsort(struct book []);

int main(int argc, char **argv)
{   
//LER ARQUIVO E CRIAR ARRAY DE STRUCTS
   FILE *bookFile;

    char *buf = malloc(MAX_STR_LEN);
    char *tmp; 


    if (buf == NULL) {
        printf ("No memory\n");
        return 1;
    }

    if ( ( bookFile = fopen( "mapa II.csv", "r" ) ) == NULL ) //Reading a file
    {
        printf( "File could not be opened.\n" );
    }

    int i = 0;
    while (fgets(buf, 1023, bookFile) != NULL)
    {
        if ((strlen(buf)>0) && (buf[strlen (buf) - 1] == '\n'))
            buf[strlen (buf) - 1] = '\0';       

        tmp = strtok(buf, ",");
        books[i].codigo = atoi(tmp);

        tmp = strtok(NULL, ",");
          strcpy(books[i].titulo, tmp);
          
          tmp = strtok(NULL, ",");
          strcpy(books[i].acao, tmp);
          
           tmp = strtok(NULL, ",");
          strcpy(books[i].classe, tmp);
          
           tmp = strtok(NULL, ",");
          strcpy(books[i].contem, tmp);


        i++;
    }
	
//SHELL SORT E IMPRIMIR
	shellsort(books);
		
//FECHAR
    fclose(bookFile);
    return 0;

    system("pause");
    return 0;
}

void shellsort(struct book intArray[]){
	int inner, outer;
	struct book valueToInsert[99];
	int interval = 1;   
	int elements = 99;
	int i = 0;
   
   
	while(interval <= elements/3) {
		interval = interval*3 +1;
	}
	
	while(interval > 0) {
		
		for(outer = interval; outer < elements; outer++) {
valueToInsert[outer] = intArray[outer];
inner = outer;

while(inner > interval -1 && intArray[inner - interval].codigo >= valueToInsert[outer].codigo) {
intArray[inner] = intArray[inner - interval];
inner -=interval;
}

intArray[inner] = valueToInsert[outer];
}
		
		interval = (interval -1) /3;
		i++;
	}
	
//IMPRIMIR
	int j;
    for (j = 0; j <= MAX_BOOKS; j++)
    {
        if (intArray[j].codigo != 0)
        printf("index i= %i  Codigo: %i | titulo no Brasil: %s |Genero: %s | Classificacao atribuida: %s |Contem: %s |\n",j, intArray[j].codigo,intArray[j].titulo,intArray[j].acao,intArray[j].classe,intArray[j].contem);
        else
            break;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Input.h"

int isNumber(char* cadena){
	int retorno =1;
	int i =0;

	if(cadena[0]=='-'){
		i=1;
	}

	for( ;cadena[i]!='\0';i++){
		if(cadena[i]>'9'|| cadena[i]<'0'){
			if(cadena[i]==46){
				continue;
			}
			retorno=0;
			break;
		}
	}
	return retorno;
}

int getInt(int* entero,char mensaje[]){
	char buffer[100];

	printf("%s",mensaje);
	scanf("%s", buffer);

	while(isNumber(buffer)==0){
		printf("ERROR, ingrese un valor correcto\n");
		printf("%s",mensaje);
		scanf("%s", buffer);
	}
	*entero=atoi(buffer);

	return 0;
}

int getFloat(float* flotante, char mensaje[]){
	char buffer[100];

	printf("%s",mensaje);
	scanf("%s", buffer);

	while(isNumber(buffer)==0){
			printf("ERROR, ingrese un valor correcto \n");
			printf("%s",mensaje);
			scanf("%s", buffer);
		}
		*flotante=atof(buffer);

	return 0;
}


int getString(char* cadena ,int tamano, char mensaje[]){

	printf("%s",mensaje);
	fflush(stdin);
	fgets(cadena,tamano,stdin);
	cadena[strlen(cadena)-1]='\0';

	return 0;
}


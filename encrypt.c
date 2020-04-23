#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificare_nr(char *sir) { //functie pentru a verifica daca un sir este numar sau nu
	int i, nr=1;
	
	for(i=0;i<strlen(sir);i++) {
		
			if(sir[i] >= 48 && sir[i] <= 57)
				nr++;
			else
				{ nr=0;
				break;
				}
	}

	return nr;
}


int main()
{
	int n, i, j;
char **a;


scanf("%d\n", &n); //retinem numarul de linii

a=malloc(n*sizeof(char *));
for(i=0;i<n;i++) { //citim liniile
	char s[200];
	fgets(s, 200, stdin);
	a[i]=malloc(200*sizeof(char));
	strcpy(a[i], s); //liniile le copiez intr-un vector alaturat
}

for(i=0;i<n;i++) {
	char *token;
	token=strtok(a[i]," "); //sparg in tokeni sirul
	while(token != NULL) {
		if (verificare_nr(token)) { //verific daca token-ul este numar 
			printf("%s", token); //in caz afirmativ il afisez
		}
		else {
			char aux;
			aux=token[0]; //retin prima litera
			//printf(" ");
			printf("%c", token[0]);
			for(j=1;j<strlen(token);j++) {
				char cod;
				if (token[j] != '\n') { // verific caraterul retinut sa nu fie '\n' 
					cod=token[j];
					token[j]=(cod+aux)%256; //adaug la codul ASCII al caracterelor token-ului codul primului caracter
					printf("%c", token[j]);
				} 
			}
		}
		token=strtok(NULL," \n");
			if(token != NULL) {
				printf(" ");
			}
	}
	printf("\n");
}
	

for(i=0;i<n;i++) {
	free(a[i]); //eliberez memoria
}

free(a);

	return 0;
}

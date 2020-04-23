#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strdel(char* p, int n)   //functie de stergere 
{
        // nu exista mai mult de n caractere incepand de la pozitia p
        if (strlen(p) <= n) {
                *p = '\0';
                return p;
                }

        //in caz contrar, facem stergerea copiind caracterele de la p+n peste cele de la p
        strcpy(p, p + n);
        return p;
}

char* strins(char* p, char *s) //functie de inserare
{
        // copiem sirul din p intr-o alta locatie
        char *tail_p = strdup(p);

        // copiem la pozitia p noul sir
        strcpy(p, s);

        // copiem la sfarsit caracterele care existau inainte in p
        strcat(p, tail_p);
		free(tail_p);
        return p;
}


int main()
{
char cautat[30], cautat3[30], **a;
int n, i;
char *p;


fgets(cautat, 30, stdin); //citim cuvantul ce va fi cautat

cautat[strlen(cautat) - 1] = '\0';

scanf("%d ", &n); //se va introduce numarul de linii 

a=malloc(n*sizeof(char *));


for (i=0; i < n; i++) { //se citesc stringurile 
	char s[200];
	fgets(s, 200, stdin); 
	a[i]=malloc(200*sizeof(char));
	strcpy(a[i], s);
	
}

//copiem intr-o alta variabila secventa ce trebuie cautata impreuna cu codurile pentru a colora cu rosu
strcpy(cautat3,"\e[0;31m");
strcat(cautat3,cautat);
strcat(cautat3,"\e[m");


//inlocuiesc fiecare aparitie a secventei cautate cu cea colorata
for(i=0;i<n;i++) {
    for (p = strstr(a[i], cautat); p != NULL; p = strstr(p + strlen(cautat3), cautat)) {
	
                strdel(p,strlen(cautat)); //introduc sirul colorat in locul sirului initial
                strins(p,cautat3);
	if(strstr(p+strlen(cautat3),cautat)==NULL)
		printf("%s",a[i]);
   } 
}

//eliberez memoria
for(i=0;i<n;i++) {
	free(a[i]);
}

free(a);	

	return 0;
}

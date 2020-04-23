#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sortare_descrescatoare(float v[], int n) {//functie petru sortarea descrescatoare a vectorilor
	int i, j;
	for(i=0;i<n-1;i++) {
		for(j=i+1;j<n;j++) {  
			if(v[i] < v[j]) {
				float aux;
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;		
			}
		}
	} 

}

int sum(int v[], int i) { //functie pentru calcularea sumei unui vector
	int sum, j; 
	sum=0;
	for(j=0;j<i;j++) {
		sum=sum+v[j];
	}
return sum;
}



int main()
{int **a,  i, j=0, k, col[100], n, x, suma[100];
float  med[100], copie[100];


scanf("%d", &n); // n=numarul materiilor

a=malloc(n*sizeof(int*)); //matricea este complet alocata dinamic
for(i=0;i<n;i++) {
	a[i]=(int*)malloc(3*sizeof(int));  //linia ese alocata initial cu o dimensiune maxima initiala 3
	do { /////citesc matricea
		scanf("%d", &a[i][j]);
		x=a[i][j]; //retin fiecare element al matricei intr-o variabila pentru a o compara cu zero
		j++; //cresc cu o unitate numarul notelor
		if(j%3==2)
			a[i] = realloc(a[i], (j+4)*sizeof(int)); //dimensiunea este marita de fiecare data cu 3 atunci cand este depasita dimensiunea deja alocata
		col[i]=j; //retin intr-un vector numarul notelor(coloanelor) fiecarei materii(linii)
		
	} while(x != 0);
	j=0; 

}
 
for(i=0;i<n;i++) {  /// calculez suma notelor de pe fiecare linie
		suma[i]=sum(a[i], col[i]);
	
}
for(i=0;i<n;i++){  //calculez feicare medie de pe fiecare linie
	
		med[i]=(float)suma[i]/(col[i]-1);
		copie[i]=med[i]; //retin intr o matrice alaturata

} 

sortare_descrescatoare(med, n); //sortez vectorul mediilor descrescator

for(i=0;i<n;i++) {    ///afsisez matricea ordonata descrescator in functie de media fiecarei materii
	 printf("%-10.3f", med[i]);
	for(k=0;k<n;k++) {
		if(med[i]==copie[k]) { copie[k]=-100; 
			for(j=1;j<col[k];j++) {
		
			 printf("%d ", a[k][j-1]); 

			} 
		break;
		}
	
	}
printf("\n");
}
//eliberez memoria matricei
for(i=0;i<n;i++) {
	free(a[i]);
}

free(a);

return 0;
}

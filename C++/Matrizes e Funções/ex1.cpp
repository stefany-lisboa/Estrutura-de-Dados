#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
using namespace std;

#define TAM 10

int soma = 0;
int *psoma = &soma;
	
double media = 0;
double *pmedia = &media;
	
int maiores = 0;
int *pmaiores = &maiores;


	
void calcula_media(int p[])
{	
    for(int i=0; i<TAM; i++)
	{		
		*psoma += p[i]; 
	}
	
	*pmedia = (double)*psoma/TAM;
	cout << "Média: " << *pmedia << endl;
	
}

void mostra_maior(int p[], int media)
{
	cout << "Números acima da média: ";
	for(int i=0; i<TAM; i++)
		
		{
			if (p[i] > media){
				*pmaiores += 1;
				
				cout << p[i] << " ";
			}	
		}
	cout << "\nQuantidade de números acima da média: " << *pmaiores << endl;
}

int main(){
	
	setlocale(LC_ALL,"");
	int *v1;
	
		v1 = (int*)malloc(sizeof(int)*TAM);
		
		for(int i=0; i<TAM; i++)
		{
			cin >> v1[i];

		}
		
		 calcula_media(v1);
		 mostra_maior(v1, *pmedia);
		 
		 	
		free(v1);

	return 0;
}


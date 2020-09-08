#include <stdio.h>
#include <stdlib.h>


int main()
{
	
	int *m;
	int i,j;
	int k;
	int x;
	int conf;
	int totaldoce = 0;
	int totalsalgada = 0;
	int vlsubdoce = 0;
	int vlsubsalgada = 0;


	

	int fconf;
	int *pfconf;
	pfconf = &fconf;
	
	
	
	int car;
	int *pcar;
	pcar = &car;
	
	int sabor;
	int *psabor;
	psabor = &sabor;
	
	int qtde;
	int *pqtde;
	pqtde = &qtde;
	
	int elemento;
	
	m = (int*)malloc(2 * 15 * sizeof(int));


	for (x=0; x<30; x++ )
	{
		*(m+x)=0;
	}

		
	k=0;
	for (i=0; i<15;++i)
	{
		for (j=0; j<2; ++j)
		{
	
			k++;
		}

	}
	conf = 1;

	while (conf == 1){
		
	
	printf("Digite o numero do carrinho: ");
	scanf("%i", &car);	
	while (*pcar > 15){
	printf("Digite o numero do carrinho: ");
	scanf("%i", &car);
	}

	 
	printf("\n\n 1 - Doce \n\n 2 - Salgada:  ");
	scanf("%i", &sabor);
	
	
	while (*psabor != 1 && *psabor !=2){
	printf("\n\n 1 - Doce \n\n 2 - Salgada:  ");
	scanf("%i", &sabor);

	}
	

	printf("\n");
	
	printf("Digite a quantidade vendida: ");
	scanf("%i", &qtde);

	printf("\n");
	
	
	
	if (*psabor == 1){
		
		
		elemento = ((*pcar * 2) -2);
		*(m+elemento)+= *pqtde;
		while (*psabor != 1){
	printf("\n\n 1 - Doce \n\n 2 - Salgada:  ");
	scanf("%i", &sabor);
	printf("a");
	}

		
	}
	else{
		elemento = ((*pcar * 2) -1);
		*(m+elemento)+= *pqtde;

	}	
	
	 
	printf("\n\n 1 - Nova venda \n\n 2 - Mostrar tabela \n\n 3 - Encerrar: \n\n ");
	scanf("%i", &fconf);
	printf("\n");
	conf = *pfconf;
	
	


	
	if(conf == 2){
		k = 0;
	

	printf("\t \t Doce");
	printf("\t Valor Doce");	
	printf("\t Salgada");
	printf("\t Valor Salgada");
	
	printf("\n");
	for (i=0; i<15;++i)
	{
		
		printf("Carrinho %i:\t", i+1);
		for (j=0; j<2; ++j)
		{
			
			if(j == 0){
				
				printf("%i\t\t ", *(m + k) );			
				printf("%i\t\t", (*(m + k) * 5));
				totaldoce += *(m + k) * 5 ;
					
			
			}
			else{
				printf("%i\t\t", *(m + k) );
				printf("%i\t\t", (*(m + k) * 7));
				
				totalsalgada += *(m + k) * 7 ;
			}
			k++;
		}
		printf("\n");
		

	}
	

	


	printf("Doce: R$ %i\n", totaldoce);
	printf("Salgada: R$ %i", totalsalgada);
	printf("\n\n 1 - Nova venda \n\n 2 - Encerrar: \n\n ");
	scanf("%i", &fconf);
	printf("\n");
	conf = *pfconf;
	vlsubdoce = totaldoce;
	vlsubsalgada = totalsalgada;
	
	if(vlsubdoce > 0){

		totaldoce -=vlsubdoce;
	}

	
	if(vlsubsalgada > 0){

		totalsalgada -=vlsubsalgada;
	}
	
	
	}
	
	if(conf == 2){
		conf = 3;
	}
	if(conf == 3){
		printf("Fim");
	}
	}
	
	return(0);
}
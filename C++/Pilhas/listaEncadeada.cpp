 
 #include <iostream>
using  namespace std;

#define MAX 30

struct Par{
	float dado;
	struct Par *prox;
}; 

struct Impar{
	float dado;
	struct Impar *prox;
}; 

struct Pilha{
	Par *topoPar;
	Impar *topoImpar;

};

Pilha* init(){
	Pilha *p = new Pilha;
	p->topoPar = NULL;
	p->topoImpar = NULL;
	return p;
}

int isEmptyPar(Pilha *p) {
	return (p->topoPar == NULL);
}

int isEmptyImpar(Pilha *p) {
	return (p->topoImpar == NULL);
}

void pushPar(Pilha *p, float v) {
	Par *par = new Par;
	par->dado = v;
	par->prox = p->topoPar;
	p->topoPar = par;
}

void pushImpar(Pilha *p, float v) {
	Impar *impar = new Impar;
	impar->dado = v;
	impar->prox = p->topoImpar;
	p->topoImpar = impar;
}

int modNum(int n){
	
	return (n%2 == 0);
}

void printPar(Pilha *p) {
	Par *par;
	par = p->topoPar;
	while(par != NULL) {
		cout << par->dado << endl;
		par = par->prox;
	}
	cout << "------------------------" << endl;
}

void printImpar(Pilha *p) {
	Impar *impar;
	impar = p->topoImpar;
	while(impar != NULL) {
		cout << impar->dado << endl;
		impar = impar->prox;
	}
	cout << "------------------------" << endl;
}



void printBoth(Pilha *p) {
	

	Impar *impar;
	impar = p->topoImpar;
	Par *par;
	par = p->topoPar;
	while(impar != NULL || par !=NULL) {

		if(par !=NULL && impar !=NULL){
			if(par->dado > impar->dado){
					  		
			cout << par->dado << endl;
			par = par->prox;
			}
			else{
			cout << impar->dado << endl;
			impar = impar->prox;
			}
		}
		else if(par !=NULL && impar == NULL){
			cout << par->dado << endl;
			par = par->prox;
		}
		else if(par == NULL && impar != NULL){
			cout << impar->dado << endl;
			impar = impar->prox;
		}
							   		
	}
	cout << "------------------------" << endl;
}



int countPar(Pilha *p) {
	int qtde = 0;
	Par *par;
	par = p->topoPar;
	while(par != NULL) {
        qtde++;   
		par = par->prox;
	}
	return qtde;
}

int countImpar(Pilha *p) {
	int qtde = 0;
	Impar *impar;
	impar = p->topoImpar;
	while(impar != NULL) {
        qtde++;   
		impar = impar->prox;
	}
	return qtde;
}



int main(int argc, char** argv)
{
	float num;
	float maior;
	
	Pilha *pilhaFloat;
	pilhaFloat = init();
	
	cout << "Pilha par vazia: " << (isEmptyPar(pilhaFloat)?"Sim":"Nao") << endl;
	cout << "Pilha impar vazia: " << (isEmptyImpar(pilhaFloat)?"Sim":"Nao") << endl;
	
	
	for(int i=0; i<MAX; i++){
		cout << "Digite um número" << endl;
		cin >> num;
		
		if(i == 0){
			maior = num;
		}
		else if(i > 0){
			while(maior >= num){
				cout << "Digite um numero maior do que o anterior" << endl;
				cin >> num;
			}
			maior = num;
		}
		
		
		if(modNum(num)){
			pushPar(pilhaFloat, num);
		}
		else{
			pushImpar(pilhaFloat, num);
		}
		
		
	}
	
	cout << "Pilha de numeros pares: " << endl;
	printPar(pilhaFloat);
	
	cout << "Pilha de numeros impares: " << endl;
	printImpar(pilhaFloat);
		
	cout << "Quantidade de pares: ";
	cout << countPar(pilhaFloat) << endl;
	
	cout << "Quantidade de impares: ";
	cout << countImpar(pilhaFloat) << endl;


	cout << "Ambas as pilhas: " << endl;
	printBoth(pilhaFloat);	
	
	

		
	cout << "Pilha par vazia: " << (isEmptyPar(pilhaFloat)?"Sim":"Nao") << endl;
	cout << "Pilha impar vazia: " << (isEmptyImpar(pilhaFloat)?"Sim":"Nao") << endl;	
	
	return 0;
}


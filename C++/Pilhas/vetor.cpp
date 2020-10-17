 
 #include <iostream>
using  namespace std;

#define MAX 30

struct Pilha {
	int qtde;
	float nos[MAX];
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->qtde == 0);
}

int count(Pilha *p) {
	return p->qtde;
}
int modNum(int n){
	
	return (n%2 == 0);
}
int push(Pilha *p, float v) {
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar) {
		p->nos[p->qtde] = v;
		p->qtde++;
	}
	return podeEmpilhar;
}

float pop(Pilha *p) {
	float ret;
	int podeDesempilhar = (p->qtde > 0);
	if (podeDesempilhar) {
		ret = p->nos[p->qtde - 1];
		p->qtde--;
	}
	else
	{
		ret = -1;
	}
	return ret;
}

void print(Pilha *p) {
	for(int i = p->qtde-1; i >= 0; --i) {
		cout << p->nos[i] << endl;
	} 
	cout << "------------------" << endl;
}

void printBoth(Pilha *a, Pilha *b){
	int x = a->qtde-1;
	int y = b->qtde-1;	
	while(a->qtde != 0 || b->qtde !=0){

			
		
		if(x+1 != 0 && y+1 != 0){			
			if(a->nos[x] > b->nos[y]){
				cout << a->nos[x] << endl;
				--x;
			}
			else{
				cout << b->nos[y] << endl;
				--y;
			}
		}
		else if(x+1 != 0 && y+1 == 0){
				cout << a->nos[x] << endl;
				--x;
		}
		else if(x+1 == 0 && y+1 !=0){
			cout << b->nos[y] << endl;
			--y;
		}
		
	
		}				
}

void freePilha(Pilha *p)
{
	free(p);
}

int main(int argc, char** argv)
{
	
	float num;
	float maior; 
	
	
	Pilha *pilhaPar;
	Pilha *pilhaImpar;	
	
	pilhaPar = init();
	pilhaImpar = init();
	
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
			push(pilhaPar, num);
		}
		else{
			push(pilhaImpar, num);
		}		
	}
	
	cout << "Pilha par vazia: " << (isEmpty(pilhaPar)?"Sim":"Nao") << endl;
	cout << "Pilha impar vazia: " << (isEmpty(pilhaImpar)?"Sim":"Nao") << endl;

	cout << "Pilha de numeros pares:" << endl;
	print(pilhaPar);
	cout << "Pilha de numeros impares:" << endl;
	print(pilhaImpar);
	
	cout << "Ambas as pilhas: " << endl;
	printBoth(pilhaPar, pilhaImpar);

	return 0;
}
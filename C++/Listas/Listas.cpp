#include <iostream>
using namespace std;

struct Funcionario
{
	int prontuario;
	string nome;
	double salario;
};

struct Lista
{
	Funcionario dado;
	struct Lista *prox;
};

Lista* init()
{
	return NULL;
}


int isEmpty(Lista* lista)
{
	return (lista == NULL);
}


Lista* insert(Lista* lista, Funcionario i)
{
	Lista* novo = new Lista;
	novo->dado = i;
	novo->prox = lista;
	return novo;
}


void print(Lista* lista)
{
	Lista* aux;
	aux = lista;
	while (aux != NULL)
	{
		cout << "Prontuario: " << aux->dado.prontuario << ", ";
		cout << "Nome: " << aux->dado.nome << ", ";
		cout << "Salario: " << aux->dado.salario << endl;
		aux = aux->prox;
	}
}

double totalSalario(Lista* lista)
{
	Lista* aux;
	aux = lista;
	double sltotal = 0;
	while (aux != NULL)
	{

		sltotal += aux->dado.salario;
		aux = aux->prox;
	}
	return sltotal;
}

Lista* find(Lista* lista, int i)
{
	Lista* aux;
	aux = lista;
	while (aux != NULL && aux->dado.prontuario != i)
	{
		aux = aux->prox;
	}
	if (aux == NULL)
	{
		aux = new Lista;
		aux->dado.prontuario = -1;
		aux->dado.nome = "";
		aux->dado.prontuario = -1;
		aux->prox = NULL;
	}
	return aux;
}

Lista* remove(Lista* lista, int i)
{
	Lista *ant = NULL;
	Lista *aux;
	
	aux = lista;
	while (aux != NULL && aux->dado.prontuario != i)
	{
		ant = aux;
		aux = aux->prox;
	}
	if (aux == NULL)
	{
		return lista;
	}
	if (ant == NULL) 
	{
		lista = aux->prox;
	}
	else
	{
		ant->prox = aux->prox;
	}
	free(aux);
	return lista;
}

void freeList(Lista* lista)
{
	Lista *aux;
	aux = lista;
	while (aux != NULL)
	{
		Lista *ant = aux->prox;
		free(aux);
		aux = ant;
	}
}

int main(int argc, char** argv)
{
    int escolha = 0;
    int pront = 0;
	Lista *minhaLista;
	minhaLista = init();
	
	//cout << "Lista vazia: " << (isEmpty(minhaLista)?"Sim":"Nao") << endl;
	Funcionario novoF;
	
	cout << "0. Sair" << endl;
	cout << "1. Incluir" << endl;
	cout << "2. Excluir" << endl;
	cout << "3. Pesquisar" << endl;
	cout << "4. Listar" << endl;
	
	cout << "Digite um numero : ";
	cin >> escolha;
	while (escolha != 0)
	{
		if(escolha == 1){
		    int verificapront = 0;
		    cout << "Inserir" << endl;
		    cout << "Digite o prontuario do funcionario: " << endl;
		    cin >> verificapront;
		    Lista *procurado = find(minhaLista,verificapront); 
	        if (procurado->dado.prontuario == verificapront)
	        {
  	            cout << "Já existe um funcionario com este prontuario" << endl;
	        }
            else
            {
   	            novoF.prontuario = verificapront;
   	            cout << "Digite o nome do funcionario: " << endl;
	            cin >> novoF.nome;
	            cout << "Digite o salario do funcionario: " << endl;
	            cin >> novoF.salario;
	            minhaLista = insert(minhaLista, novoF);
            }
		       
		}
		if(escolha == 2){
		    
		    cout << "Excluir" << endl;
		    cout << "Digite o prontuario do funcionario: " << endl;
		    cin >> pront;
		    minhaLista = remove(minhaLista, pront);
		    
		    
		}
		if(escolha == 3){
		    cout << "Encontrar" << endl;
		    cout << "Digite o prontuario do funcionario: " << endl;
		    cin >> pront;
		    Lista *procurado = find(minhaLista,pront); 
	        if (procurado->dado.prontuario > -1)
	        {
  	            cout << "Resultado da busca: " << endl;
  	            cout << "Prontuario: " << procurado->dado.prontuario << ", ";
  	            cout << "Nome: " << procurado->dado.nome << ", ";
  	            cout << "Salario: " << procurado->dado.salario << endl;
	        }
            else
            {
   	            cout <<"Nao encontrado" << endl;
            }
		    
		}
		if(escolha == 4){
		    cout << "Listar" << endl;
		    print(minhaLista);	
		    cout << "Valor total dos salarios: " << totalSalario(minhaLista);
		}
		
		cout << "0. Sair" << endl;
	    cout << "1. Incluir" << endl;
	    cout << "2. Excluir" << endl;
	    cout << "3. Pesquisar" << endl;
	    cout << "4. Listar" << endl;
		cout << "Digite um numero : ";
	    cin >> escolha;
	}
	
	freeList(minhaLista);  
	
	return 0;
}
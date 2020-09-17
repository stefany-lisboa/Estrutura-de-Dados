#include <iostream>
using namespace std;
#include <time.h>
 #include <locale.h>

class Data
{
	private: 	
	   int dia;
	   int mes;
	   int ano;	
    public:
    	Data(int dia, int mes, int ano)
		{
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
		}
		Data()
		{
			this->dia = 0;
			this->mes = 0;
			this->ano = 0;
		}
    	void setDia(int dia)
    	{
			this->dia = dia;
		}
		void setMes(int mes)
    	{
			this->mes = mes;
		}
		void setAno(int ano)
    	{
			this->ano = ano;
		}
		int getDia()
		{
			return this->dia;
		}
		int getMes()
		{
			return this->mes;
		}
		int getAno()
		{
			return this->ano;
		}
		string getData()
		{
		    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
		}
		Data* dia_seguinte()
		{
			int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			Data *d1 = new Data(this->dia, this->mes, this->ano);
			
			if (d1->ano%4 == 0)
			{
				diasNoMes[1]++;
			}
			
			d1->dia++;
			if (d1->dia > diasNoMes[d1->mes-1])
			{
				d1->dia = 1;
				if (++d1->mes > 12)
				{
					d1->mes = 1;
					d1->ano++;
				}
			}
			
			return d1;
		}
};

class Contato{
    private:
        string email;
        string nome;
        string dtnasc;
        string telefone;

    public: 
    
    
        Contato(string email, string nome, string dtnasc, string telefone)
        {
          this->email = email;
          this->nome = nome;
          this->dtnasc = dtnasc;
          this->telefone = telefone;
        }
        
        Contato()
        {
          this->email = "";
          this->nome = "";
          this->dtnasc = "";
          this->telefone = "";

        }
        
        void setEmail(string email){
          this-> email = email;  
        }
        
        void setNome(string nome){
          this-> nome = nome;  
        }

        void setDtnasc(string dtnasc){
          this-> dtnasc = dtnasc;  
        }
        
        void setTelefone(string telefone){
          this-> telefone = telefone;  
        }
        
        string getEmail(){
            return this-> email;
        }
        string getNome(){
            return this-> nome;
        }
        
        string getDtnasc(){
            return this-> dtnasc;
        }
        
        string getTelefone(){
            return this-> telefone;
        }        
        
        string getDados(){
            return "Nome: " + this->nome + "\nEmail: " + this->email + "\nData de Nascimento " + this->dtnasc + "\nTelefone: " + this->telefone; 
        }
        
        int getIdade(int cDia, int cMes, int cAno){
  
            time_t mytime;
            mytime = time(NULL);
            struct tm tm = *localtime(&mytime);
            int idade = 0;
            
            if(tm.tm_mon + 1 > cMes)
            {
             idade = tm.tm_year + 1900 - cAno;
            }
            else if(tm.tm_mon + 1 == cMes){
                if(tm.tm_mday >= cDia){
                    idade = tm.tm_year + 1900 - cAno;
                }
                else{
                    idade = tm.tm_year + 1900 - cAno - 1;
                }
            }
            else if (tm.tm_mon + 1 < cMes){
                idade = tm.tm_year + 1900 - cAno;
            }
            return idade;
        }
};





int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
    string email[10] = "";
    string nome[10] = "";
    int dia[10];
    int mes[10];
    int ano[10];
    string telefone[10] = "";
    int idade[10];
    double soma =0;
    double media=0;
    int cont=0;
    int maior = 0;
    int maisvelho = 0;
    
    
    for (int i = 0; i<=9; i++) {
    cout << "Contato " << i+1 << endl;
    cout << "Digite seu email: ";
    cin >> email[i];
    cout << "Digite seu nome: ";
    cin >> nome[i];
    cout << "Digite o dia em que você nasceu: ";
    cin >> dia[i];
    cout << "Digite o mes em que você nasceu: ";
    cin >> mes[i];  
    cout << "Digite o ano em que você nasceu: ";
    cin >> ano[i];   
    cout << "Digite o seu telefone: ";
    cin >> telefone[i];
    }

    //cout << nasc->getData() << endl;


    Data *nasc = new Data[10];
    Contato *dados = new Contato[10];
    for (int i = 0; i<=9; i++) {
        
        
    
    nasc[i] = Data(dia[i], mes[i], ano[i]);
        
    
    dados[i] = Contato(""+email[i]+"", ""+nome[i]+"", ""+nasc[i].getData()+"", ""+telefone[i]+"");
    
    
    cout << "\n" << dados[i].getDados() << endl; 
    
    cout << "Idade: ";
    
    idade[i] = dados[i].getIdade(nasc[i].getDia(), nasc[i].getMes(), nasc[i].getAno());
    cout << idade[i] << endl; 
    soma +=idade[i];
    
    
    }
    media = soma/10;
    cout << "\nMédia de idade dos contatos: " << media << endl;
    cout << "\nContatos com idade maior do que a média: " << endl;
    for (int i = 0; i<=9; i++) {
        
        if(idade[i] > media){
            cout << dados[i].getNome() <<endl;
            cont += 1;
        } 
        
        if ((i == 9) && (cont == 0))
        {
            cout<< "Nenhum" << endl;
        }
        
        if (idade[i] >= 18){
            maior +=1;
        }
        
        
        if (idade[i] > maisvelho){
            maisvelho = idade[i];
        }
    }
    

    cout << "\nQuantidade de contatos maiores de idade: " << maior << endl;
    cout << "\nContatos mais velhos: " << endl;
    for (int i; i<=9; i++){
        if (idade[i] == maisvelho){
            cout << dados[i].getNome() <<endl;
            cout << dados[i].getEmail() <<endl;
            cout << dados[i].getTelefone() <<endl;
            cout << "\n";
        }
    }
    
    
    
    
    
    
    //Data *amanha = nasc->dia_seguinte();
    //cout << amanha->getData() << endl;

	 
	return 0;
}
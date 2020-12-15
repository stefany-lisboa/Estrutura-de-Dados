using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrabED08_12c.Models
{
    class Contato
    {
        private string email;
        private string nome;
        private string telefone;
        private Data dtNasc;

        public Contato()
        {
            email = "";
            nome = "";
            telefone = "";
            dtNasc = new Data();
        }

        public string Email
        {
            get { return email; }
            set { email = value; }
        }

        public string Nome
        {
            get { return nome; }
            set { nome = value; }
        }

        public string Telefone
        {
            get { return telefone; }
            set { telefone = value; }
        }

        public Data DtNasc
        {
            get { return dtNasc; }
            set { dtNasc = value; }
        }

        public int getIdade()
        {
            DateTime hoje = DateTime.Today;
            DateTime nas = DateTime.Parse(DtNasc.ToString());

            int idade = hoje.Year - nas.Year;

            if (hoje.Month <= nas.Month && hoje.Day <= nas.Day)
            {
                idade--;
            }

            return idade;
        }

        public override string ToString()
        {
            return "Nome: " + nome + ", Email: " + email + ", Telefone: " + telefone + ", Idade: " + getIdade();
        }

        public override bool Equals(object obj)
        {
            return this.Nome.Equals(((Contato)obj).Nome);
        }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trabalho10_11
{
    class Venda
    {
        private int qtde;
        private double valor;


        public Venda()
        {
            qtde = 0;
            valor = 0.0;
        }

        public Venda(int qtde, double valor)
        {
            this.qtde = qtde;
            this.valor = valor;
        }


        public int Qtde
        {
            get { return qtde; }
            set { qtde = value; }
        }

        public double Valor
        {
            get { return valor; }
            set { valor = value; }
        }

        
        public double valorMedio()
        {
            return valor / qtde;
        }
    }
}

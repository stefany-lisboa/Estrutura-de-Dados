﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trabalho10_11
{
    class Vendedores
    {
 
        private Vendedor[] osVendedores;
        private int max;
        private int qtde;

        public Vendedores(int max)
        {
            this.max = max;
            this.qtde = 0;
            this.osVendedores = new Vendedor[this.max];
            for (int i = 0; i < this.max; ++i)
            {
                this.osVendedores[i] = new Vendedor();
            }
        }

        public int Qtde
        {
            get { return qtde; }
            set { qtde = value; }
        }

        public Vendedor[] OsVendedores
        {
            get { return osVendedores; }
            set { osVendedores = value; }
        }

        public bool addVendedor(Vendedor vendedor)
        {
            bool podeAdicionar = (this.qtde < this.max);
            if (podeAdicionar)
            {
                this.osVendedores[this.qtde] = vendedor;
                this.qtde++;
            }
            return podeAdicionar;
        }

        public bool delVendedor(Vendedor vendedor)
        {
            bool temVendedor = false;
            foreach (Vendedor v in this.osVendedores)
            {
                if (v.Equals(vendedor))
                {
                    v.Id = -1;
                    v.Nome = "";
                    v.PercComissao = 0.0;
                    v.AsVendas = new Venda[31];
                    temVendedor = true;
                }
            }
            return temVendedor;
        }

        public Vendedor searchVendedor(string nome)
        {
            Vendedor vendedorAchado = new Vendedor();
            int i = 0;
            while (i < this.max && !this.osVendedores[i].Nome.Equals(nome))
            {
                i++;
            }
            if (i < this.max)
            {
                vendedorAchado = this.osVendedores[i];
            }
            return vendedorAchado;
        }

        public double valorVendas()
        {
            double valorTotal = 0.0;

            foreach (Vendedor v in this.osVendedores)
            {
                valorTotal += v.valorVendas();
            }

            return valorTotal;
        }

        public double valorComissao()
        {
            double valorTotal = 0.0;

            foreach (Vendedor v in this.osVendedores)
            {
                valorTotal += v.valorComissao();
            }

            return valorTotal;
        }

    }
}

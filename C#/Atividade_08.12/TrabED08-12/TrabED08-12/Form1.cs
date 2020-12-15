using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TrabED08_12.Models;

namespace TrabED08_12
{
    public partial class Form1 : Form
    {
        Contatos contatos = new Contatos(10);
        string email = "";
        public Form1()
        {
            
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnNovo_Click(object sender, EventArgs e)
        {
            tbEmail.Text = "";
            tbNome.Text = "";
            tbFone.Text = "";
            tbDia.Text = "";
            tbMes.Text = "";
            tbAno.Text = "";
        }
      
        private void btnGravar_Click(object sender, EventArgs e)
        {
            Contato contato = new Contato();
            contato.Nome = tbNome.Text;
            contato.Email = tbEmail.Text;
            contato.Telefone = tbFone.Text;
            Data data = new Data();
            data.setData(int.Parse(tbDia.Text), int.Parse(tbMes.Text), int.Parse(tbAno.Text));
            contato.DtNasc = data;

            contatos.adicionar(contato);

            tbEmail.Text = "";
            tbNome.Text = "";
            tbFone.Text = "";
            tbDia.Text = "";
            tbMes.Text = "";
            tbAno.Text = "";
        }

        private void btnPesquisar_Click(object sender, EventArgs e)
        {
            Contato contato = new Contato();

            contato.Email = tbEmail.Text;

            contato = contatos.pesquisar(contato);

            if (contato.Email != "")
            {
                tbEmail.Text = contato.Email;
                tbNome.Text = contato.Nome;
                tbFone.Text = contato.Telefone;
                tbDia.Text = contato.DtNasc.Dia.ToString();
                tbMes.Text = contato.DtNasc.Mes.ToString();
                tbAno.Text = contato.DtNasc.Ano.ToString();

            }
            else
            {
                MessageBox.Show("Não encontrado!");
            }

        }

        private void btnExcluir_Click(object sender, EventArgs e)
        {

            Contato contato = new Contato();

            contato.Nome = tbNome.Text;
            contato.Email = tbEmail.Text;

            bool excluiu = contatos.remover(contato);

            if (excluiu)
            {
                MessageBox.Show("Sucesso!");
            }
            else
            {
                MessageBox.Show("Falha!");
            }
        }

        private void btnListar_Click(object sender, EventArgs e)
        {
            lbContato.Items.Clear();
            foreach (Contato c in contatos.Agenda)
            {
                if (c.Nome != "")
                {
                    lbContato.Items.Add(c.ToString());
                }
            }
        }

        private void lbContato_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}

﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TrabED08_12c.Models;

namespace TrabED08_12c
{
    class Program
    {
        static void Main(string[] args)
        {
            Contatos contatos = new Contatos(10);
            int opc;
            Console.WriteLine("0. Sair");
            Console.WriteLine("1. Adicionar contato");
            Console.WriteLine("2. Pesquisar contato");
            Console.WriteLine("3. Alterar contato");
            Console.WriteLine("4. Remover contato");
            Console.WriteLine("5. Listar contatos");
            Console.WriteLine("Escolha uma opção: ");
            opc = int.Parse(Console.ReadLine());

            while (opc != 0)
            {
                if (opc == 1)
                {
                    Contato contato = new Contato();

                    Console.WriteLine("Digite o nome: ");
                    string nome = Console.ReadLine();

                    Console.WriteLine("Digite o email: ");
                    string email = Console.ReadLine();

                    Console.WriteLine("Digite o telefone: ");
                    string telefone = Console.ReadLine();

                    Console.WriteLine("Digite o dia do nascimento: ");
                    int dia = int.Parse(Console.ReadLine());
                    Console.WriteLine("Digite o mes do nascimento: ");
                    int mes = int.Parse(Console.ReadLine());
                    Console.WriteLine("Digite o ano do nascimento: ");
                    int ano = int.Parse(Console.ReadLine());

                    Data data = new Data();
                    data.setData(dia, mes, ano);

                    contato.Nome = nome;
                    contato.Email = email;
                    contato.Telefone = telefone;
                    contato.DtNasc = data;

                    contatos.adicionar(contato);
                }
                if (opc == 2)
                {
                    Contato contato = new Contato();

                    Console.WriteLine("Digite o nome: ");
                    string nome = Console.ReadLine();
                    contato.Nome = nome;

                    contato = contatos.pesquisar(contato);

                    if (contato.Nome != "")
                    {
                        Console.WriteLine(contato.ToString());
                    }
                    else
                    {
                        Console.WriteLine("Não encontrado!");
                    }

                }
                if (opc == 3)
                {
                    Contato contato = new Contato();

                    Console.WriteLine("Digite o nome do contato existente: ");
                    string nome = Console.ReadLine();

                    Console.WriteLine("Digite o email: ");
                    string email = Console.ReadLine();

                    Console.WriteLine("Digite o telefone: ");
                    string telefone = Console.ReadLine();

                    Console.WriteLine("Digite o dia do nascimento: ");
                    int dia = int.Parse(Console.ReadLine());
                    Console.WriteLine("Digite o mes do nascimento: ");
                    int mes = int.Parse(Console.ReadLine());
                    Console.WriteLine("Digite o ano do nascimento: ");
                    int ano = int.Parse(Console.ReadLine());

                    Data data = new Data();
                    data.setData(dia, mes, ano);

                    contato.Nome = nome;
                    contato.Email = email;
                    contato.Telefone = telefone;
                    contato.DtNasc = data;

                    contatos.alterar(contato);
                }
                if (opc == 4)
                {
                    Contato contato = new Contato();

                    Console.WriteLine("Digite o nome: ");
                    string nome = Console.ReadLine();
                    contato.Nome = nome;

                    contatos.remover(contato);
                }
                if (opc == 5)
                {
                    foreach (Contato c in contatos.Agenda)
                    {
                        if (c.Nome != "")
                        {
                            Console.WriteLine(c.ToString());
                        }
                    }
                }

                Console.WriteLine("0. Sair");
                Console.WriteLine("1. Adicionar contato");
                Console.WriteLine("2. Pesquisar contato");
                Console.WriteLine("3. Alterar contato");
                Console.WriteLine("4. Remover contato");
                Console.WriteLine("5. Listar contatos");
                Console.WriteLine("Escolha uma opção: ");
                opc = int.Parse(Console.ReadLine());
            }

        }
    }
}

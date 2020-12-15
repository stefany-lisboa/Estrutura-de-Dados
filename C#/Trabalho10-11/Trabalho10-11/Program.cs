using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trabalho10_11
{
    class Program
    {
        static void Main(string[] args)
        {
            Vendedores vendedores = new Vendedores(10);
            int opc;
            Console.WriteLine("0. Sair");
            Console.WriteLine("1. Cadastrar vendedor");
            Console.WriteLine("2. Consultar vendedor");
            Console.WriteLine("3. Excluir vendedor");
            Console.WriteLine("4. Registrar venda");
            Console.WriteLine("5. Listar vendedores");
            Console.WriteLine("Escolha uma opção: ");
            opc = int.Parse(Console.ReadLine());

            while (opc != 0)
            {
                if (opc == 1)
                {
                    if (vendedores.Qtde < 10)
                    {
                        Vendedor vendedor = new Vendedor();
                        Console.WriteLine("Digite o nome: ");
                        string nome = Console.ReadLine();
                        vendedor.Id = vendedores.Qtde;
                        vendedor.Nome = nome;
                        vendedor.AsVendas = new Venda[31];

                        for (int i = 0; i < vendedor.AsVendas.Length; ++i)
                        {
                            vendedor.AsVendas[i] = new Venda();
                        }

                        vendedores.addVendedor(vendedor);
                    }
                    else
                    {
                        Console.WriteLine("Ta cheio: ");
                    }

                }

                if (opc == 2)
                {
                    Console.WriteLine("Digite o nome do vendedor: ");
                    string nome = Console.ReadLine();
                    Vendedor vendedorAchado = vendedores.searchVendedor(nome);
                    if (vendedorAchado.Id == -1)
                    {
                        Console.WriteLine("Vendedor não encontrado.");
                    }
                    else
                    {
                        Console.WriteLine("ID: " + vendedorAchado.Id);
                        Console.WriteLine("NOME: " + vendedorAchado.Nome);
                        Console.WriteLine("VALOR TOTAL VENDAS: " + vendedorAchado.valorVendas());
                        Console.WriteLine("VALOR COMISSÂO: " + vendedorAchado.valorComissao());
                        int dia = 0;
                        foreach (Venda v in vendedorAchado.AsVendas)
                        {
                            dia++;
                            if (v.Qtde > 0)
                            {
                                Console.WriteLine("Valor Médio de venda do dia " + dia + " foi: " + v.valorMedio());
                            }
                        }
                        dia = 0;
                    }                   
                }

                if (opc == 3)
                {
                    bool podeExcluir = true;
                    Console.WriteLine("Digite o nome do vendedor: ");
                    string nome = Console.ReadLine();
                    Vendedor vendedorAchado = vendedores.searchVendedor(nome);
                    if (vendedorAchado.Id == -1)
                    {
                        Console.WriteLine("Vendedor não encontrado.");
                    }
                    else
                    {
                        foreach (Venda v in vendedorAchado.AsVendas)
                        {
                            if (v.Qtde > 0)
                            {
                                podeExcluir = false;
                            }
                        }

                        if (podeExcluir)
                        {
                            vendedores.delVendedor(vendedorAchado);
                        }
                        else
                        {
                            Console.WriteLine("Vendedor com alguma venda não pode ser deletado.");
                        }
                    }                   
                }

                if (opc == 4)
                {
                    Console.WriteLine("Digite o nome do vendedor: ");
                    string nome = Console.ReadLine();
                    Vendedor vendedorAchado = vendedores.searchVendedor(nome);
                    if (vendedorAchado.Id == -1)
                    {
                        Console.WriteLine("Vendedor não encontrado.");
                    }
                    else
                    {
                        int addVenda;
                        Console.WriteLine("0. Sair da Venda");
                        Console.WriteLine("1. Cadastrar uma Venda");
                        addVenda = int.Parse(Console.ReadLine());
                        while (addVenda != 0)
                        {
                            if (addVenda == 1)
                            {
                                int dia;
                                int qtd;
                                float valor;
                                Console.WriteLine("digite o dia");
                                dia = int.Parse(Console.ReadLine());
                                Console.WriteLine("digite a quantidade");
                                qtd = int.Parse(Console.ReadLine());
                                Console.WriteLine("digite o valor");
                                valor = float.Parse(Console.ReadLine());
                                vendedorAchado.registrarVenda(dia, new Venda(qtd, valor));

                            }                           
                            Console.WriteLine("0. Sair da Venda");
                            Console.WriteLine("1. Cadastrar uma Venda");
                            addVenda = int.Parse(Console.ReadLine());
                        }                        
                    }
                }

                if (opc == 5)
                {
                    double totalValor = 0;
                    double totalValorComissao = 0;
                    foreach (Vendedor v in vendedores.OsVendedores)
                    {
                        if (v.Id != -1)
                        {
                            Console.WriteLine("ID: " + v.Id);
                            Console.WriteLine("NOME: " + v.Nome);
                            Console.WriteLine("VALOR TOTAL VENDAS: " + v.valorVendas());
                            Console.WriteLine("VALOR COMISSÂO: " + v.valorComissao());

                            totalValor = totalValor + v.valorVendas();
                            totalValorComissao = totalValorComissao + v.valorComissao();
                        }
                       
                    }
                    Console.WriteLine("O total do Valor de Vendas foi: " + totalValor);
                    Console.WriteLine("O total do Valor das Comissões foram: " + totalValorComissao);

                }

                Console.WriteLine("0. Sair");
                Console.WriteLine("1. Cadastrar vendedor");
                Console.WriteLine("2. Consultar vendedor");
                Console.WriteLine("3. Excluir vendedor");
                Console.WriteLine("4. Registrar venda");
                Console.WriteLine("5. Listar vendedores");
                Console.WriteLine("Escolha uma opção: ");
                opc = int.Parse(Console.ReadLine());
            }

        }
    }
}

/*
 * Classe que fornece toda a lógica para a utilização dos menus e pede
 * serviços ao servidor.
 */

using System;
using Thrift;
using Thrift.Protocol;
using Thrift.Server;
using Thrift.Transport;
using processo;

namespace Client
{
    public class Cliente
    {
        public static int Main(string[] args)
        {
            if (args.Length == 0)
            {
                System.Console.WriteLine("Sem argumentos");
                System.Console.Read();
                return 1;
            }
            else if (args.Length < 2)
            {
                System.Console.WriteLine("Argumentos insuficientes");
                System.Console.Read();
                return 1;
            }
            TTransport transport = null;
            TProtocol protocol = null;
            ProcessoServidor.Client client = null;
            try
            {
                transport = new TSocket(args[0], int.Parse(args[1]));
                protocol = new TBinaryProtocol(transport);
                client = new ProcessoServidor.Client(protocol);
                transport.Open();
            }
            catch(Exception ex)
            {
                System.Console.WriteLine("Erro durante a inicialização");
                System.Console.Read();
                return 1;
            }
            int opt = 0, t = 3000;
            string aux, nome, tel;
            Resultado res = null;
            Exception e = null;
            while (opt != 4)
            {
                System.Console.WriteLine("1 - Armazena/Atualiza um Registro;");
                System.Console.WriteLine("2 - Remove um Registro;");
                System.Console.WriteLine("3 - Recupera um Registro;");
                System.Console.WriteLine("4 - Finaliza a Aplicação");
                opt = int.Parse(System.Console.ReadLine());
                switch (opt)
                {
                    case 1:
                        System.Console.WriteLine("Digite o nome do Contato:");
                        nome = System.Console.ReadLine();
                        System.Console.WriteLine("Digite o telefone do Contato:");
                        tel = System.Console.ReadLine();
                        do
                        {
                            try
                            {
                                if (e != null)
                                {
                                    e = null;
                                    transport = new TSocket(args[0], int.Parse(args[1]));
                                    protocol = new TBinaryProtocol(transport);
                                    client = new ProcessoServidor.Client(protocol);
                                    transport.Open();
                                }
                                res = client.recuperar(nome);
                            }
                            catch (Exception ex)
                            {
                                e = ex;
                                System.Threading.Thread.Sleep(t);
                            }
                        } while (e != null);
                        if (res.Sinal == true)
                        {
                            System.Console.WriteLine("Contado existente!");
                            System.Console.WriteLine(res.Mensagem);
                            System.Console.WriteLine("Deseja atualizar o contato? (escreva Sim para atualizar)");
                            aux = System.Console.ReadLine();
                            if (aux.Equals("sim",StringComparison.OrdinalIgnoreCase))
                            {
                                System.Console.WriteLine("Digite o telefone do Contato:");
                                tel = System.Console.ReadLine();
                                do
                                {
                                    try
                                    {
                                        if (e != null)
                                        {
                                            e = null;
                                            transport = new TSocket(args[0], int.Parse(args[1]));
                                            protocol = new TBinaryProtocol(transport);
                                            client = new ProcessoServidor.Client(protocol);
                                            transport.Open();
                                        }
                                        res = client.atualizar(nome, tel);
                                    }
                                    catch (Exception ex)
                                    {
                                        e = ex;
                                        System.Threading.Thread.Sleep(t);
                                    }
                                } while (e != null);
                                System.Console.WriteLine(res.Mensagem);
                            }
                        }
                        else
                        {
                            do
                            {
                                try
                                {
                                    if (e != null)
                                    {
                                        e = null;
                                        transport = new TSocket(args[0], int.Parse(args[1]));
                                        protocol = new TBinaryProtocol(transport);
                                        client = new ProcessoServidor.Client(protocol);
                                        transport.Open();
                                    }
                                    res = client.armazenar(nome, tel);
                                }
                                catch (Exception ex)
                                {
                                    e = ex;
                                    System.Threading.Thread.Sleep(t);
                                }
                            } while (e != null);
                            System.Console.WriteLine(res.Mensagem);
                        }
                        break;
                    case 2:
                        System.Console.WriteLine("Digite o nome do Contato:");
                        nome = System.Console.ReadLine();
                        do
                        {
                            try
                            {
                                if (e != null)
                                {
                                    e = null;
                                    transport = new TSocket(args[0], int.Parse(args[1]));
                                    protocol = new TBinaryProtocol(transport);
                                    client = new ProcessoServidor.Client(protocol);
                                    transport.Open();
                                }
                                res = client.remover(nome);
                            }
                            catch (Exception ex)
                            {
                                e = ex;
                                System.Threading.Thread.Sleep(t);
                            }
                        } while (e != null);
                        System.Console.WriteLine(res.Mensagem);
                        break;
                    case 3:
                        System.Console.WriteLine("Digite o nome do Contato:");
                        nome = System.Console.ReadLine();
                        do
                        {
                            try
                            {
                                if (e != null)
                                {
                                    e = null;
                                    transport = new TSocket(args[0], int.Parse(args[1]));
                                    protocol = new TBinaryProtocol(transport);
                                    client = new ProcessoServidor.Client(protocol);
                                    transport.Open();
                                }
                                res = client.recuperar(nome);
                            }
                            catch (Exception ex)
                            {
                                e = ex;
                                System.Threading.Thread.Sleep(t);
                            }
                        } while (e != null);
                        System.Console.WriteLine(res.Mensagem);
                        break;
                    case 4:
                        System.Console.WriteLine("Saindo...");
                        break;
                    default:
                        System.Console.WriteLine("Opção não reconhecida");
                        break;

                }
            }
            return 0;
        }
    }
}
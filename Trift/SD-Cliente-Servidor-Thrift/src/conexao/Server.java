/*
    Classe que ativa o servidor.
*/
package conexao;

import controle.*;
import java.util.logging.*;
import org.apache.thrift.server.*;
import org.apache.thrift.transport.*;
import processo.*;

public class Server {
    private static String SERVERNAME;
    private static int SERVERPORT;
    
    public static ProcessoServidorImpl processo;
    public static ProcessoServidor.Processor processor;

    public static void main(String [] args) {
        if(args.length == 0) {
            System.out.println("Sem argumentos");
            return;
        }
        try {
            SERVERNAME = args[0];
            SERVERPORT = new Integer(args[1]).intValue();
            processo = new ProcessoServidorImpl();
            processor = new ProcessoServidor.Processor(processo);
            Runnable simple = new Runnable() {
                @Override
                public void run() {
                server(processor);
                }
            };
            new Thread(simple).start();
        } catch (NumberFormatException e) {
            Logger.getLogger(Server.class.getName()).log(Level.ALL, null, e);
        }
    }

    public static void server(ProcessoServidor.Processor processor) {
        try {
            TServerTransport serverTransport = new TServerSocket(SERVERPORT);
            TServer server = new TThreadPoolServer(new TThreadPoolServer.Args(serverTransport).processor(processor));
            System.out.println("Servidor ativo em: " + SERVERNAME + " Porta: " + SERVERPORT);
            server.serve();
        } catch (TTransportException e) {
            Logger.getLogger(Server.class.getName()).log(Level.ALL, null, e);
        }
    }
}

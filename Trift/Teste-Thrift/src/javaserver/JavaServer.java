package javaserver;

import org.apache.thrift.server.*;
import org.apache.thrift.server.TServer.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.transport.TSSLTransportFactory.*;
import tutorial.*;

public class JavaServer {

  public static CalculatorHandler handler;
  public static Calculator.Processor processor;
  private static final int port = 9090;

  public static void main(String [] args) {
    try {
      handler = new CalculatorHandler();
      processor = new Calculator.Processor(handler);
      Runnable simple = new Runnable() {
        @Override
        public void run() {
          simple(processor);
        }
      };
      new Thread(simple).start();
    } catch (Exception x) {
    }
  }

  public static void simple(Calculator.Processor processor) {
    try {
      TServerTransport serverTransport = new TServerSocket(port);
      TServer server = new TSimpleServer(new Args(serverTransport).processor(processor));
      // Use this for a multithreaded server
      // TServer server = new TThreadPoolServer(new TThreadPoolServer.Args(serverTransport).processor(processor));
      System.out.println("Starting server at localhost:" + port);
      server.serve();
    } catch (TTransportException e) {
    }
  }
}
/*
    Classe que encaminha o serviço requisitado pelo cliente para o DAO
    processar.
*/
package controle;

import dao.*;
import java.math.*;
import modelo.*;
import processo.*;

public class ProcessoServidorImpl implements ProcessoServidor.Iface {
    
    @Override
    public Resultado armazenar(String nome, String telefone) {
        nome = Filtro.filtroNome(nome);
        BigDecimal tel = Filtro.filtroFone(telefone);
        System.out.println("* Recebido:");
        System.out.println("Armazenar: {nome = " + nome + ", telefone = " + tel + "}");
        Resultado res;
        if(ContatoDAO.getInstance().salvar(nome, tel)) {
            res = new Resultado(true, "O telefone do contato " + nome + " foi salvo como: " + tel);
        } else res = new Resultado(false, "Contato não pôde ser armazenado");
        System.out.println("* Respondendo:");
        System.out.println(res.mensagem);
        return res;
    }

    @Override
    public Resultado atualizar(String nome, String telefone) {
        nome = Filtro.filtroNome(nome);
        BigDecimal tel = Filtro.filtroFone(telefone);
        System.out.println("* Recebido:");
        System.out.println("Atualizar: {nome = " + nome + ", telefone = " + tel + "}");
        Resultado res;
        if(ContatoDAO.getInstance().atualizar(nome, tel)) {
            res = new Resultado(true, "O telefone do contato " + nome + " foi atualizado para: " + tel);
        } else res = new Resultado(false, "Contato não pôde ser atualizado");
        System.out.println("* Respondendo:");
        System.out.println(res.mensagem);
        return res;
    }

    @Override
    public Resultado remover(String nome) {
        nome = Filtro.filtroNome(nome);
        System.out.println("* Recebido:");
        System.out.println("Remover: {nome = " + nome + "}");
        Resultado res;
        if(ContatoDAO.getInstance().deletar(nome)) {
            res = new Resultado(true, "O contato " + nome + " foi apagado");
        } else res = new Resultado(false, "Contato não pôde ser removido");
        System.out.println("* Respondendo:");
        System.out.println(res.mensagem);
        return res;
    }

    @Override
    public Resultado recuperar(String nome) {
        nome = Filtro.filtroNome(nome);
        Contato cont = ContatoDAO.getInstance().buscar(nome);
        System.out.println("* Recebido:");
        System.out.println("Recuperar: {nome = " + nome + "}");
        Resultado res;
        if(cont != null) {
            res = new Resultado(true, "O telefone do contato " + cont.getNome() + " é: " + cont.getTelefone());
        } else res = new Resultado(false, "Contato não encontrado");
        System.out.println("* Respondendo:");
        System.out.println(res.mensagem);
        return res;
    }
}

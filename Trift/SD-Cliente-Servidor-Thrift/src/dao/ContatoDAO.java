/*
    Classe responsável pela comunicação com BDM. Ela possui funções para
    buscar, atualizar, salvar e deletar dados da tabela PESSOA do banco.
*/
package dao;

import java.math.*;
import java.sql.*;
import java.util.logging.*;
import modelo.*;
import persistencia.*;

public class ContatoDAO {
    final String SQL_SALVAR = "INSERT INTO pessoa (nome, telefone) VALUES ('%s', '%s');";
    final String SQL_UPDATE = "UPDATE pessoa SET telefone = '%s' WHERE nome = '%s';";
    final String SQL_DELETE = "DELETE FROM pessoa WHERE nome = '%s';";
    final String SQL_FIND_1 = "SELECT * FROM pessoa WHERE nome = '%s';";
    private static ContatoDAO instancia;

    private ContatoDAO() {
    }

    public static ContatoDAO getInstance() {
	if (ContatoDAO.instancia == null) {
	    ContatoDAO.instancia = new ContatoDAO();
	}
	return ContatoDAO.instancia;
    }

    public Contato buscar(String nome) {
	try {
            Contato cont = new Contato();
            java.sql.ResultSet rs = PGSql.getInstance().query(String.format(SQL_FIND_1, nome));
	    rs.next();
	    cont.setNome(rs.getString("nome"));
	    cont.setTelefone(rs.getString("telefone"));
	    return cont;
	} catch (SQLException e) {
            Logger.getLogger(ContatoDAO.class.getName()).log(Level.ALL, null, e);
	    return null;
	}
    }

    public boolean salvar(String nome, BigDecimal telefone) {
	return PGSql.getInstance().exec(String.format(SQL_SALVAR, nome, telefone));
    }

    public boolean atualizar(String nome, BigDecimal telefone) {
	return PGSql.getInstance().exec(String.format(SQL_UPDATE, telefone, nome));
    }

    public boolean deletar(String nome) {
	return PGSql.getInstance().exec(String.format(SQL_DELETE, nome));
    }
}

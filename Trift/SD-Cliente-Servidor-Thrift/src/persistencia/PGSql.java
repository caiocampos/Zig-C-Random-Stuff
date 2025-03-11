/*
    Classe que controla a conexão com o banco.
*/
package persistencia;

import java.sql.*;
import java.util.logging.*;

public class PGSql {

    private Connection connection;
    private final String url = "jdbc:postgresql://127.0.0.1:5432/postgres";
    private final String login = "postgres";
    private final String passw = "postgre";
    private static PGSql instancia;
    private static boolean searchPath = false;

    public Connection getConnection() {
        return this.connection;
    }

    private PGSql() throws SQLException {
        try {
            Class.forName("org.postgresql.Driver");
            this.connection = DriverManager.getConnection(this.url, this.login, this.passw);
        } catch (NullPointerException | ClassNotFoundException | SQLException e) {
            Logger.getLogger(PGSql.class.getName()).log(Level.SEVERE, null, e);
        }
    }

    public static PGSql getInstance() {
        try {
            if (PGSql.instancia == null) {
                PGSql.instancia = new PGSql();
            }
            return PGSql.instancia;
        } catch (NullPointerException | SQLException e) {
            Logger.getLogger(PGSql.class.getName()).log(Level.SEVERE, null, e);
            return null;
        }
    }

    public ResultSet query(String query) {
        setSearchPath();
        Statement statement;
        ResultSet rs;
        try {
            statement = this.connection.createStatement();
            rs = statement.executeQuery(query);
            return rs;
        } catch (SQLException e) {
            Logger.getLogger(PGSql.class.getName()).log(Level.SEVERE, null, e);
            return null;
        } catch (NullPointerException e) {
            Logger.getLogger(PGSql.class.getName()).log(Level.SEVERE, null, e);
            PGSql.instancia = null;
            return null;
        }
    }

    public boolean exec(String query) {
        setSearchPath();
        Statement statement;
        try {
            statement = this.connection.createStatement();
            statement.execute(query);
                statement.close();
            return true;
        } catch (SQLException e) {
            Logger.getLogger(PGSql.class.getName()).log(Level.SEVERE, null, e);
            return false;
        } catch (NullPointerException e) {
            Logger.getLogger(PGSql.class.getName()).log(Level.SEVERE, null, e);
            PGSql.instancia = null;
            return false;
        }
    }
    
    private boolean setSearchPath() {
        if (!searchPath) {
            Statement statement;
            try {
                statement = this.connection.createStatement();
                statement.execute("SET SEARCH_PATH TO NP;");
                searchPath = true;
                statement.close();
                return true;
            } catch (SQLException e) {
                Logger.getLogger(PGSql.class.getName()).log(Level.SEVERE, null, e);
                return false;
            } catch (NullPointerException e) {
                Logger.getLogger(PGSql.class.getName()).log(Level.SEVERE, null, e);
                PGSql.instancia = null;
                return false;
            }
        }
        return true;
    }
}

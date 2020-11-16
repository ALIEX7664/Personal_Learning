import java.sql.*;
import java.util.Arrays;
import java.util.Date;

// 同主键事务插入异常测试

public class TestTransaction {
    public static void main(String[] args) {
        Connection con = null;
        try {
//          1. 建立数据库连接
            Class.forName("com.mysql.cj.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/test?user=root&password=139226&" +
                    "useUnicode=true&characterEncoding=utf8&serverTimezone=GMT";
            con = DriverManager.getConnection(url);
            System.out.println("Database connect succeed");
        } catch (ClassNotFoundException e) {
            System.out.println("JDBC Driver error");
            e.printStackTrace();
            return;
        } catch (SQLException e) {
            System.out.println("Database created error");
            e.printStackTrace();
            return;
        }
//      2. 编写SQL语句
        String sql = "insert into pets(id,name,gender) values(?,?,?)";

        PreparedStatement ps = null;
//      3. 编写事务
        try {
            ps = con.prepareStatement(sql);

            con.setAutoCommit(false);
            ps.setString(1, "1");
            ps.setString(2, "Aliex");
            ps.setInt(3, 1);
            ps.executeUpdate();
            ps.setString(1, "1");
            ps.setString(2, "Alie");
            ps.setInt(3, 0);
            ps.executeUpdate();
            con.commit();
            System.out.println("Insert succeed");
        } catch (SQLException e) {
            System.out.println("update error");
            e.printStackTrace();
//          4. 回滚机制
            try {
                con.rollback();
            } catch (SQLException e1) {
                e1.printStackTrace();
                System.out.println("rollback error");
            }

        } finally {
//          5. 关闭连接
            try {
                ps.close();
                con.close();
            } catch (SQLException e) {
                System.out.println("close error");
                e.printStackTrace();
                ps = null;
                con = null;
            }
        }
    }

}

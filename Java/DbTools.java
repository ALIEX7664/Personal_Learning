import com.mchange.v2.c3p0.ComboPooledDataSource;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.SQLException;


public class DbTools {
//    单例模式创建对象
  private static ComboPooledDataSource dataSource = new ComboPooledDataSource();

  public  static DataSource getDataSource(){
      return dataSource;
  }


  public static Connection getConnection(){
      Connection  con = null;
      try{
            con = dataSource.getConnection();
      }catch(SQLException e) {
            e.printStackTrace();
      }
      return con;
  }
}

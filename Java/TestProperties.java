import java.beans.PropertyVetoException;
import java.io.FileInputStream;
import java.sql.*;
import java.util.Properties;

import com.mchange.v2.c3p0.ComboPooledDataSource;

//自动读取c3p0配置文件,实现连接池技术的配置
public class TestProperties {
    public static void main(String[] args) throws Exception {
        ComboPooledDataSource cdps = null; 
        cdps = new ComboPooledDataSource("myApp");
        System.out.println("c3p0 initial succeed");

        Connection con = cdps.getConnection();
        System.out.println("connection succeed");
        Thread.sleep(1000);
        con.close();
        System.out.println("release connection");
        cdps.close();
        System.out.println("close database pool");
    }
}

import java.beans.PropertyVetoException;
import java.io.FileInputStream;
import java.sql.*;
import java.util.Properties;

import  com.mchange.v2.c3p0.ComboPooledDataSource;
import com.mchange.v2.c3p0.DataSources;
import  javax.sql.DataSource;


public class TestC3P0 {
    public static void main(String[] args) throws Exception {
        ComboPooledDataSource cpds = null;
        try{
//           建立连接池对象和配置文件对象
            cpds = new ComboPooledDataSource("myApp");
            Properties pro = new Properties();
//            新建输入文档流
            FileInputStream file = new FileInputStream("dbinfo.properties");
//            读取文件配置
            pro.load(file);
//            关闭文档流
            file.close();

//            从文件配置中获取设置连接池配置的键值
            cpds.setDriverClass(pro.getProperty("driver"));
            cpds.setJdbcUrl(pro.getProperty("url"));
            cpds.setUser(pro.getProperty("user"));
            cpds.setPassword(pro.getProperty("password"));

            System.out.println("c3p0 pool initial succeed");

//            通过连接池建立数据库连接
            Connection con = cpds.getConnection();
            System.out.println("get pool succeed");
            Thread.sleep(2000);
            con.close();
            System.out.println("close connection succeed");
            cpds.close();
        }catch(PropertyVetoException e) {
            e.printStackTrace();
        }catch(SQLException e){
            e.printStackTrace();
        }
    }
}

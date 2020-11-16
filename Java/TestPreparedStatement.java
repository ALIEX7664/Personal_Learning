import java.sql.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class User{
    String id;
    String name;
    User(String id,String name){
        this.id = id;
        this.name = name;
    }


    @Override
    public String toString() {
        return "Name:"+ this.name + "\tId:" + this.id;
    }
}


public class TestPreparedStatement{
    public static void main(String[] args)  throws Exception{
//        声明
        Class.forName("com.mysql.cj.jdbc.Driver");
        String url = "jdbc:mysql://localhost:3306/test?user=root&password=139226&" +
                        "useUnicode=true&characterEncoding=utf8&serverTimezone=GMT";
//        连接数据库
        Connection con = DriverManager.getConnection(url);
        String name = "Odie";
        String sql = "select * from pets where name=?";
//        设置CRUD操作
        PreparedStatement ps = con.prepareStatement(sql);
        ps.setString(1,name);
//        设置返回结果
        ResultSet rs = ps.executeQuery();

//        读取数据存入
        List<User> userList =  new ArrayList<User>();
        while(rs.next()){
            String userId = rs.getString("id");
            String userName = rs.getString("name");
            User user = new User(userId,userName);
            userList.add(user);
        }

//        关闭连接
        rs.close();
        ps.close();
        con.close();

//        遍历
        for(User user:userList){
            System.out.println(user);
        }



    }

}

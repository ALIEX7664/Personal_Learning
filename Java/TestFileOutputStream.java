import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class TestFileOutputStream {

    public  static void main(String[] args){
        FileOutputStream out = null;
        try{
            out = new FileOutputStream("E:/Test.txt");
            byte[] data = "Hello China".getBytes();
            out.write(data);
            System.out.println("writing");
        }catch(FileNotFoundException e){
            System.out.println("FileNotFoundException");
        }catch(IOException e){
            System.out.println("IOException");
        }finally {
            if(null != out){
                try{
                    out.flush();
                    out.close();
                }catch(IOException e){
                    System.out.println("IOException 2");
                }
            }
        }
    }
}

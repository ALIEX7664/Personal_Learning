//import javax.imageio.IIOException;
//import java.io.FileInputStream;
//import java.io.FileNotFoundException;
//import java.io.IOException;
//import java.util.Arrays;
//
//public class TestFileInputStream {
//    public static void main(String[] args) {
//        int b = 0;
//        FileInputStream in = null;
//        try {
//            in = new FileInputStream("E:/Test.txt");
//            long num = 0;
//            while((b = in.read()) != -1){
//                System.out.print((char)b);
//                num++;
//            }
//            System.out.println("read" + num +"byte");
//
//        } catch (FileNotFoundException e) {
//            System.out.println("FileNotFoundException");
//        }catch (IOException e){
//            System.out.println("IOException");
//        }finally {
//            if(null != in){
//                try{
//                    in.close();
//                }catch(IOException e){
//                    System.out.println("IOException 2");
//                }
//            }
//        }
//    }
//}

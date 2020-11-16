//单例模式

class Singleton{
    private Singleton(){

    }

//    创建私有静态实例对象
    private static Singleton instance = new Singleton();

//    外部获取对象方法
    public static Singleton getObj(){
        return instance;
    }

    @Override
    public String toString(){
        return "Create instance success";
    }

}


public class SinglletonPattern {
    public static void main(String[] args) {
        Singleton obj = Singleton.getObj();
        System.out.println(obj);
    }
}

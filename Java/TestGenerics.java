//import java.awt.*;
//import java.util.Comparator;
//
//class MySorter<T extends Comparable<T>> {
//    public void sort(T[] a) {
//        T temp = null;
//
////        冒泡排序
//        for (int i = a.length - 1; i > 0; i--) {
//            for (int j = 0; j < i; j++) {
//                if (a[j].compareTo(a[j + 1]) > 0) {  // 使用Peron覆盖的方法
//                    temp = a[j];
//                    a[j] = a[j + 1];
//                    a[j + 1] = temp;
//                }
//            }
//        }
//    }
//
//    public void sort(T[] a, Comparator<T> comparator) {
//        T temp = null;
//
////      比较器冒泡排序
//        for (int i = a.length - 1; i > 0; i--) {
//            for (int j = 0; j < i; j++) {
//                if (comparator.compare(a[j], a[j + 1]) > 0) {
//                    temp = a[j];
//                    a[j] = a[j + 1];
//                    a[j + 1] = temp;
//                }
//            }
//        }
//    }
//}
//
//class MyArrays {
//    public static <T extends Comparable<T>> T getMin(T[] a) {
//        T min = a[0];
//        for (T t : a) {
//            if (t.compareTo(min) < 0) {
//                min = t;
//            }
//        }
//        return min;
//    }
//}
//
//class ComparatorByName implements Comparator<Person> {
//    @Override
//    public int compare(Person o1, Person o2) {
//        return o1.name.compareTo(o2.name);
//    }
//}
//
//class Person implements Comparable<Person> {
//    public int age;
//    public String name;
//
//    public Person() {
//    }
//
//    public Person(int age, String name) {
//        this.age = age;
//        this.name = name;
//    }
//
//    @Override
//    public String toString() {
//        return this.name + "的年龄是:" + this.age;
//    }
//
//    @Override
//    public int compareTo(Person o) {
//        return this.age - o.age;
//    }
//
//}
//
//enum Color{
//    RED(255,0,0) , GREEN(0,255,0) ,BLUE(0,0,255);
//    private int r,g,b;
//    private Color(int r, int g, int b){
//        this.r = r;
//        this.g = g;
//        this.b = b;
//    }
//
//    @Override
//    public String toString(){
//        return "color" + Integer.toString(this.r + this.g + this.b);
//    }
//
//
//}
//
//public class TestGenerics {
//    public static void main(String[] args) {
//
//        Color c = Color.RED;
//        System.out.println(c);
//
//
//        Person[] p = new Person[3];
//        p[0] = new Person(20, "A");
//        p[1] = new Person(30, "B");
//        p[2] = new Person(15, "c");
//
//        MySorter<Person> sorter = new MySorter<Person>();
//        System.out.println("按Person类制定的默认比较规则排序：");
//        sorter.sort(p);
//        for (Person e : p) {
//            System.out.println(e);
//        }
//
//        System.out.println("按ComparatorByName制定比较规则排序：");
//        sorter.sort(p, new ComparatorByName());
//        for (Person e : p) {
//            System.out.println(e);
//        }
//
//        System.out.println("数组中的最小元素是：" + MyArrays.getMin(p));
//    }
//
//}

import java.util.Random;

public class Main {

    public static void main(String[] args) {
        Var1 v = new Var1();
        System.out.println(v.a + " " + v.c + " " + v.s);

        Student s1 = new Student();
        Student s2 = new Student("Mark Robertson", 19, 4.5);

        System.out.println(s1.name + " is" + s1.age + " years old, and " + s1.mark +" is his mark");
        System.out.println(s2.name + " is" + s2.age + " years old, and " + s2.mark +" is his mark");

        for (int i = 5; i < 80; i++) {
            System.out.print(i + " ");
            if(i%15 == 0){
                System.out.println();
            }
        }
        System.out.println();
        int c = 5;
        while (c < 80) {
            System.out.print(c + " ");
            if(c++%15 == 0){
                System.out.println();
            }
        }
    }

}
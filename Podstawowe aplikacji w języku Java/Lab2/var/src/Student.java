public class Student {
    String name;
    int age;
    double mark;

    Student(){
        name = "Unknown Student";
        age = 0;
        mark = 0.0;
    }

    Student(String name, int age, double mark){
        this.name = name;
        this.age = age;
        this.mark = mark;
    }
}

public class Triangle {
    double a;
    double b;
    double c;

    Triangle(double a, double b, double c){
        this.a = a;
        this.b = b;
        this.c = c;
    }

    boolean isValid(){
        if((a + b) <= c){
            return false;
        }
        else if((a + c) <= b){
            return false;
        }
        else if((c + b) <= a){
            return false;
        }
        return true;
    }

    void type(){
        if(a == b && a == c){
            System.out.println("Rownoboczny");
        } else if (a == b || a == c || b == c) {
            System.out.println("Rownoramienny");
        } else {
            System.out.println("Roznoboczny");
        }
    }
}

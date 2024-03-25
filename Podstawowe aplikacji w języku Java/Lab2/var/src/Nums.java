public class Nums {
    void nums(){
        for (int i = 11; i < 111; i++) {
            if(i%13 == 0){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    void fibbonaci(int n){
        System.out.println(fibNum(n));
    }

    int fibNum (int n){
        if(n <= 1){
            return 1;
        }
        return fibNum(n-1) + fibNum(n - 2);
    }
}

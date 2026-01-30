import java.util.*;

public class ccc07j1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int b = s.nextInt();
        int c = s.nextInt();
        s.close();
        if (a > b && a > c) {
            if(b>c){
                System.out.println(b);
            }
            else{
                System.out.println(c);
            }
        }
        if (b > a && b > c) {
            if(a>c){
                System.out.println(a);
            }
            else{
                System.out.println(c);
            }
        }
        if (c > b && c > a) {
            if(b>a){
                System.out.println(b);
            }
            else{
                System.out.println(a);
            }
        }
    }
}
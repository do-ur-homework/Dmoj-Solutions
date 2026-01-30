import java.util.*;

public class ccc03j2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        boolean done = false;
        List<Integer> all = new ArrayList<>();
        while(!done){
            int pics = in.nextInt();
            if(pics == 0){
                break;
            }
            all.add(pics);
        }
        in.close();

        for(int i = 0; i<all.size(); i++){
            int temp = all.get(i);
            int prev = 1;

            if(Math.pow((int)Math.sqrt(temp), 2) == temp){
                int peri = (int) Math.sqrt(temp) *4;
                System.out.println("Minimum perimeter is " + peri + " with dimensions " + (int) Math.sqrt(temp) + " x " + (int) Math.sqrt(temp));
                continue;
            }

            for(int j = 1; j<=temp; j++){
                if(temp%j == 0 && j*prev == temp){
                    int peri = j*2 + prev*2;
                    System.out.println("Minimum perimeter is " + peri + " with dimensions " + prev + " x " + j);
                    break;
                }else if(temp%j == 0){
                    prev = j;
                }
            }
        }
    }
}
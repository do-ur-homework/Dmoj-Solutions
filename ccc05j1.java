import java.io.*;
import java.util.*;

public class ccc05j1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int daytime = Integer.parseInt(scanner.nextLine());
        int evening = Integer.parseInt(scanner.nextLine());
        int weekend = Integer.parseInt(scanner.nextLine());


        double daytimeCostA = Math.max(daytime - 100, 0) * 0.25;
        double eveningCostA = evening * 0.15;
        double weekendCostA = weekend * 0.2;
        double planA = daytimeCostA + eveningCostA + weekendCostA;

        double daytimeCostB = Math.max(daytime - 250, 0) * 0.45;
        double eveningCostB = evening * 0.35;
        double weekendCostB = weekend * 0.25;
        double planB = daytimeCostB + eveningCostB + weekendCostB;

        System.out.println("Plan A costs " + String.format("%.2f", planA));
        System.out.println("Plan B costs " + String.format("%.2f", planB));

        if (planA < planB) {
            System.out.println("Plan A is cheapest.");
        } else if (planB < planA) {
            System.out.println("Plan B is cheapest.");
        } else {
            System.out.println("Plan A and B are the same price.");
        }
    }
}
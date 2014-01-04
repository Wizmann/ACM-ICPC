import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        int A[] = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = cin.nextInt();
        }

        solve(n, A);
    }

    public static void solve(int n, int A[]) {
        int sum = 0;
        for (int i: A) {
            sum += i;
        }
        int fill = 0;
        int now = 0;
        int dir = 1;
        while (fill < sum) {
            if (A[now] > 0) {
                System.out.print("P");
                A[now]--;
                fill++;
            }

            if (now + dir >= n || now + dir < 0) {
                dir *= -1;
            }

            now += dir;
            System.out.print(dir == 1 ? "R": "L");
        }
        System.out.println("");
    }
}



import java.util.Stack;
import java.util.Scanner;

public class TowerOfHanoiIterative {
    static char[] rods = {'A', 'B', 'C'};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of disks: ");
        int n = sc.nextInt();

        Stack<Integer>[] towers = new Stack[3];
        for (int i = 0; i < 3; i++)
            towers[i] = new Stack<>();

        // push disks to the first (source) tower
        for (int i = n; i >= 1; i--)
            towers[0].push(i);

        // calculate total moves
        int totalMoves = (int) Math.pow(2, n) - 1;

        // swap destination and auxiliary for even number of disks
        int src = 0, aux = 1, dest = 2;
        if (n % 2 == 0) {
            int temp = dest;
            dest = aux;
            aux = temp;
        }

        System.out.println("\nTower of Hanoi Moves:");
        for (int i = 1; i <= totalMoves; i++) {
            // move between source and destination
            if (i % 3 == 1)
                moveDisk(towers, src, dest);
            // move between source and auxiliary
            else if (i % 3 == 2)
                moveDisk(towers, src, aux);
            // move between auxiliary and destination
            else
                moveDisk(towers, aux, dest);
        }
        sc.close();
    }

    static void moveDisk(Stack<Integer>[] towers, int from, int to) {
        if (towers[to].isEmpty() || (!towers[from].isEmpty() && towers[from].peek() < towers[to].peek())) {
            int disk = towers[from].pop();
            towers[to].push(disk);
            System.out.println("Move disk " + disk + " from rod " + rods[from] + " to rod " + rods[to]);
        } else {
            int disk = towers[to].pop();
            towers[from].push(disk);
            System.out.println("Move disk " + disk + " from rod " + rods[to] + " to rod " + rods[from]);
        }
    }
}

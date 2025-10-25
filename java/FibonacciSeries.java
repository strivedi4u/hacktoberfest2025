import java.util.Scanner;
class FibonacciSeries{
 public static void main(String[] args){
  int first=0, second=1, third = 1, n;
  Scanner sc = new Scanner(System.in);
  System.out.print("Enter a number: "); // number of terms in the series
  n = sc.nextInt(); // taking input
  for(int i =0; i<n; i++){
   System.out.print(first+" ");
   first = second; second = third; third = first + second;
  }
 }
}

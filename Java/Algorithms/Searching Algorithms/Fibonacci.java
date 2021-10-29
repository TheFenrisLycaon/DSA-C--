/*
Fibonacci Series algorithm in Java

This Java Program is used to Generate Fibonacci Series. The number is said to be in a Fibonacci series 
if each subsequent number is the sum of the previous two numbers. In this program ,it'll calculate a fibonacci series 
of n number of elements which we'll take from the user.

Output :
Enter the number of elements : 
20
Fibonacci Series till 20 terms:
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181

*/

import java.util.Scanner;
class Fibonacci
{
  public static void main(String[] args) 
  {
    int n , n1 = 0, n2 = 1 , n3;
    
    Scanner sc = new Scanner(System.in);  //To take the number of elements as a input from the user
    System.out.println("Enter the number of elements : ");
    n = sc.nextInt();  //To store all the of elements
    
    System.out.println("Fibonacci Series till " + n + " terms:");

    for (int i = 1; i <= n; i++)  //To calculate the Fibonacci Series of 'n' number of elements
    {
      System.out.print(n1 + " ");
      n3 = n1 + n2;
      n1 = n2;
      n2 = n3;
    }
  }
}
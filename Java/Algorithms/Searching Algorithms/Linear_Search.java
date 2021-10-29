/*
Linear search algorithm in Java

In this search, every element is checked and if a match is found then that particular element is returned, if a match is not found then
it'll say element is not found.

Output :
Enter size of array : 
10
Enter the elements in an array : 
4 9 2 7 6 0 1 8 5 3
Enter element which is to be searched :
0
0 is present at location 6.

*/

import java.util.Scanner; 
 
public class LinearSearch
{
	public static void main(String[] args) 
	{
        int i , n , x , a[];
        Scanner sc = new Scanner(System.in); 
        System.out.println("Enter size of array : ");  
        n = sc.nextInt();
        a = new int[n];
        System.out.println("Enter the elements in an array : ");
        for (i = 0; i< n; i++)  //To store all the elements
        {
            a[i] = sc.nextInt();  
        }
         
         System.out.println("Enter element which is to be searched :");  
         x = sc.nextInt();  
         for (i = 0; i < n; i++)  
         {  
           if (a[i] == x)
           { 
              System.out.println(x+" is present at location " + (i+1) + ".");
              break;  
           }  
        }  
        if (i==n)
        {
           System.out.println(x+" is not found.");
        }
	}
}

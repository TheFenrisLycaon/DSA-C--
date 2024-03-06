/*
BINARY SEARCH ALGORITHM :

Approach : 

To search an element in an array -
1)First sort the array.
2)Assign low to the lowest number , high to the highest element and mid to middle number of the array.
3)If key matches with the mid, we return the mid index.
3)Search by repeatedly dividing the search interval in half.
4)If the value of the search key is less than the mid,narrow the interval to the lower half. 
 Otherwise, narrow it to the upper half. 
5)Repeatedly check until the value is found or the interval is empty.

Example :
Enter total number of elements : 10
Enter the elements : 8 2 7 4 5 0 1 3 6 9
Enter element to be searched : 5

Output :
5 is at location : 6

*/

import java.util.Scanner; 

class BinarySearch 
{
    int[] sort(int arr[])                                        //Function to sort the array
    {
        int len,max,temp;
        len=arr.length;
        for(int i=0; i<len; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(arr[i]>arr[j])
                {
                     temp = arr[j];
                    arr[j]= arr[i];
                    arr[i]= temp;
                }
            }  
        }
        return arr;        
    }
    
    int binarySearch(int arr[], int low, int high, int key)     //Function to perform Binary Search
    {
        if (high >= low) {
            int mid =  (low + high) / 2;
  
            // If the search key is present at the mid itself
            if (arr[mid] == key)
                return mid;
  
            // If search key is smaller than mid, then
            // it can only be present in left subarray
            if (arr[mid] > key)
                return binarySearch(arr, low, mid - 1, key);
  
            // If search key is larger than mid, then
            // in right subarray
            else
            return binarySearch(arr, mid+1, high, key);
        }
    // If search key is not present in an array
    return -1;
    }
}

public class Main
{
	public static void main(String[] args) {
	    int n,temp,key,b;
	    Scanner sc = new Scanner(System.in);
		System.out.println("Enter total number of elements:");
	    n = sc.nextInt();
		int[] arr = new int[n];
		System.out.println("Enter the elements:");
		for (int i=0 ; i<n ; i++)                                //To store all the elements
		{
		    arr[i]=sc.nextInt();  
		}
		
		int[] a = new int[n];
		BinarySearch obj1 = new BinarySearch();
        a = obj1.sort(arr);
        /*System.out.println("Sorted array is :");              //To print sorted elements 
        for(int i=0;i<n;i++)
        {
           System.out.print(+a[i]+" "); 
          
        }*/ 
        System.out.println("\nEnter the number to be searched: ");
        key=sc.nextInt();
        
        b=obj1.binarySearch(a,0,arr.length -1,key);
        
        if(b==0)
           {
            System.out.println("Element is not found in the array");
           }
        else
           {
            System.out.println(key+" is at location : "+(b+1));
           }
	}
}





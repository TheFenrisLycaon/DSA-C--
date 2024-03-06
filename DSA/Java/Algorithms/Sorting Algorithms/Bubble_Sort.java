//                                       **BUBBLE SORT ALGORITHM USING JAVA"
//Problem Statement: Sort elements of an array in ascending or descending order using Bubble Sort method.
//................................................................................................................
//Input: 1)Total number of elements to be stored in array.
//       2)Elements to be stored in the array for sorting array.
//       3)Users choice whether to sort elements in ascending order or descending order.
//.................................................................................................................
//Output:Sorted array with elements either in ascending order or descending order
//.................................................................................................................
//ALGORITHM:
//STEP 1: START
//STEP 2: Take the total number of elements to be stored in the array from user.
//STEP 3: Take the array elements to be sorted from the user.
//STEP 4: Take choice from the user to sort array elements in ascending order or descending order.
//STEP 5: Use of switch case to which the users choice is passed.
//STEP 6: According to users choice that particular case is executed.
//STEP 7:  case 1 is for sorting elements in ascending order. 
//        Use of for loop to print the array elements before sorting.
//        For loop is executed till the value of i is less than the length of array.
//STEP 8: Use of nested for loop to sort the elements. 
//        Array is traversed from first element to last element using the outer for loop. 
//        Using the inner for loop , array is traversed from 0 index position to the  (n-i) position
//        Here, current element is compared with the next element.
//        If current element is greater than the next element, it is swapped.
//STEP 9:Use of for loop to print the array after sorting the elements in ascending order.
//STEP 10:case 2 is for sorting elements in descending order.
//        Use of for loop to print the array elements before sorting.
//        For loop is executed till the value of i is less than the length of array.
//STEP 11:Use of nested for loop to sort the elements. 
//        Array is traversed from first element to last element using the outer for loop. 
//        Using the inner for loop , array is traversed from 0 index position to the  (n-i) position
//        Here, current element is compared with the next element.
//        If current element is less than the next element, it is swapped.
//STEP 12:Use of for loop to print the array after sorting the elements in descending order.
//STEP 13:END
//.......................................................................................................................
//APPROACH FOR ARRANGING ELEMENTS IN ASCENDING ORDER:
//EXAMPLE- [ 3 9 8 1 6 2 ]
//After first pass: [ 3 8 1 6 2 9 ]
//After second pass: [ 3 1 6 2 8 9 ]
//After third pass: [ 1 3 2 6 8 9 ]
//After fourth pass: [ 1 2 3 6 8 9 ]
//After fifth pass: [ 1 2 3 6 8 9 ]
//Hence we get sorted array after (n-1) passes where n is the total number of elements in the array.
//***********************************************************************************************************************************************************************************************
package Hacktoberfest_TheFenrisLycaon_Solutions;

import java.util.Scanner;

public class Bubble_Sort {
//start of class
	public static void main(String[] args) {
		// start of main function
		int n, ch, ch1;// Declaration of variables
		Scanner sc = new Scanner(System.in);// Use of scanner class
		// Use of do while controlled loop
		do {
			System.out.println("Enter the total number of elements to be stored in the array:");
			n = sc.nextInt();// Take the total number of elements from user and store in n
			int arr[] = new int[n];// Array declaration
			System.out.println("Enter " + n + " elements for the array");
			// To store all the elements in the array
			for (int i = 0; i < n; i++) {
				arr[i] = sc.nextInt();
			}
			System.out.println("Enter your choice:");
			System.out.println("1:Sort elements of array in ascending order");
			System.out.println("2:Sort elements of array in descending order");
			ch = sc.nextInt();// Store the choice entered by user in ch
			// Use of switch case
			switch (ch) {
			case 1:
				System.out.println(
						"///////////////////////////////////////////////////////////////////////////////////////////////////////");
				System.out.println("Sorting Array using Bubble Sort Technique in Ascending Order..");
				System.out.println("**BEFORE SORTING**");
				int temp;
				System.out.print("[");
				// Print array elements before sorting
				for (int i = 0; i < n; i++) {
					System.out.print(" " + arr[i] + " ");
				}
				System.out.print("]");
				// To sort the elements in ascending order
				// Outer for loop to traverse the array till last
				for (int i = 0; i < n; i++) {
					// Use of nested for loop
					// Inner for loop to traverse from current element index position the the n-i
					// position
					for (int j = 1; j < n - i; j++) {
						// Use of if control structure
						if (arr[j - 1] > arr[j]) {
							// swapping of elements

							temp = arr[j - 1];
							arr[j - 1] = arr[j];
							arr[j] = temp;
						}
					}
				}
				System.out.println("\n**AFTER SORTING**");
				// Print array elements after sorting
				System.out.print("[");
				for (int i = 0; i < n; i++) {
					System.out.print(" " + arr[i] + " ");
				}
				System.out.print("]");

				System.out.println("\n");
				System.out.println(
						"///////////////////////////////////////////////////////////////////////////////////////////////////////");

				break;

			case 2:
				System.out.println(
						"///////////////////////////////////////////////////////////////////////////////////////////////////////");

				System.out.println("Sorting Array using Bubble Sort Technique in Descending Order..");
				System.out.println("**BEFORE SORTING**");
				int temp1;
				// Print array elements before sorting
				System.out.print("[");
				for (int i = 0; i < n; i++) {
					System.out.print(" " + arr[i] + " ");
				}
				System.out.print("]");
				// To sort the elements in descending order
				for (int i = 0; i < n; i++) {
					for (int j = 1; j < n - i; j++) {
						if (arr[j - 1] < arr[j]) {
							// swapping of elements
							temp = arr[j - 1];
							arr[j - 1] = arr[j];
							arr[j] = temp;
						}
					}
				}
				System.out.println("\n**AFTER SORTING**");
				// Print array elements after sorting
				System.out.print("[");
				for (int i = 0; i < n; i++) {
					System.out.print(" " + arr[i] + " ");
				}
				System.out.print("]");

				System.out.println("\n");
				System.out.println(
						"///////////////////////////////////////////////////////////////////////////////////////////////////////");

				break;
			default:
				System.out.println(
						"///////////////////////////////////////////////////////////////////////////////////////////////////////");

				System.out.println("Invalid choice!!!");
				System.out.println(
						"///////////////////////////////////////////////////////////////////////////////////////////////////////");

				break;

			}
			System.out.println("Do you want to continue?");
			System.out.println("Yes:1");
			System.out.println("No:0");
			ch1 = sc.nextInt();// Store users choice in ch1
			// Use of if control structure
			if (ch1 == 0) {
				System.out.println(
						"///////////////////////////////////////////////////////////////////////////////////////////////////////");

				System.out.println("Exited the program!!!!");
				System.out.println(
						"///////////////////////////////////////////////////////////////////////////////////////////////////////");

			}

		} while (ch1 == 1);
		// Do while loop will be executed till choice ch1 entered by user is 1
	}// end of main function
}// end of class
//*****************************************************************************************************************************************************************************************************
//OUTPUT:
//.........................................................................................................................

//Enter the total number of elements to be stored in the array:
//6
//Enter 6 elements for the array
//3
//9
//8
//1
//6
//2
//Enter your choice:
//1:Sort elements of array in ascending order
//2:Sort elements of array in descending order
//1
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sorting Array using Bubble Sort Technique in Ascending Order..
//**BEFORE SORTING**
//[ 3  9  8  1  6  2 ]
//**AFTER SORTING**
//[ 1  2  3  6  8  9 ]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Do you want to continue?
//Yes:1
//No:0
//1
//Enter the total number of elements to be stored in the array:
//6
//Enter 6 elements for the array
//7
//2
//6
//8
//1
//9
//Enter your choice:
//1:Sort elements of array in ascending order
//2:Sort elements of array in descending order
//2
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sorting Array using Bubble Sort Technique in Descending Order..
//**BEFORE SORTING**
//[ 7  2  6  8  1  9 ]
//**AFTER SORTING**
//[ 9  8  7  6  2  1 ]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Do you want to continue?
//Yes:1
//No:0
//0
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Exited the program!!!!
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//..........................................................................................................
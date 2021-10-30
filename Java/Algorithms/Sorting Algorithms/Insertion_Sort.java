//                                   **INSERTION SORT ALGORITHM USING JAVA**
//Problem Statement: Sort elements of an array in ascending or descending order using Insertion Sort method.
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
//STEP 7: case 1 is for arranging elements in ascending order.
//        Use of for loop to print the array elements before sorting.
//        For loop is executed till the value of i is less than the length of array.
//STEP 8: Use of  for loop to sort the elements of array of size n.
//        Traverse from arr[1] to arr[n] over the array. 
//STEP 9: Compare the current element (key) to its predecessor. 
//STEP 10:If the key element is smaller than its predecessor, compare it to the elements before.
//STEP 11:Move the greater elements one position up to make space for the swapped element.
//STEP 12:Use of for loop to print the array after sorting the elements in ascending order.
//STEP 13:case 2 is for arranging elements in descending order.
//        Use of for loop to print the array elements before sorting.
//        For loop is executed till the value of i is less than the length of array.
//STEP 14:Use of  for loop to sort the elements of array of size n.
//        Traverse from arr[1] to arr[n] over the array. 
//STEP 15:Compare the current element (key) to its predecessor. 
//STEP 16:If the key element is greater than its predecessor, compare it to the elements before.
//STEP 17:Move the smaller elements one position up to make space for the swapped element.
//STEP 18:Use of for loop to print the array after sorting the elements in descending order.
//STEP 19:END
//.......................................................................................................................
//APPROACH FOR ARRANGING ELEMENTS IN ASCENDING ORDER:
//EXAMPLE- [ 12 11 13 5 6 ]
//After first pass: [ 11 12 13 5 6 ]
//After second pass: [ 11 12 13 5 6]
//After third pass: [ 5 11 12 13 6 ]
//After fourth pass: [ 5 6 11 12 13 ]
//Hence we get sorted array after (n-1) passes where n is the total number of elements in the array.
//**************************************************************************************************************************************************
package Hacktoberfest_TheFenrisLycaon_Solutions;

import java.util.Scanner;

public class Insertion_Sort {

	public static void main(String[] args) {
		int n, ch, ch1, i, j, key;// Declaration of variables
		Scanner sc = new Scanner(System.in);
		do {

			System.out.println("Enter the total number of elements to be stored in the array:");
			n = sc.nextInt();
			int arr[] = new int[n];// Array declaration
			System.out.println("Enter " + n + " elements for the array");
			// To store all the elements in the array
			for (i = 0; i < n; i++) {
				arr[i] = sc.nextInt();
			}
			System.out.println("Enter your choice:");
			System.out.println("1:Sort elements of array in ascending order");
			System.out.println("2:Sort elements of array in descending order");
			ch = sc.nextInt();
			// Use of switch case
			switch (ch) {
			case 1:
				System.out.println(
						"///////////////////////////////////////////////////////////////////////////////////////////////////////");
				System.out.println("Sorting Array using Insertion Sort Technique in Ascending Order..");
				System.out.println("**BEFORE SORTING**");
				int temp;
				System.out.print("[");
				// Print array elements before sorting
				for (i = 0; i < n; i++) {
					System.out.print(" " + arr[i] + " ");
				}
				System.out.print("]");
				// To sort the elements in ascending order
				// Use of for loop to traverse the array and responsible for number of passes
				for (i = 1; i < n; i++) {
					key = arr[i];
					j = i - 1;
					// Use of while loop
					while (j >= 0 && arr[j] > key) {
						arr[j + 1] = arr[j];
						j = j - 1;
					}
					arr[j + 1] = key;
				}

				System.out.println("\n**AFTER SORTING**");
				// Print array elements after sorting
				System.out.print("[");
				for (i = 0; i < n; i++) {
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

				System.out.println("Sorting Array using Insertion Sort Technique in Descending Order..");
				System.out.println("**BEFORE SORTING**");
				int temp1;
				// Print array elements before sorting
				System.out.print("[");
				for (i = 0; i < n; i++) {
					System.out.print(" " + arr[i] + " ");
				}
				System.out.print("]");
				// To sort the elements in descending order
				for (i = 0; i < n; i++) {
					key = arr[i];
					j = i - 1;
					while (j >= 0 && arr[j] < key) {
						arr[j + 1] = arr[j];
						j = j - 1;
					}
					arr[j + 1] = key;
				}

				System.out.println("\n**AFTER SORTING**");
				// Print array elements after sorting
				System.out.print("[");
				for (i = 0; i < n; i++) {
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
		// do while loop continues to execute till ch1 is equal to 1
	}// end of main function

}// end of class
//.................................................................................................................................................
//SAMPLE TEST 1:

//Enter the total number of elements to be stored in the array:
//5
//Enter 5 elements for the array
//12
//11
//13
//5
//6
//Enter your choice:
//1:Sort elements of array in ascending order
//2:Sort elements of array in descending order
//1
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sorting Array using Insertion Sort Technique in Ascending Order..
//**BEFORE SORTING**
//[ 12  11  13  5  6 ]
//**AFTER SORTING**
//[ 5  6  11  12  13 ]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Do you want to continue?
//Yes:1
//No:0
//1
//Enter the total number of elements to be stored in the array:
//5
//Enter 5 elements for the array
//7
//9
//6
//3
//8
//Enter your choice:
//1:Sort elements of array in ascending order
//2:Sort elements of array in descending order
//2
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sorting Array using Insertion Sort Technique in Descending Order..
//**BEFORE SORTING**
//[ 7  9  6  3  8 ]
//**AFTER SORTING**
//[ 9  8  7  6  3 ]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Do you want to continue?
//Yes:1
//No:0
//0
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Exited the program!!!!
///////////////////////////////////////////////////////////////////////////////////////////////////////

//***********************************************************************************************************************************************************

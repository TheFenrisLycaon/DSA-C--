//                                   **SELECTION SORT ALGORITHM**
//Problem Statement: Sort elements of an array in ascending or descending order using Selection Sort method.
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
//STEP 7: Defining case 1 for arranging array elements in ascending order.
//STEP 8: Inside case 1-
//        Use of for loop to print the array elements before sorting.
//        For loop is executed till the value of i is less than the length of array.
//STEP 9: Use of nested for loop to sort the elements. Search for the lowest element and arrange it to the proper location.
//        Swap the current element with the next lowest number.
//STEP 10:Use of for loop to print the array after sorting the elements in ascending order.
//STEP 11:Inside case 2: Same steps from step 7 to 10 carried out for arranging elements in descending order. 
//        Just for nested for loop the conditions change accordingly.
//STEP 12:END
//
//.......................................................................................................................
//APPROACH FOR ARRANGING ELEMENTS IN ASCENDING ORDER:
//EXAMPLE- [ 10 8 9 6 1 ]
//After first pass: [ 1 10 9 8 6 ]
//After second pass: [1 6 10 9 8]
//After third pass: [1 6 8 10 9]
//After fourth pass: [1 6 8 9 10]
//Hence we get sorted array after (n-1) passes where n is the total number of elements in the array.
//**************************************************************************************************************************************************
package Hacktoberfest_TheFenrisLycaon_Solutions;

import java.util.Scanner;

public class Selection_Sort {

	public static void main(String[] args) {
		int n, ch, ch1;// Declaration of variables
		Scanner sc = new Scanner(System.in);
		do {

			System.out.println("Enter the total number of elements to be stored in the array:");
			n = sc.nextInt();
			int arr[] = new int[n];// Array declaration
			System.out.println("Enter " + n + " elements for the array");
			// To store all the elements in the array
			for (int i = 0; i < n; i++) {
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
				System.out.println("Sorting Array using Selection Sort Technique in Ascending Order..");
				System.out.println("**BEFORE SORTING**");
				int temp;
				System.out.print("[");
				// Print array elements before sorting
				for (int i = 0; i < n; i++) {
					System.out.print(" " + arr[i] + " ");
				}
				System.out.print("]");
				// To sort the elements in ascending order
				for (int i = 0; i < n; i++) {
					for (int j = i + 1; j < n; j++) {
						if (arr[i] > arr[j]) {
							// swapping of elements

							temp = arr[i];
							arr[i] = arr[j];
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

				System.out.println("Sorting Array using Selection Sort Technique in Descending Order..");
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
					for (int j = i + 1; j < n; j++) {
						if (arr[i] < arr[j]) {
							// swapping of elements
							temp = arr[i];
							arr[i] = arr[j];
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
			ch1 = sc.nextInt();
			// Use of if control structure
			if (ch1 == 0) {
				System.out.println(
						"///////////////////////////////////////////////////////////////////////////////////////////////////////");

				System.out.println("Exited the program!!!!");
				System.out.println(
						"///////////////////////////////////////////////////////////////////////////////////////////////////////");

			}

		} while (ch1 == 1);
	}

}
//.................................................................................................................................................
//SAMPLE TEST 1:
//Enter the total number of elements to be stored in the array:
//5
//Enter 5 elements for the array
//10
//8
//9
//6
//1
//Enter your choice:
//1:Sort elements of array in ascending order
//2:Sort elements of array in descending order
//1
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sorting Array using Selection Sort Technique in Ascending Order..
//**BEFORE SORTING**
//[ 10  8  9  6  1 ]
//**AFTER SORTING**
//[ 1  6  8  9  10 ]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Do you want to continue?
//Yes:1
//No:0
//0
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Exited the program!!!!
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//SAMPLE TEST 2:
//Enter the total number of elements to be stored in the array:
//5
//Enter 5 elements for the array
//4
//8
//9
//6
//1
//Enter your choice:
//1:Sort elements of array in ascending order
//2:Sort elements of array in descending order
//2
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sorting Array using Selection Sort Technique in Descending Order..
//**BEFORE SORTING**
//[ 4  8  9  6  1 ]
//**AFTER SORTING**
//[ 9  8  6  4  1 ]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Do you want to continue?
//Yes:1
//No:0
//0
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Exited the program!!!!
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//***********************************************************************************************************************************************************

//Since the array size is infinte avoid using the arr.length in the code.....for start and end break the array in chunks
//with specific window size and do binary search over it since its an sorted array for logn time complexity
//we will increase the given chunk exponentialy 2^n where n=1,2,3,4,5.......
import java.util.*;
public class Searc_In_Infinite_Array{
   

   static int ans(int[] arr,int target){
      int start=0;
      int end=1;
      while(target>arr[end]){
            //increasing the window size
            int newStart=end+1;
            //Newend=previous end + window size *2 
            end=end+((end-start)+1)*2;  //Doubling the box value (end-start)+1)--> window size
            start=newStart;
      }
      return binarysearch(arr, target,start,end);
   }

   static int binarysearch(int[] arr,int target,int start,int end){
   while(start<=end){
   int mid=start +(end-start)/2;
   if(target>arr[mid]){start=mid+1;}
   else if(target<arr[mid]){end=mid-1;}
   else{return mid;}
   }
   return -1;
   }

public static void main(String[] args) {
    Scanner in=new Scanner(System.in);
    System.out.println("Enter the size of the array :");//taking arr size for now but we are not gonna use the arr.length or arr.size() in main function
     int arr[]=new int[in.nextInt()]; 
     for(int i=0;i<arr.length;i++){ 
     System.out.print(i+" : "); 
     arr[i]=in.nextInt();}
     System.out.println(ans(arr,in.nextInt()));
     
}
}

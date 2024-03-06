import java.util.*;
public class PeakIndexInMountainArray {
    static int binarysearch(int[] arr){
    int start=0;
    int end=arr.length-1;
    while(start<end){
    int mid=start +(end-start)/2;
    if(arr[mid]>arr[mid+1]){//you are in decreasing part of array
        end=mid; //this may be possible answer ,but we may have to look more in the left thus we take our new end as mid
    }else{ //(arr[mid]<arr[mid+1]) you are in increasing part of array
        start=mid+1;// cuz we need to find the greatest element
    }
    }
    //if start=mid then only one element remains by best possible case from the above two checks 
    //start and end are always trying to find the best ans which is the greatest number
    return start;  
    //you can return start or end but not mid since it's only initialized in while loop
    // since all come at same point start=end=mid 
}
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the size of the array :");
         int arr[]=new int[in.nextInt()]; 
        System.out.println("Enter the  elements in increasing and then in decreasing order :");
         for(int i=0;i<arr.length;i++){ 
         System.out.print(i+" : "); 
         arr[i]=in.nextInt();}
         System.out.println(binarysearch(arr));
    }

}

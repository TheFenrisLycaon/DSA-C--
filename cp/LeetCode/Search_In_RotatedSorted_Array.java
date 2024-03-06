//thought process :-
//[3,4,5,6,7,0,1,2]
// 1) if arr[mid]>arr[mid] then pivot would be mid since its only occuring in one case in above ex mid=7 -->[7,0] where 7>0
// 2) if arr[mid]<arr[mid-1] same thing 0<7 [mid-1] is pivot
// 3) 
import java.util.*;
public class SearchInRotatedSortedArray {

    static int search(int[] arr,int target){
        int pivot=peakValue(arr);
        int firstHalf=binarysearch(arr,target,0, pivot);
        int secondHalf=binarysearch(arr,target,pivot+1,arr.length-1);
        if(firstHalf!=-1){
            return firstHalf;
        }
        return secondHalf;
    }

    static int peakValue(int[] arr){
        int start=0;
        int end=arr.length-1;
        while(start<end){
        int mid=start +(end-start)/2;
        if(arr[mid]>arr[mid+1]){//you are in decresing part of array
            end=mid; //this may be possible answer but we may have to look more in the left thus we take our new end as mid
        }else{ //(arr[mid]<arr[mid+1]) you are in incresing part of array
            start=mid-1;// cuz we need to find the gratest element
        }
        }
        //if start=mid then only one element remains by best possible case from the above two checks 
        //start and end are always trying to find best ans which is the greatest number 
        return start; //return end or start; its all same end=start=mid=Is our answer  
        //you can return start or end but not mid since its only initialized in while loop
        // since all come at same point start=end=mid 
    }

    static int binarysearch(int[] arr,int search,int start,int end){
    while(start<=end){
    int mid=start +(end-start)/2;
    if(search>arr[mid]){
    start=mid+1;}
    else if(search<arr[mid]){
    end=mid-1;}
    else{
    return mid;
    }
    }
    return -1;
    }

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the size of the array :");
         int arr[]=new int[in.nextInt()]; 
         for(int i=0;i<arr.length;i++){ 
         System.out.print(i+" : "); 
         arr[i]=in.nextInt();}
         System.out.println(search(arr,in.nextInt()));
    }
}

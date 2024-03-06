import java.util.*;
public class FindInMountainArray {

    static int search(int arr[],int target){
        int peak=peakValue(arr);
        int firstHalf= binarysearch(arr, target,0,peak);//searches in ascending order which is first half
        int SecondHalf= binarysearch(arr, target,peak+1,arr.length-1);//searches in descending order which is second half
        if(firstHalf!=-1){
            return firstHalf;
        }
        return SecondHalf;
    }


    //order agnostic binary search
    static int binarysearch(int[] arr,int target,int start,int end){
        boolean isAsec=arr[start]<arr[end];
        while(start<=end){
            int mid=start +(end-start)/2;
            if(arr[mid]==target){
                return mid;
            }
            else{
                if(isAsec==true){ 
                    if(target>arr[mid]){
                         start=mid+1;
                    }else{
                         end=mid-1;
                    }
                }else{
                    if(target<arr[mid]){
                        start=mid+1;
                   }else{
                        end=mid-1;
                   }
                }
            }
        }
        return -1;
    }



     static int peakValue(int[] arr){
        int start=0;
        int end=arr.length-1;
        while(start<end){
        int mid=start +(end-start)/2;
        if(arr[mid]>arr[mid+1]){//you are in decresing part of array
            end=mid; //this may be possible answer but we may have to look more in the left thus we take our new end as mid
        }else{ //(arr[mid]<arr[mid+1]) you are in incresing part of array
            start=mid+1;// cuz we need to find the gratest element
        }
        }
        //if start=mid then only one element remains by best possible case from the above two checks 
        //start and end are always trying to find best ans which is the greatest number 
        return start; //return end or start; its all same end=start=mid=Is our answer  
        //you can return start or end but not mid since its only initialized in while loop
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
             System.out.println(search(arr,in.nextInt()));
        }
    
}

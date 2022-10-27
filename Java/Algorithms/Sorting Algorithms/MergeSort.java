import java.util.Arrays;

class MergeSort{
     static void merge (int arr[], int s, int e){
        //calaculate the length 
        int mid = (s+e)/2;
        int len1 = mid-s+1;
        int len2 = e-mid;
        //create two array for copy
        int arr1[] = new int[len1];
        int arr2[] = new int[len2];
        //now copy elements to  the arrays 
        int mainIndex = s;
        for(int i=0;i<len1;i++){
            arr1[i]=arr[mainIndex++];
        }
        mainIndex = mid+1;
        for(int i=0;i<len2;i++){
            arr2[i]=arr[mainIndex++];
        }
        //now compare 
        int i=0;
        int j=0;
        mainIndex =s;

        while(i<len1 && j<len2){
            if(arr1[i]<arr2[j]){
                arr[mainIndex++]=arr1[i++];
            }
            else{
                arr[mainIndex++]=arr2[j++];
            }
        }

        //now still some element left
        while(i<len1){
            arr[mainIndex++]=arr1[i++];
        }
        while(j<len2){
            arr[mainIndex++]=arr2[j++];
        }
     }

    static void mergeSort(int arr[], int s , int e){
        //base case 
        if(s>=e){
            return;
        }
        int mid = (s+e)/2;
        //sort left side of mid
        mergeSort(arr, s, mid);
        //sort right side of  mid
        mergeSort(arr, mid+1, e);

        //now merge both the sorted array
        merge(arr, s, e);
    }
    public static void main(String[] args) {
        int arr[] ={12,-1 ,98,367,12};
        System.out.println("Before sort :-"+Arrays.toString(arr));
        mergeSort(arr,0,arr.length-1);
        System.out.println("After sort :-"+Arrays.toString(arr));
    }
}
import java.util.Arrays;

// Cyclic Sort : it will only work with number from range {1,N} and without missing numbers in between

// Its a unstable algorithm : Doesnot Changes the main object while sorting even if values are same
// Its an In-Place algorithm :Doesn't use auxillary space
// time Complexity O(n^2) ----> worst case   n(n-1)/2
//                O(n^2) ----> best case    
// Space complexity and Auxillary space complexity : O(1) 
                                //Very imp formual index = value-1  arr: 5 4 3 2 1   for 5 in arr it should be in index=5-1=4-->index 
public class CycleSort {
    static void cycle(int arr[]){
           for(int i=0;i<arr.length;i++){
                if(arr[i]-1!=i){
                    int temp=arr[arr[i]-1];
                    arr[arr[i]-1]=arr[i];
                    arr[i]=temp;
                    i--;
                }
           } 
        }
     
        static void cycleWhile(int arr[]){
            int i=0;
            while(i<arr.length){
                int correctIndex=arr[i]-1;
                 if(arr[i]!=arr[correctIndex]){
                     int temp=arr[correctIndex];
                     arr[correctIndex]=arr[i];
                     arr[i]=temp;
                 }
                 else{
                    i++;
                 }
            }        
    }
    public static void main(String[] args) {
        int[] arr={3,5,2,1,4};
        cycle(arr);
        System.out.println(Arrays.toString(arr));
    }
    
}

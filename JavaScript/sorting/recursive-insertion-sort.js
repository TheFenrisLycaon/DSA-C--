//Recursive insertion sort
let recursiveInsertionSort = (arr, i = arr.length) => {
    //if index is less than 1 then return
    if(i <= 1){
      return;
    }
     
    //Recursively call the same function
    recursiveInsertionSort(arr, i - 1);  
  
    let key = arr[i - 1];
    let j = i - 2;
    
    //Sort the array
    while(j >= 0 && arr[j] > key){
      arr[j + 1] = arr[j];
      j--;
    }
  
    arr[j + 1] = key; 
}
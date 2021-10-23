var arrayToSearch = [2, 6, 8, 12, 14, 16, 20, 24, 26, 28, 30, 31, 35];
var length = arrayToSearch.length;
var low = 0;
var high = length-1;
console.log("Found at position :" + interpolationSearch(arrayToSearch, 2, 0, high));
console.log("Found at position :" + interpolationSearch(arrayToSearch, 12, 0, high));
console.log("Found at position :" + interpolationSearch(arrayToSearch, 35, 0, high));
console.log("Found at position :" + interpolationSearch(arrayToSearch, 44444, 0, high));
 
function interpolationSearch(arrayToSearch, valueToSearch, low, high){
  if(low <= high 
        && valueToSearch >= arrayToSearch[low]
        && valueToSearch <= arrayToSearch[high]){
    var delta = (valueToSearch-arrayToSearch[low])/(arrayToSearch[high]-arrayToSearch[low]);
    var position = low + Math.floor((high-low)*delta);
    if (arrayToSearch[position] == valueToSearch){
      return position;
    }
    if (arrayToSearch[position] < valueToSearch){
      low = position + 1;
    } else {
      high = position - 1;
    }
    return interpolationSearch(arrayToSearch, valueToSearch, low, high)
  }
 
  return -1;
}
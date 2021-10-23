/*Write a function to implement binary search of an array of numbers*/ 
function binarySearch(arr, key) {
    if (arr.length < 1) {
        return -1;
    }
    let lowerBound = 0;
    let upperBound = arr.length - 1;

    while (lowerBound <= upperBound) {
        let mid = Math.floor((lowerBound + upperBound) / 2);
        if (arr[mid] === key) {
            return `Found at index ${mid}`;
        }
        else if (key > arr[mid]) {
            lowerBound = mid + 1;
        }
        else {
            upperBound = mid - 1;
        }
    }
    return `Element not found!`;
}

console.log(binarySearch([1, 2, 3, 4, 5, 6, 7, 100, 999], 4));
console.log(binarySearch([-1, 2, 4, 5, 10, 89], 89));
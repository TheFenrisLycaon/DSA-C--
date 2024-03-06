/*Write a function to implement a radix sort algorithm*/ 
// Defining Helper Methods for radix sort

function getDigit(num, i) {
    return Math.floor(Math.abs(num) / Math.pow(10, i)) % 10;
}

function digitLength(num) {
    return String(Math.abs(num)).length + 0;
}

function mostDigits(nums) {
    let max = 0;
    for (let i = 0; i < nums.length; i++){
        max = Math.max(max, digitLength(nums[i]));
    }
    return max;
}

// console.log(getDigit(-09798, 5));
// console.log(digitLength(-9273298));
// console.log(mostDigits([87,-987,8759]))

// Works only for +ive numbers
function radixSort(arr) {
    let maximumDigits = mostDigits(arr);

    for (let i = 0; i < maximumDigits; i++){
        let buckets = Array.from({ length: 10 }, () => []);
        

        for (let j = 0; j < arr.length; j++){
            buckets[getDigit(arr[j],i)].push(arr[j]);
        }

        arr = [].concat(...buckets);
    }
    return arr;
}

console.log(radixSort([11, 10, 0, 8, 976, 9861]));
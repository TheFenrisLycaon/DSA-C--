/*Write a function to count how many times a smaller string exists in larger string*/

function stringCount(longerString, pattern) {
    let count = 0;

    for (i = 0; i < longerString.length; i++) {
        for (j = 0; j < pattern.length; j++) {
            if (pattern[j] !== longerString[i + j]) {
                break;
            }

            if (j === pattern.length - 1) {
                count += 1;
            }
        }
    }
    return count;
}
console.log(stringCount("wowomgzomg", "omg"));
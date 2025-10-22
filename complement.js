// Function to perform binary search
function binarySearch(arr, left, right, target) {
    while (left <= right) {
        let mid = Math.floor(left + (right - left) / 2);

        if (arr[mid] === target)
            return true;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

function twoSum(arr, target) {
    arr.sort((a, b) => a - b);

    for (let i = 0; i < arr.length; i++) {
        let complement = target - arr[i];

        // Use binary search to find the complement
        if (binarySearch(arr, i + 1, 
                    arr.length - 1, complement))
            return true;
    }
    // If no pair is found
    return false;
}

// Driver Code
let arr = [0, -1, 2, -3, 1];
let target = -2;

if (twoSum(arr, target)) {
    console.log("true");
} else {
    console.log("false");
}

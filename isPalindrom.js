

const isPalindrom = (string) => {

    // convert string to an array
    const palString = string.split('')

    // set pointers for each end of the array
    let i = 0;
    let j = palString.length - 1

    // loop through array, checking to see if palString[i] === palstring[j]
    while (i < j) {
        if (palString[i] !== palString[j]){
            console.log(`${string} is not a Palindrom`)
            return false;
        }

        i++
        j--
    }

    console.log(`${string} is a Palindrom!`)
    return true;
}

isPalindrom('asdfsds')
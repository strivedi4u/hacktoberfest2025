function checkPalindrom (str) {
  return str == str.split('').reverse().join('');
}

let test = "naman"
if(checkPalindrom(test)) {
  console.log("Yes")
}else {
  console.log("No")
}

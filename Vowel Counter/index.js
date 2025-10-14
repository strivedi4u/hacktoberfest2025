let inputtext = document.getElementById("box");
let button = document.getElementById("click");
let button1 = document.getElementById("click1");
let p = document.getElementById("answer");


    button.addEventListener("click", function name() {
        if (inputtext.value === "") {
            alert("Please enter the text.")
        } 
        else {
        let count = 0;
        let text = inputtext.value;
        for (const i of text) {
            if (i === "a" || i === "e" || i === "i" || i === "o" || i === "u" || i === "A" || i === "E" || i === "I" || i === "O" || i === "U") {
                count = count + 1;
            }
        }
        p.innerHTML = `<b>Total Vowel Characters : ${count}</b>`;
    }})


button1.addEventListener("click", function one() {
    inputtext.value= "";
    p.innerHTML = "";
})
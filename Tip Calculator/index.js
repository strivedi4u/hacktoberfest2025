let inputamount = document.getElementById("amount");
let inputpercentage = document.getElementById("percentage");
let inputperson = document.getElementById("person");
let output = document.getElementById("submit");
let get = document.getElementById("answer");

output.addEventListener("click", function display() {
    // Clear the previous output
    get.innerHTML = "";

    // Validate input values for empty fields
    if (inputamount.value === "" || inputpercentage.value === "" || inputperson.value === "") {
        alert("Please enter values for all fields.");
    }
    // Validate that the inputs are numbers
    else if (isNaN(inputamount.value) || isNaN(inputpercentage.value) || isNaN(inputperson.value)) {
        alert("Please enter valid numeric values only.");

        // Clear the invalid input fields
        inputamount.value = "";
        inputpercentage.value = "";
        inputperson.value = "";
    }
    // If inputs are valid, calculate values
    else {
        // Calculate values
        let tipAmount = Number(inputamount.value) * (Number(inputpercentage.value) / 100);
        let totalAmount = tipAmount + Number(inputamount.value);
        let amountPerPerson = totalAmount / Number(inputperson.value);

        // Display new output
        get.innerHTML += `Tip Amount : Rs. ${tipAmount.toFixed(2)} <br><br>`;
        get.innerHTML += `Total Amount : Rs. ${totalAmount.toFixed(2)} <br><br>`;
        get.innerHTML += `Amount to be paid by each one : Rs. ${amountPerPerson.toFixed(2)}`;
    }
});

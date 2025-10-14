// Function to generate random RGB color
function getRandomRGB() {
    const r = Math.floor(Math.random() * 256);
    const g = Math.floor(Math.random() * 256);
    const b = Math.floor(Math.random() * 256);
    return `rgb(${r}, ${g}, ${b})`;
}

// Selecting the button and color value elements
const button = document.getElementById('colorButton');
const colorValue = document.getElementById('colorValue');


button.addEventListener('click', function () {
    
    const randomColor = getRandomRGB();

    
    document.body.style.backgroundColor = randomColor;

 
    colorValue.textContent = randomColor;
});

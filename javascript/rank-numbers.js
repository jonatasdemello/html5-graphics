// ---------------------------------------------------------------------------------------------------
// Generate an array of 1000 float numbers ranging from 0.0 to 0.9999
let array = Array.from({ length: 1000 }, () => Math.random() * 0.9999);

// Define the category boundaries
let boundaries = [0.0, 0.16665, 0.3333, 0.49995, 0.6666, 0.83325, 0.9999];
let categories = ['A', 'B', 'C', 'D', 'E', 'F'];

// Function to categorize the numbers
function categorize(number, boundaries, categories) {
    for (let i = 0; i < boundaries.length - 1; i++) {
        if (number >= boundaries[i] && number < boundaries[i + 1]) {
            return categories[i];
        }
    }
    return categories[categories.length - 1];
}

// Categorize the array
let categorizedArray = array.map(num => categorize(num, boundaries, categories));

console.log(categorizedArray);

// ---------------------------------------------------------------------------------------------------

// Generate an array of 1000 float numbers ranging from 0.0 to 0.9999
let array = Array.from({ length: 1000 }, () => Math.random() * 0.9999);

// Define your custom category names
let categories = ['Alpha', 'Beta', 'Gamma', 'Delta', 'Epsilon', 'Zeta', 'Eta', 'Theta'];

// Calculate the interval width based on the number of categories
let intervalWidth = 0.9999 / categories.length;

// Define the category boundaries
let boundaries = Array.from({ length: categories.length + 1 }, (_, i) => i * intervalWidth);

// Function to categorize the numbers
function categorize(number, boundaries, categories) {
    for (let i = 0; i < boundaries.length - 1; i++) {
        if (number >= boundaries[i] && number < boundaries[i + 1]) {
            return categories[i];
        }
    }
    return categories[categories.length - 1];
}

// Categorize the array
let categorizedArray = array.map(num => categorize(num, boundaries, categories));

console.log(categorizedArray);


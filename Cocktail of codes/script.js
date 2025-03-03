// Initialize a counter variable
let count = 0;

// Function to update the displayed counter
function updateCounter() {
  document.getElementById("counter").textContent = count;
}

// Event listener for the "Increase" button
document.getElementById("increaseButton").addEventListener("click", function () {
  count++; // Increment the counter
  updateCounter(); // Update the displayed value
});

// Event listener for the "Reset" button
document.getElementById("resetButton").addEventListener("click", function () {
  count = 0; // Reset the counter
  updateCounter(); // Update the displayed value
});

import numpy as np

# Generate an array of 1000 float numbers ranging from 0.0 to 0.9999
array = np.random.uniform(0.0, 0.9999, 1000)

# Define the category boundaries
boundaries = np.linspace(0.0, 0.9999, 12)

# Function to categorize the numbers
def categorize(number, boundaries):
    for i in range(len(boundaries) - 1):
        if boundaries[i] <= number < boundaries[i + 1]:
            return i + 1
    return len(boundaries) - 1

# Categorize the array
categories = [categorize(num, boundaries) for num in array]

print(categories)

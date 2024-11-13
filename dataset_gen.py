import random
def generate_nearly_sorted_data(num_integers, sorted_percentage=0.85):
    """
    Generate a nearly sorted dataset with a specified percentage already sorted.
    """
    # Calculate the count of elements that should be in sorted order
    sorted_count = int(num_integers * sorted_percentage)

    # Create a sorted list of random integers within the C int range
    nearly_sorted_data = sorted(random.randint(-2147483648, 2147483647) for _ in range(sorted_count))
    
    # Add unsorted random integers to the list to fill it up to the desired count
    nearly_sorted_data += [random.randint(-2147483648, 2147483647) for _ in range(num_integers - sorted_count)]
    
    # Shuffle a small portion of the list to simulate "nearly sorted"
    # Swap random pairs within the nearly sorted segment
    for _ in range(int(num_integers * (1 - sorted_percentage) * 2)):  # Adjust based on the unsorted proportion
        i, j = random.sample(range(sorted_count), 2)
        nearly_sorted_data[i], nearly_sorted_data[j] = nearly_sorted_data[j], nearly_sorted_data[i]

    return nearly_sorted_data

# Generate datasets with 10,000 and 50,000 nearly sorted numbers
nearly_sorted_10k = generate_nearly_sorted_data(10000)
nearly_sorted_50k = generate_nearly_sorted_data(50000)

# Prepare and save the 10,000 dataset
nearly_sorted_10k_content = f"{len(nearly_sorted_10k)}\n" + "\n".join(map(str, nearly_sorted_10k))
nearly_sorted_10k_file_path = ".\sorting_test_case_nearly_sorted_10k.txt"
with open(nearly_sorted_10k_file_path, "w") as f:
    f.write(nearly_sorted_10k_content)

# Prepare and save the 50,000 dataset
nearly_sorted_50k_content = f"{len(nearly_sorted_50k)}\n" + "\n".join(map(str, nearly_sorted_50k))
nearly_sorted_50k_file_path = ".\sorting_test_case_nearly_sorted_50k.txt"
with open(nearly_sorted_50k_file_path, "w") as f:
    f.write(nearly_sorted_50k_content)

nearly_sorted_10k_file_path, nearly_sorted_50k_file_path

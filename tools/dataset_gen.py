import numpy as np

#random arrays
def array_gen(n, n_digits):
    #random in range [low, high)

    return np.random.randint(low=1, high=pow(10, n_digits), size=(n))

#special-case arrays
def array_spec(n, n_digits, order):
    #order == 1 increasing
    
    res = np.random.randint(low=1, high=pow(10, n_digits), size=(n))
    return np.sort(res) if order else np.sort(res)[::-1]

def print_array(array, f):
    for x in array:
        print(x, end = " ", file=f)
    print("", file=f)

file_dir = "./data"
def data_gen(n_files, n_spec, n_size, n_digits):
    # #random arrays
    for i in range(1, n_files - n_spec + 1):
        with open(f"{file_dir}/{i}.inp", "w") as f:
            print(n_size, file=f)
            print_array(array_gen(n_size, n_digits), f)
    
    # #special cases (increasing and decreasing)
    for i in range(n_files - n_spec + 1, n_files + 1):
        with open(f"{file_dir}/{i}.inp", "w") as f:
            print(n_size, file=f)
            print_array(array_spec(n_size, n_digits, i % 2), f)
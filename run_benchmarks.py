import os
import sys
import time
import argparse
from tools import dataset_gen 
import numpy as np 

#9 algorithms
algorithms = ["Quick Sort",
              "Heap Sort",
              "Merge Sort",
              "Cpp Sort",
              "Numpy Sort"]

algo_files = ["quick_sort.cpp",
              "heap_sort.cpp",
              "merge_sort.cpp",
              "cpp_sort.cpp",
              "numpy_sort.py"]
algo_exe = []
for f in algo_files:
    if f[-3:] == ".py":
        algo_exe.append(f[:-3])
    else:
        algo_exe.append(f[:-4])


algo_dir = "./algorithms"
data_dir = "./data"


def get_args():
    parser = argparse.ArgumentParser(description='Sorting algorithms Evaluation')
    
    parser.add_argument('--n_files', default=10, type=int, help='number of files to run benchmark')
    parser.add_argument('--n_spec', default=2, type=int, help='number of special-case files to run')
    parser.add_argument('--n_size', default=200000, type=int, help='size of generated arrays')
    parser.add_argument('--n_digits', default=6, type=int, help='number of maximum digits for generated values')

    args = parser.parse_args()

    return args


#run benchmark
def main(args):
    print("Generating input files...")
    dataset_gen.data_gen(args.n_files, args.n_spec, args.n_size, args.n_digits)

    #compile cpp files
    print("Compiling files...")
    for i in range(len(algo_files)):
        f = algo_files[i]
        if f[-3:] != ".py":
            os.system(f"g++ {algo_dir[2:]}/{f} -o {algo_dir[2:]}/{algo_exe[i]}")
    

    print("Running Benchmark!")
    total = np.zeros(len(algo_files))
    for i in range(args.n_files):
        print(f"run {i + 1}:", end=" ")

        ind = 0
        for f in algo_files:
            f_exe = ""
            isPython = False
            if f[-3:] == ".py":
                f_exe = f[:-3]
                isPython = True
            else:
                f_exe = f[:-4]

            start = time.time()
            
            runtime = 0
            if not isPython:
                os.system(f"{algo_dir[2:]}\\{f_exe} < {data_dir[2:]}\\{i + 1}.inp > {data_dir[2:]}\\{i + 1}_{f_exe}.out")
            else:
                os.system(f"python {algo_dir[2:]}/{f_exe}.py < {data_dir[2:]}/{i + 1}.inp > {data_dir[2:]}/{i + 1}_{f_exe}.out")
            
            end = time.time()
            if not isPython:
                runtime = 1000 * (end - start)
            else:
                with open(f"{data_dir[2:]}/{i + 1}_{f_exe}.out", "r") as f:
                    runtime = float(f.readline())
            
            print(f"{runtime: .3f} ms", end=" ")
            total[ind] += runtime
            ind += 1
        print("")

    print("Average exc time: ")
    for i in range(len(algo_files)):
        print(f"{total[i] / args.n_files : .3f} ms ", end="")
    print("")

    


if __name__ == "__main__":
    args = get_args()
    main(args)
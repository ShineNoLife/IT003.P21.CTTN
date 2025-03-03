Benchmarks for:
    Quicksort, Heapsort, Mergesort, C++ sort, and Numpy sort.

this benchmark is used to test the running time of these algorithms on 
randomly generated tests and special-cases (increasing or decreasing sequences).

The running time is then averaged over the tests.
This benchmark can be configurated to change some variables (number of tests, size of tests, etc.)

to run the basics, use the command:

```shell
python run_benchmarks.py --n_files=10 --n_size=200000
```
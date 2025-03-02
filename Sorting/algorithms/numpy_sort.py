import sys, argparse
import numpy as np
import time

def main():
    n = 1
    v = []

    n = int(sys.stdin.readline())
    v = np.fromstring(sys.stdin.readline(), dtype=int, sep=" ")

    start = time.time()
    v = np.sort(v)
    end = time.time()
    
    print(1000.0 * (end - start))




if __name__ == "__main__":
    main()
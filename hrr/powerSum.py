#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'powerSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER X
#  2. INTEGER N
#

def powerSum(X, N):
    
    def dfs(total, power, num_present):
        val = total - num_present**power
        
        if val <= 0:
            if val == 0:
                return 1
            return 0
            
        
        
        return dfs(val, power, num_present+1) + dfs(total, power, num_present+1)
            
        
    return dfs(X, N, 1)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    X = int(input().strip())

    N = int(input().strip())

    result = powerSum(X, N)

    fptr.write(str(result) + '\n')

    fptr.close()

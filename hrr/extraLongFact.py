#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'extraLongFactorials' function below.
#
# The function accepts INTEGER n as parameter.
#

def extraLongFactorials(n):

    res=1
    if n==0:
        return 1
    else:
        for x in range(1,n+1):
            res*=x
    print(res)
    

if __name__ == '__main__':
    n = int(input().strip())

    extraLongFactorials(n)

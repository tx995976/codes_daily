import imp
import os
import sys

def test(name,i,**kwargs):
    print(name)
    print(i)
    sss = kwargs[sss]
    print(sss)

test(sys.argv[1],sys.argv[2],sss=2)
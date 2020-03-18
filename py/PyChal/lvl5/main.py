#!/usr/bin/python

import pickle

with open('banner.p', 'rb') as f:
    obj = pickle.load(f)

for elt in obj:
    for subelt in elt:
        for i in range(subelt[1]):
            print(subelt[0], end='')
    print()

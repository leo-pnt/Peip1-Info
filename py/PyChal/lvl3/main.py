#!/usr/bin/python

picked_letters = str()

with open('raw.txt', 'r') as f:
    for line in f:
        for i in range(4, len(line)-4):
            if line[i].islower() and line[i-4].islower() and line[i+4].islower():
                if line[i-3].isupper() and line[i-2].isupper() and line[i-1].isupper() and line[i+1].isupper() and line[i+2].isupper() and line[i+3].isupper():
                    picked_letters += line[i]

print(picked_letters)

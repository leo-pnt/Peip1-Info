#!/usr/bin/python

whitelist = "abcdefghijklmnopqrstuvwxyz"
picked_letter = str()

with open('raw.txt', 'r') as f:
    data = f.read()
    for line in data:
        for letter in line:
            if letter in whitelist:
                picked_letter += letter

print(picked_letter)

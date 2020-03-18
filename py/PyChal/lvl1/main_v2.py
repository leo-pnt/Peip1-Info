#!/usr/bin/python

intab =  "abcdefghijklmnopqrstuvwxyz"
outtab = "cdefghijklmnopqrstuvwxyzab"

trantab = str.maketrans(intab, outtab)

with open('raw.txt', 'r') as f:
    data = f.read()
print(data.translate(trantab))

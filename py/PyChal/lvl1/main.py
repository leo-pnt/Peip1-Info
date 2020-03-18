#!/usr/bin/python

whitelist = "abcdefghijklmnopqrstuvwxyz"

with open('raw.txt', 'r') as f:
    data = f.read()
    for letter in data:
        if letter == " ":
            print(" ", end='')
        elif letter == 'y':
            print('a', end='')
        elif letter == 'z':
            print('b', end='')
        elif letter in whitelist and letter!=' ' and letter!='y' and letter!='z':
            print(chr(ord(letter) + 2), end='')
        else:
            print(letter, end='')

print('END')

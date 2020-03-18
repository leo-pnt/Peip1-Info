#!/usr/bin/python

from zipfile import ZipFile

with ZipFile('channel.zip', 'r') as zip:
    data = zip.read('readme.txt').decode(encoding='UTF-8',errors='strict')
    print(data)
next_number = input('[next_number]> ')

comments = str()

with ZipFile('channel.zip', 'r') as zip:
    while True:
        file_name = next_number + '.txt'
        data = zip.read(file_name).decode(encoding='UTF-8',errors='strict')
        info = zip.getinfo(file_name)
        print(info.comment.decode(encoding='UTF-8',errors='strict'), end='')
        if len(data.split()) == 4:
            #print(data)
            next_number = data.split()[-1]
        else:
            print(data)
            print('\nsomething has changed. ctrl-C to quit')
            try:
                next_number = input('[next_number]> ')
            except KeyboardInterrupt:
                print('\nprogram ended')
                break

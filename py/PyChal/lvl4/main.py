#!/usr/bin/python

from urllib.request import urlopen

urlBase = 'http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing='
url = urlBase + str(12345)

while True:
    webUrl = urlopen(url)
    rawData = webUrl.read()
    data = rawData.decode(encoding='UTF-8',errors='strict')
    if len(data.split()) == 6:
        nextNumber = data.split()[-1]
        url = urlBase + nextNumber
        print('> {}'.format(url))
        print('# {}'.format(data))
    else:
        print('> {}'.format(url))
        print('# {}'.format(data))
        print('\nSomething has changed. Please update number. ctrl+C to quit')
        print('[number]>>', end='')
        try:
            nextNumber = input()

        except KeyboardInterrupt:
            print('\nprogram ended')
            break

        url = urlBase + nextNumber

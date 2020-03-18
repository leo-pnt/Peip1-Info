#!/usr/bin/python

from PIL import Image

def isGrey(pixel):
    R = pixel[0]
    G = pixel[1]
    B = pixel[2]
    if G == R and B == R:
        return True
    else:
        return False

with Image.open('oxygen.png') as img:
    data = img.load() #data is now a list[x,y] coordinate for pixel
    dataSize = img.size #dataSize is a tuple (x,y)

y = int(dataSize[1]/2)

newPxl = (0,0,0,255)
cryptData = list()
pxlCount = 0
pxlSize = 7

#search number of color pixels
NbcolorPxl = 0
for x in range(dataSize[0]):
    pxl = data[x,y] # tuple (R,G,B,A)
    if not isGrey(pxl):
        NbcolorPxl += 1

for x in range(0, dataSize[0]-NbcolorPxl, pxlSize):
    pxl = data[x,y] # tuple (R,G,B,A)
    cryptData.append(pxl[0])

cryptDataCHR = list()
print(cryptData)
for elt in cryptData:
    cryptDataCHR.append(chr(elt))
print('\n'+''.join(cryptDataCHR))

#--- now we translate manually the answer given
nLevelCrypted = [105, 110, 116, 101, 103, 114, 105, 116, 121]
nLevel = list()
for elt in nLevelCrypted:
    nLevel.append(chr(elt))
print('\ntranslated :')
print(nLevel)
print(''.join(nLevel))

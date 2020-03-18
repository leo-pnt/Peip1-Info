import pyinputplus as pyin
import shelve

f = shelve.open('myData')
wow = f['someData']

print(list(f.keys()))

f.close()

print(wow)
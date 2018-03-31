# filefuzzer.py
#
# python script
#
# "file fuzzer"
#
# generates a bunch of random data using os.urandom then writes it to fuzzy.csv
# this was used to generate fuzzy.csv
# fuzzy.csv is used to test error handling when reading data
import os

with open('fuzzy.csv', 'wb') as fout:
    fout.write(os.urandom(1024*50)) # replace 1024 with size_kb if not unreasonably large
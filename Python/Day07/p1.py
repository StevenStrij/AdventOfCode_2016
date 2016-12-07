import sys, re

filter1 = r'(.)([^\1])\2\1'
filter2 = r''


for line in sys.stdin:
    if re.match(filter1, line):
        print(line)

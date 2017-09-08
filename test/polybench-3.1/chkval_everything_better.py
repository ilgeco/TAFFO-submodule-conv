#!/usr/bin/env python3

import sys
import re
import os


def ParseInput(filename):
  out = []
  with open(filename, 'r') as f:
    f.readline() # discard table header
    l = f.readline()
    while l != '':
      r = re.findall('[a-zA-Z0-9\.+-_]+', l)
      for i in range(1, len(r)):
        if r[i] == '-':
          r[i] = None
        else:
          r[i] = float(r[i])
      out.append(r)
      l = f.readline()
  return out
  

def SumEverything(table1, table2):
  for i in range(len(table1)):
    for j in range(1, len(table1[i])):
      if table1[i][j]:
        table1[i][j] += table2[i][j]
  

def DivideEverything(table, n):
  for i in range(len(table)):
    for j in range(1, len(table[i])):
      if table[i][j]:
       table[i][j] /= n
       
       
def PrettyPrint(table):
  widths=[15,  10,  10,   11,  11, 11,  13]
  format=['s','.6f','.6f','d','d','.2f','.5e']
  titles=['', 'fix T', 'flo T', '# ofl fix', '# ofl flo', 'avg err %', 'avg abs err']
  normalfmt=['%' + str(widths[i]) + format[i] for i in range(len(widths))]
  fallbackfmt=['%' + str(widths[i]) + 's' for i in range(len(widths))]
  print(''.join([fallbackfmt[i] % titles[i] for i in range(len(widths))]))
  for i in range(len(table)):
    for j in range(len(table[i])):
      if not (table[i][j] is None):
        v = normalfmt[j] % table[i][j]
      else:
        v = fallbackfmt[j] % '-'
      print(v, end='')
    print('')


if len(sys.argv) != 2:
  print("usage: %s <n_tries>" % sys.argv[0])
  exit(1)
ntries = int(sys.argv[1])

t = None
t2 = None
print("trial 1", file=sys.stderr)
os.system("./chkval_everything.sh > .tmp")
t = ParseInput(".tmp")
for i in range(ntries-1):
  print('trial %d' % (i+2), file=sys.stderr)
  os.system("./chkval_everything.sh > .tmp")
  t2 = ParseInput(".tmp")
  SumEverything(t, t2)
DivideEverything(t, ntries)
PrettyPrint(t)
os.remove(".tmp")

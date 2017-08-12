#!/usr/bin/env python3

import sys
import math


def ReadValues(filename):
  with open(filename, 'r') as f:
    l = f.readline()
    while l != '':
      for v in l.strip().split():
        if v != '':
          yield v
      l = f.readline()


n = 0
accerr = 0
fix_nofl = 0
flo_nofl = 0

for svfix, svflo in zip(ReadValues(sys.argv[1]), ReadValues(sys.argv[2])):
  vfix, vflo = float(svfix), float(svflo)
  if math.isnan(vfix):
    fix_nofl += 1
  elif math.isnan(vflo):
    flo_nofl += 1
  elif abs(vflo - vfix) > vflo/2:
    fix_nofl += 1
  else:
    n += 1
    accerr += abs(vflo - vfix)
  
print(fix_nofl, flo_nofl, '%.2f' % (accerr / n))

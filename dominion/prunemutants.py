import glob
import os

covered = {}

n = 1
for l in open("dominion.c.gcov"):
    timesRun = (l.split(":")[0]).split()[0]
    line = int(l.split(":")[1])
    if (timesRun != "-") and (timesRun != "#####"):
        covered[line] = int(timesRun)

for m in glob.glob("mutant*dominion.c"):
    n = 1
    for l in open(m):
        if "MUTANT" in l:
            break
        n += 1
    if n not in covered:
        print "DELETING NEVER-COVERED MUTANT",m
        os.remove(m)

import glob
import os
import subprocess

covered = {}

n = 1
for l in open("basecoverage"):
    timesRun = (l.split(":")[0]).split()[0]
    line = int(l.split(":")[1])
    if (timesRun != "-") and (timesRun != "#####"):
        covered[line] = int(timesRun)

totalKilled = 0.0
totalTested = 0.0

for m in glob.glob("mutant*dominion.c"):
    print "CHECKING MUTANT",m
    n = 1
    for ml in open(m):
        if "MUTANT" in ml:
            break
        n += 1
    subprocess.call(["cp " + m + " dominion.c; make clean; make all >& /dev/null"],shell=True)
    if not os.path.exists("playdom"):
        print "DOES NOT COMPILE!"
        subprocess.call(["mv " + m + " compilefail"],shell=True)
        continue
    subprocess.call(["rm -rf playdom.3.out; ulimit -t 5; ./playdom 3 >& playdom.3.out"],shell=True)
    totalTested += 1
    d = subprocess.call(["diff playdom.3.out playdom.3.baseline.out >& /dev/null"], shell=True)
    if d == 0:
        print "MUTANT NOT KILLED!!!!!!!"
        print "LINE =",n,"COVERED",covered[n],"TIMES"
        print ml
        subprocess.call(["mv " + m + " notkilled"],shell=True)
    else:
        print "MUTANT KILLED"
        totalKilled += 1
        subprocess.call(["mv " + m + " killed"],shell=True)
    print "MUTATION SCORE:",totalKilled/totalTested    

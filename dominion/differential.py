import subprocess
import os

nullf = open(os.devnull,'w')

dominion1dir = "../projects/olsomatt/"
dominion2dir = "../projects/millsma/dominion"

dominions = [(dominion1dir, "olsomatt"), (dominion2dir, "millsma")]

subprocess.call(["make clean; make all"], shell=True)

testexes = []

for (d, n) in dominions:
    c1 = "cd " + d + "; make clean; make all"
    subprocess.call ([c1], shell=True, stderr = nullf, stdout = nullf)
    c2 = "gcc -o " + n + "test fulldomtest.c " + d + "/dominion.o rngs.o interface.o --coverage" 
    subprocess.call ([c2], shell=True, stderr = nullf, stdout = nullf)
    testexes.append (n + "test")

numTests = 100


for t in xrange(1,numTests+1):
    print "TEST/SEED #", t
    outfiles = []
    for e in testexes:
        eout = open(e+".out",'w')
        subprocess.call(["./" + e + ".exe", str(t)], stdout=eout, stderr = nullf)
        eout.close()
        outfiles.append(e+".out") 
        
    r = subprocess.call(["diff " + outfiles[0] + " " + outfiles[1]], shell=True, stderr = nullf, stdout = nullf)
    if (r != 0):
        print "DIFFERENCE DETECTED, ABORTING"
        break
        
    

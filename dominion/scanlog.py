import sys
import re

logfile = sys.argv[1]
propfile = sys.argv[2]

FSM = {}

for l in open(propfile):
    [state, action] = l.split(":")
    (pat, nextState) = action.split("->")
    nextState = nextState.replace("\n","")
    print (state, pat, nextState)
    if state in FSM:
        FSM[state].append((pat,nextState))
    else:
        FSM[state] = [(pat, nextState)]

print FSM        

s = "s0"

for line in open(logfile):
    print (s, line)
    for (pat, nextState) in FSM[s]:
        if re.match(pat,line):
            s = nextState
            if nextState == "error":
                print "ERROR"
                sys.exit(0)

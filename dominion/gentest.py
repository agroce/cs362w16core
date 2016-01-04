import sys
import random
import subprocess

outf = open(sys.argv[1], 'w')
length = int(sys.argv[2])
if (len(sys.argv) > 2):
    random.seed(int(sys.argv[3]))

Kcards = ["adventurer", "council_room", "feast", "gardens", "mine", "remodel", "smithy", "village", "baron", "great_hall",
          "minion", "steward", "tribute", "outpost", "salvager", "sea_hag",
          "treasure_map"]

random.shuffle(Kcards)
initCards = ""
for i in xrange(0,10):
    initCards += Kcards[i] + ","
    
initCards = initCards[0:-1]

Kcards.append("gold")

handPos = lambda:str(random.randint(0,10))
choice = lambda:str(random.randint(0,10))
def supplyPos():
    if random.choice([True,False]):
        return "copper"
    if random.choice([True,False]):
        return str(random.choice(Kcards))
    return str(random.randint(0,27))

API = [("endTurn", []),
       ("playCard", [handPos, choice, choice, choice]),
       ("buyCard", [supplyPos])]

def call((f, args)):
    outf.write("  printf(\"%d: \", G.whoseTurn);")
    outf.write("  for (i = 0; i < numHandCards(&G); i++) {")
    outf.write("    cardNumToName(handCard(i, &G), cardName);")
    outf.write("    printf(\"%s \", cardName);")
    outf.write("  }")
    outf.write("  printf (\"\\n\");")
    callstr = f + "("
    for arg in args:
        callstr += arg() + ", "
    callstr += "&G)"

    outf.write("  printf(\"" + callstr + "\");\n")
    outf.write("  r = " + callstr + ";\n")
    outf.write("  printf(\" = %d\\n\", r);")

outf.write("#include \"dominion.h\"\n")
outf.write("\nint main() {\n")

outf.write("  int r, i;\n")
outf.write("  char cardName[200];\n")
outf.write("  struct gameState G;\n")
outf.write("  int k[10] = {" + initCards + "};\n")
outf.write("  printf(\"" + initCards+ "\\n\");")
rseed = str(random.randint(0,1000000))

outf.write("  initializeGame(" + str(random.choice([2,3,4])) + ", k, " + rseed + ", &G);\n")

for i in xrange(0,length):
    call(random.choice(API))

outf.write("  printf(\"TEST SUCCESSFULLY COMPLETED.\\n\");\n")
outf.write("  return 0;\n")
outf.write("}\n")

outf.close()

subprocess.call(["gcc -o thetest " + sys.argv[1] + " dominion.c rngs.c interface.c -lm -coverage -g"], shell=True)
subprocess.call(["rm -rf out; ./thetest >& out"], shell=True)

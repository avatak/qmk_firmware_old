
# Braid thing           col 1 col 2 ... col 21
#               row 5
#               row 6
#               row 7

gridW = 32
gridH = 7

grid = [[hex(i*32 + j) for j in range(gridW)] for i in range(gridH)]

def getBlock(r1,c1,r2,c2):
    block_temp = []
    for i in range(r1,r2):
        for j in range(c1,c2):
            block_temp.append(grid[i][j])
    return block_temp

def printBlock(r1,c1,r2,c2):
    block_temp = []
    for i in range(r1,r2):
        for j in range(c1,c2):
            print(grid[i][j],end=',')
        if i == r2 - 1:
            print("0",end='')
        print()

#rowStart    = int(input("Beginning row: "))-1
#rowEnd      = int(input("Ending row: "))
#colStart    = int(input("Beginning column: "))-1
#colEnd      = int(input("Ending column: "))
#
#
#printBlock(rowStart,colStart,rowEnd,colEnd)

bigIcon = []
for j in range(3):
    bigIcon = bigIcon + [[hex((4+j)*32 + i) for i in range(8)]+[hex(32*(4+j)+27+s) for s in range(5)]+[hex((4+j)*32 + 8 + 5 + i) for i in range(8)]]

for row in range(3):
    for n in bigIcon[row]:
        print(n,end=',')
    if row == 2:
        print('0',end='')
    print()

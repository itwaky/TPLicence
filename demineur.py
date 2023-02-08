import random


# 9 = mine / chiffre inférieur a 9 = libre

# 2,2 --> 2,1 / 1,2 / 1,1 / 3,3 / 1,3 / 3,1 / 2,3 / 3,2
#
#   /1,1|1,2|1,3/
#   /2,1|2,2|2,3/
#   /3,1|3,2|3,3/
#

def afficherMatrice (matrice):
    for x in range (len(matrice)):
        print()
        for y in range(len(matrice[x])):
            print(matrice[x][y], end=" ")
    print()


def generationMine (matrice):
    for x in range (len(matrice)):
        for y in range (len(matrice[x])):
            if random.randint(1,20) == 1:
                matrice[x][y] = 9
    return matrice


def calculAdjacent (matrice):
    for x in range(len(matrice)):
        for y in range(len(matrice)):
            if matrice[x][y] == 9:
                for x2 in range (x-1, x+1):
                    for y2 in range (y-1, y+1):
                        if x2 >= 0 and y2 >= 0 and (x != x2 or y !=y2):
                            if matrice[x2][y2] != 9:
                                matrice[x2][y2] = matrice[x2][y2] + 1
    return matrice


def creationMatrice (tailleX, tailleY):
    matrice = []
    for x in range (tailleX):
        matrice.append([0])
        for y in range (tailleY):
            matrice[x].append(0)
    return matrice

afficherMatrice(creationMatrice(10,10))


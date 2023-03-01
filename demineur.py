import random


#9 = mine / chiffre inférieur a 9 = libre

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

def afficherMatriceJoueur (matriceChoix, demineur):
    return None


def generationMine (matrice):
    for x in range (len(matrice)):
        for y in range (len(matrice[x])):
            if random.randint(1,10) == 1:
                matrice[x][y] = 9
    return matrice


def calculAdjacent (matrice):
    for x in range(len(matrice)):
        for y in range(len(matrice[x])):
            if matrice[x][y] == 9:
                for x2 in range (x-1, x+2):
                    for y2 in range (y-1, y+2):
                        if ((x2 >= 0 and y2 >= 0) and (x != x2 or y !=y2) and (x2 < len(matrice) and y2 < len(matrice[x2])) ):
                            if matrice[x2][y2] != 9:
                                matrice[x2][y2] = matrice[x2][y2] + 1
    return matrice


def creationMatrice (tailleX, tailleY):
    matrice = []
    for x in range (tailleX):
        matrice.append([])
        for y in range (tailleY):
            matrice[x].append(0)
    matrice = generationMine(matrice)
    matrice = calculAdjacent(matrice)
    return matrice

def creationMatriceChoix(matrice):
    for x in range(len(matrice)):
        matrice.append([])
        for y in range(len(matrice[x])):
            matrice[x].append[0]
    return matrice


def selectionJoueur(matrice):
    print()
    x = input("Choisissez l'emplacement en abscice : ")
    print()
    y = input("Choisissez l'emplacement en ordonné : ")
    print()
    if x < len(matrice[y]) and y < len(matrice):
        coordonnees = (x, y)
    else:
        print("Les valeurs ne sont pas valide veuillez en entrer de nouvelles...")
        selectionJoueur(matrice)
    return coordonnees



def verificationVictoire(matrice):
    for y in range(len(matrice)):
        for x in range(len(matrice[y])):
            if matrice[y][x] != 9 or matrice[y][x] != 10:
                return False
    return True


demineur = creationMatrice(10, 10)


while verificationVictoire(demineur) == False:






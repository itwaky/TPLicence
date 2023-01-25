morpion = [[0,0,0],
           [0,0,0],
           [0,0,0]]

gagnant = [0,1]

def afficherMorpion(morpion):
    for ligne in range (len(morpion)):
        print(" ")
        for col in range(len(morpion[ligne])):
            if morpion[ligne][col] == 0:
                print(".", end=" ")
            elif morpion[ligne][col] == 1:
                print("O",end=" ")
            elif morpion[ligne][col] == 2:
                print("X",end=" ")
    print(" ")

def ajoutUtil(morpion, joueur ):
    if joueur == 0:
        print("Au tour des O...")
    else:
        print("Au tour des x...")
    y = int(input("Entrez votre choix en ordonné : "))
    x = int(input("Entrez votre choix en abscice : "))
    if morpion[y][x] == 1 or morpion[y][x] == 2:
        input("la case est déjà occuper veillez appuyer sur entrer pour recomencer.")
        ajoutUtil(morpion, joueur)
    else:
        if joueur == 0:
            morpion[y][x] = 1
        elif joueur == 1:
            morpion[y][x] = 2
        print(morpion)
        return morpion


victoire = False
i = 0
while victoire == False:
    if i%2 == 0:
        joueur = 0
    else :
        joueur = 1
    ajoutUtil(morpion, joueur)
    afficherMorpion(morpion)
    i += 1
    for y in range (len(morpion)):
        testLigne = morpion[y][0]
        testColonne = morpion[0][y]
        if testLigne != 0:
            if (morpion[y][0] == testLigne and morpion[y][1] == testLigne and morpion[y][2] == testLigne):
                if testLigne == 1:
                    print("Bravo aux O")
                else:
                    print("Bravo aux x")
                victoire = True
        if testColonne != 0:
            if (morpion[0][y] == testColonne and morpion[1][y] == testColonne and morpion[2][y] == testColonne):
                if testColonne == 1:
                    print("Bravo aux O")
                else:
                    print("Bravo aux x")
                victoire = True
    testDiagonale = morpion[1][1]
    if testDiagonale != 0:
        if (morpion[0][0] == testDiagonale and morpion[2][2] == testDiagonale or morpion[0][2] == testDiagonale and morpion[2][0] == testDiagonale):
            if testDiagonale == 1:
                print("Bravo aux O")
            else:
                print("Bravo aux x")
            victoire = True

morpion = [[0,0,0],
           [0,0,0],
           [0,0,0]]

#test

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
    y = int(input("Entrez votre choix en ordonné : "))
    x = int(input("Entrez votre choix en abscice : "))
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
        if (morpion[y][0] == 1 and morpion[y][1] == 1 and morpion[y][2] == 1):
            print("Bravo au joueur 0")
            victoire = True

import tkdraw.basic as graph
import Labyrinthe



laby = Labyrinthe.creer(11,15)
for ligne in laby:
    print(ligne)



def coord(lst, n):
    for y in range(len(lst)):
        for x in range(len(lst[y])):
            if lst[y][x] == n:
                return (y,x)
    return None


def entree(lst):
    return coord(lst, 2)


def sortie(lst):
    return coord(lst, 3)



print("entre :", entree(laby), " sortie : ", sortie(laby))



def taille_laby(lst):
    y2 = 0
    x2 = 0
    for y in range(len(lst)):
        y2 += 1
    for x in range(len(lst[y])):
        x2 +=1
    return (y2,x2)



print("taille : ", taille_laby(laby))

import tkdraw.basic as graph
import Labyrinthe, os



laby = Labyrinthe.creer(11,15)
for ligne in laby:
    print(ligne)

#---------------------------------1.2

def coord(lst, n):
    for y in range(len(lst)):
        for x in range(len(lst[y])):
            if lst[y][x] == n:
                return (y,x)
    return None



#------------------------------------------1.3

def entree(lst):
    return coord(lst, 2)


def sortie(lst):
    return coord(lst, 3)



#print("entre :", entree(laby), " sortie : ", sortie(laby))



#---------------------------------------------2.1


def taille_laby(lst):
    y2 = 0
    x2 = 0
    for y in range(len(lst)):
        y2 += 1
    for x in range(len(lst[y])):
        x2 +=1
    return (y2,x2)



#print("taille : ", taille_laby(laby))

DimensionsY = taille_laby(laby)[0]
DimensionsX = taille_laby(laby)[1]


#---------------------------------------2.3



def voisin_laby_fin(lgn,col,nb_lignes,nb_colonnes):
    coord = []
    coordNonTeste = [[lgn-1,col],[lgn+1,col],[lgn,col-1],[lgn ,col+1]]
    for i in range(4):
        if coordNonTeste[i][0] <= nb_lignes and coordNonTeste[i][0] >= 0 and coordNonTeste[i][1] <= nb_colonnes and coordNonTeste[i][1] >= 0:
            coord.append(tuple(coordNonTeste[i]))
    return coord


#print("cases voisines : ", voisin_laby_fin(1,1,DimensionsX,DimensionsY))



#----------------------------------------2.4 et 2.5



#def voisins_laby_acc(lgn,col,laby):
#    casesAcc = []
#    DimensionsY = taille_laby(laby)[0]
#    DimensionsX = taille_laby(laby)[1]
#    casesVoisines = voisin_laby_fin(lgn,col,DimensionsX,DimensionsY)
#    for i in range(4):
#        if laby[casesVoisines[i][0]][casesVoisines[i][1]]:
#            casesAcc = casesAcc + [casesVoisines[i]]
#    return casesAcc


def voisins_laby_acc(coord,laby):
    casesAcc = []
    DimensionsY = taille_laby(laby)[0]
    DimensionsX = taille_laby(laby)[1]
    casesVoisines = voisin_laby_fin(coord[0],coord[1],DimensionsX,DimensionsY)
    for i in range(len(casesVoisines)):
        if laby[casesVoisines[i][0]][casesVoisines[i][1]] == 1 or laby[casesVoisines[i][0]][casesVoisines[i][1]] == 3:
            casesAcc = casesAcc + [casesVoisines[i]]
    return casesAcc


#print("cases accessibles : ", voisins_laby_acc((3,4),laby))




#-------------------------------------------3.1 et 3.2


labySimple = [[0, 0, 0, 0, 0, 0, 0],
              [0, 1, 1, 1, 0, 3, 0],
              [0, 1, 0, 1, 0, 1, 0],
              [0, 2, 0, 1, 1, 1, 0],
              [0, 0, 0, 0, 0, 0, 0]]



def afficherParcour(listCel, laby):  #cette fonction n'est pas demander dans le tp
    for y in range(len(laby)):
        print()
        for x in range(len(laby[y])):
            cel = (y, x)
            if cel in listCel:
                print("*", end=" ")
            else:
                print(laby[y][x], end=" ")
    print()


def exploreVoie(depart, labySimple):
    trouver = False
    arrive = sortie(labySimple)
    case = depart
    lstCellules = [(case)]
    while trouver == False:
        caseAcc = voisins_laby_acc(case,labySimple)
        for i in range(len(caseAcc)):
            if caseAcc[i] not in lstCellules:
                case = caseAcc[i]
        if case in lstCellules:
            return []
        lstCellules += [(case)]
        afficherParcour(lstCellules, labySimple) #fait pas gaffe a ça c'est pas demander dans le tp c'est simplement pour afficher le chemin en cours c'était pour débuger
        if arrive == case:
            trouver = True
    return lstCellules



#print("Chemin pour sortir du labyrinthe : ", exploreVoie(entree(labySimple), labySimple))







#----------------------------------------------------------Pour aller plus loin




def estMinuscule(car):
    if car.islower():
        return True
    else:
        return False



def decalageCar(car, nb):
    return chr((((ord(car)+nb) - 96) % 26) + 96)



print(decalageCar('x', 10))


def decalageStr(str, nb):
    newStr = ''
    for i in range(len(str)):
        if estMinuscule(str[i]):
            newStr += decalageCar(str[i], nb)
        else:
            newStr += str[i]
    return newStr


print(decalageStr('Bonjour', 4))


def decalageFichier(intext, outtext, nb):
    print(intext)
    f = open(os.path.dirname(os.path.realpath(__file__)) + "/" + "in.txt", "r")
    contenu = f.read()
    f.close()
    newContenu = decalageStr(contenu)
    fw = open(os.path.dirname(os.path.realpath(__file__)) + "/" + "out.txt", "w")
    fw.write(newContenu)
    fw.close



decalageFichier('in.txt', 'out.txt', 4)

f = open(os.path.dirname(os.path.realpath(__file__)) + "/" + "in.txt", "r")
print(f.read())
print(os.path.dirname(os.path.realpath(__file__)) + "/" + "in.txt")
f.close()

    

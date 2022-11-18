import tkdraw.basic as graph
import Labyrinthe, random




#-------------------------Mission1---------------------Afficher le labyrinthe




laby = Labyrinthe.creer(9,9)


#laby = [[0, 0, 0, 0, 0, 0, 0],
#        [0, 1, 1, 1, 1, 3, 0],
#        [0, 1, 0, 1, 0, 0, 0],
#        [0, 2, 0, 1, 1, 1, 0],
#        [0, 0, 0, 0, 0, 0, 0]]



for ligne in laby:
	print(ligne)
def nb_lignes(lst):
	return len(lst)



def nb_colonnes(lst):
	return len(lst[0])



def taille_image(lst, taille):
	return (nb_lignes(lst)*taille,nb_colonnes(lst)*taille)

def rectangle_noir(haut, larg, y1, y2, x1, x2, couleur="black"):
	for y in range (haut):
		for x in range (larg):
			if (y1 <= y and y2 > y ) and (x1 <= x and x2 > x):
				graph.plot(y,x,couleur)

def dessine_labyrinthe(lst, taille):
	haut = 0
	larg = 0
	tailleImage = taille_image(lst, taille)
	graph.open_win(tailleImage[0],tailleImage[1] , 4)
	for i in range(len(lst)):
		haut = i * taille
		for j in range(len(lst[i])):
			larg = j * taille
			if lst[i][j]==0:
				rectangle_noir(tailleImage[0],tailleImage[1],haut,haut+taille,larg,larg+taille)
			elif lst[i][j]==2:
				rectangle_noir(tailleImage[0],tailleImage[1],haut,haut+taille,larg,larg+taille, couleur="blue")
			elif lst[i][j]==3:rectangle_noir(tailleImage[0],tailleImage[1],haut,haut+taille,larg,larg+taille, couleur="red")


	graph.wait()







#-----------------------------Mission2------------------Résolution du labyrinthe



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


def voisin_laby_fin(lgn,col,nb_lignes,nb_colonnes):
    coord = []
    coordNonTeste = [[lgn-1,col],[lgn+1,col],[lgn,col-1],[lgn ,col+1]]
    for i in range(4):
        if coordNonTeste[i][0] <= nb_lignes and coordNonTeste[i][0] >= 0 and coordNonTeste[i][1] <= nb_colonnes and coordNonTeste[i][1] >= 0:
            coord.append(tuple(coordNonTeste[i]))
    return coord

def taille_laby(lst):
    y2 = 0
    x2 = 0
    for y in range(len(lst)):
        y2 += 1
    for x in range(len(lst[y])):
        x2 +=1
    return (y2,x2)

def voisins_laby_acc(coord,laby):
    casesAcc = []
    DimensionsY = taille_laby(laby)[0]
    DimensionsX = taille_laby(laby)[1]
    casesVoisines = voisin_laby_fin(coord[0],coord[1],DimensionsX,DimensionsY)
    for i in range(len(casesVoisines)):
        if laby[casesVoisines[i][0]][casesVoisines[i][1]] == 1 or laby[casesVoisines[i][0]][casesVoisines[i][1]] == 3:
            casesAcc = casesAcc + [casesVoisines[i]]
    return casesAcc


def afficherParcour(listCel, laby):
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
    lstEmbranchement = []
    positionLst = 0
    positionEssaie = 0
    while trouver == False:
        input("Attente d'entré utilisateur...")
        caseAcc = voisins_laby_acc(case,labySimple)
        vraiCasesAcc = []
        for i in range(len(caseAcc)):
            if caseAcc[i] not in lstCellules:
                vraiCasesAcc.append(tuple(caseAcc[i]))
        print("Vrai case acc : ", vraiCasesAcc)
        if len(vraiCasesAcc) > 1:
            lstEmbranchement.append([positionLst, positionEssaie])
            print("Liste des embranchement", lstEmbranchement)
            case = vraiCasesAcc[positionEssaie]
        else:
            try: 
                case = vraiCasesAcc[positionEssaie]
            except IndexError:
                pass
        positionEssaie = 0
        if case in lstCellules:
            #reviens a l'enbranchement d'avant a partir d'une liste contenant toutes les positions des embranchement passé avec les choix précédent
            dernierEmbranchement = lstEmbranchement[-1]
            #supprime l'embranchement
            print("Retour à l'embranchement : ", dernierEmbranchement)
            lstCellules = lstCellules[0:dernierEmbranchement[0]+1]
            print(lstCellules)
            positionEssaie = dernierEmbranchement[1]+1
            positionLst = dernierEmbranchement[0]
            case = lstCellules[-1]
        else:
            print("Ajout de la case : ", case)
            lstCellules += [(case)]
            positionLst += 1
        print(lstCellules)
        afficherParcour(lstCellules, labySimple)
        if arrive == case:
            trouver = True
    return lstCellules

print(exploreVoie(entree(laby), laby))
dessine_labyrinthe(laby, 10)

import tkdraw.basic as graph
import random
import Labyrinthe

#-------------------------1


def doubler(lst):
	for i in range(len(lst)):
		lst[i] *= 2
	return lst

lst = [5,0,50,200]




#--------------------------------2


def listEntier():
	lst = []
	for i in range(1,100):
		if (i%2 == 0) or (i%3 == 0):
			lst += [i]
	return lst

print(listEntier())


#--------------------------3


def nvDoubler(lst):
	lst2 = []
	for i in range (len(lst)):
		lst2.insert(i, lst[i] * 2)
	return lst2

print(nvDoubler(lst))


#------------------------------4


def pixels_voisins(y, x):
	return [(y-1, x),(y+1, x),(y,x-1),(y,x+1)]


print(pixels_voisins(2,3))



#-------------------------------Première stratégie 2.1




def num_bande(y,x, largeur_bandes):
	return x//largeur_bandes

print("Numéro de bande : ", num_bande(5,34,10))




#-------------------------2.2



lst = [1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0]


def dessine_bandes1(lst, hauteur, largeur_bandes):
	graph.open_win(hauteur, largeur_bandes*len(lst), 4)
	depart = 0
	for i in range(len(lst)):
		depart = i * largeur_bandes
		arrive = depart + largeur_bandes
		if lst[i] == 0:
			for y in range(hauteur):
				for x in range(largeur_bandes*len(lst)):
					if x >= depart and x < arrive:
						graph.plot(y, x)
		else:
			print("valeur de la liste : ", lst[i])


	graph.wait()


#dessine_bandes1(lst, 50, 10)



#--------------------------deuxième stratégie----exo2

def rectangle_noir(haut, larg, y1, y2, x1, x2, couleur="black"):
	for y in range (haut):
		for x in range (larg):
			if (y1 <= y and y2 > y ) and (x1 <= x and x2 > x):
				graph.plot(y,x,couleur)



def rayures_verticales(haut,larg_bande, lst):
	graph.open_win(haut,larg_bande*len(lst),4)
	for j in range(len(lst)):
		depart = j * larg_bande
		arrive = depart +larg_bande
		if lst[j] == 0:
			rectangle_noir(haut,larg_bande*len(lst),0,haut,depart,arrive)
	graph.wait()



#rayures_verticales(50, 10, lst)


#---------------------la meilleur est la 2eme



lstlst = [[0, 1, 1, 0, 1, 1, 1, 0],
		 [1, 0, 0, 1, 1, 0, 0, 1],
		 [0, 1, 0, 1, 1, 0, 0, 1],
	 	 [0, 1, 0, 1, 0, 0, 1, 1],
		 [1, 0, 1, 0, 0, 1, 1, 0],
		 [1, 1, 0, 0, 0, 1, 0, 1]]


#--------------------------------------3.1


def nb_lignes(lst):
	return len(lst)



def nb_colonnes(lst):
	return len(lst[0])





def taille_image(lst, taille):
	return (nb_lignes(lst)*taille,nb_colonnes(lst)*taille)



print(taille_image(lstlst,10))



def damier(lst, taille):
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
	graph.wait()


#damier(lstlst, 10)



#---------------------------------------------4




laby = Labyrinthe.creer(11,15)
for ligne in laby:
	print(ligne)


#damier(laby, 10)


def entree(lst):
	entre = None
	for y in range(len(lst)):
		for x in range(len(lst[y])):
			if lst[y][x] == 2:
				entre = (y,x)
	return entre


def sortie(lst):
	sortie = None
	for y in range(len(lst)):
		for x in range(len(lst[y])):
			if lst[y][x] == 3:
				sortie = (y,x)
	return sortie


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


dessine_labyrinthe(laby, 10)

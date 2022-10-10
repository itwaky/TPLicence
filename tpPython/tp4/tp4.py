import tkdraw.basic as graph
import random

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


dessine_bandes1(lst, 50, 10)

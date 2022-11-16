import tkdraw.basic as graph
import Labyrinthe




#-------------------------Mission1---------------------Afficher le labyrinthe




laby = Labyrinthe.creer(17,17)
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


dessine_labyrinthe(laby, 10)





#-----------------------------Mission2------------------Résolution du labyrinthe

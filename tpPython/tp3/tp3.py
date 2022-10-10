import random
import tkdraw.basic as graph


#-------------------------sapin de noel---------------


def ligneSapin(nb):
	string = ""
	for i in range(nb-1):
		ran = random.random()
		if ran <= 0.2:
			string = string + "O"
		else:
			string = string + "*"
	return string 

def sapin(taille):
	sapin = ""
	ran = random.random()
	for i in range (1, taille):
		ran = random.random()
		if ran <= 0.2:
			print(" " * (taille - i) + ligneSapin(i) + "O" + ligneSapin(i))
		else:
			print(" " * (taille  - i) + ligneSapin(i) + "*" + ligneSapin(i))
	print(" " * (taille - 2) + "***")


#----------------------------------boucle while-----------------------

def myst():
	nb = random.randint(0,99)
	reussite = False
	while reussite == False:
		nbUtil = int(input("saisissez le nombre entre 0 et 99 : "))
		if nb < nbUtil:
			print("moin")
		elif nb > nbUtil:
			print("plus")
		else:
			print("bravo vous avez trouve le nombre qui est égal a : " , nb)
			reussite = True


#------------------------------projet labyrinthe: dessiner images--------------------

graph.open_win(400, 600 , 2)
def bande_noire_gauche(haut,larg,larg_bande):
	for y in range(haut):
		for x in range(larg):
			if x < larg_bande:
				graph.plot(y,x)






def rectangle_noir(haut, larg, y1, y2, x1, x2):
	for y in range (haut):
		for x in range (larg):
			if (y1 <= y and y2 > y ) and (x1 <= x and x2 > x):
				graph.plot(y,x)



def rectangle_blanc(haut, larg, y1, y2, x1, x2):
	for y in range (haut):
		for x in range (larg):
			if (y1 <= y and y2 > y ) and (x1 <= x and x2 > x):
				ok = ' '
			else:
				graph.plot(y,x)


				
#-------------------------4




def numBande(x, larg_bande):
	reussi = False
	i = 0
	position = larg_bande
	numero = 0
	while reussi == False:
		if position>x:
			reussi = True
			numero = i
		else:
			i = i + 1
			position = position + larg_bande
	return numero

#-----------5

# elle doit être impair




#----------------------6

		
def rayures_verticales(haut,larg,larg_bande):
	if larg%larg_bande != 0:
		print("Les valeur de longueurs sont incorectes")
	else:
		depart = larg_bande
		for i in range ((larg//larg_bande)//2):
			rectangle_noir(haut,larg,0,haut,depart,depart+larg_bande)
			depart += larg_bande*2




#--------------------------------7




def numCarre(x,y,cote):
	reussiHaut = False
	reussiLarg = False
	i = 0
	positionHaut = cote
	positionLarg = cote
	nv = 0
	nh = 0
	while reussiLarg == False:
		if positionLarg>x:
			reussiLarg = True
			nh = i
		else:
			i += 1
			positionLarg += cote
	
	a = 0
	while reussiHaut == False:
		if positionHaut>y:
			reussiHaut = True
			nv = a
		else:
			a += 1
			positionHaut += cote
	
	print("nh = ", nh)
	print("nv = ", nv)


numCarre(140, 250, 50)

		

#-------------------------8

#------------Il faut que nh et nv soit impair



#-------------------------------9



def damier(haut, larg, cote):
	if larg%cote or haut%cote != 0:
		print("les longueur ne sont pas bonnes")
	else:
		departHaut = 0
		for i in range (haut//cote):
			if i%2 == 0:
				departLarg = cote
			else:
				departLarg = 0
			for i in range ((larg//cote)//2):
				rectangle_noir(haut,larg,departHaut,departHaut+cote,departLarg,departLarg+cote)
				departLarg += cote*2
			departHaut += cote






#--------------------------10




def rectangleMulti(haut, larg, y1, y2, x1, x2):
	couleurs = ["black", "white", "red", "green", "blue", "yellow", "cyan", "magenta", "orange", "darkgrey"]
	choice = random.randint(0,9)

	for y in range (haut):
		for x in range (larg):
			if (y1 <= y and y2 > y ) and (x1 <= x and x2 > x):
				graph.plot(y,x,couleurs[choice])	




def damierMulti(haut, larg, cote):
	if larg%cote or haut%cote != 0:
		print("les longueur ne sont pas bonnes")
	else:
		departHaut = 0
		for i in range (haut//cote):
			if i%2 == 0:
				departLarg = cote
			else:
				departLarg = 0
			for i in range ((larg//cote)//2):
				rectangleMulti(haut,larg,departHaut,departHaut+cote,departLarg,departLarg+cote)
				departLarg += cote*2
			departHaut += cote



damierMulti(400, 600, 50)


	
graph.wait()




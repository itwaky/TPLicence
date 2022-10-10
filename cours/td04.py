import random


#-----------------td4exo1----------

def intensite(c):
	intens = (c[0] + c[1] + c[2]) / 3
	return intens
	

print(intensite((255,255,255)))


#---------------------td4exo2----------------------


def sombre(c):
	res = (c[0]//2, c[1]//2, c[2]//2)
	return res

print(sombre((20,20,20)))

#-----------------td4exo3-----------------------


def somme(c1, c2):
	res = (c1[0]+c2[0], c1[1] + c2[1])
	return res
	
print(somme((2,2),(2,2)))


#------------------------td4--2)exo1----------------------


def multiplier(lst):
	for i in range (len(lst)):
		lst[i] = lst[i] * lst[i]
	return lst
	
print(multiplier([2,3,4]))

#------------------------td4----2)exo2&exo3-------------


def doubler(lst):
	lst2 = []
	for i in range (len(lst)):
		lst2 += [lst[i] * 2]
	return lst2

print(doubler([2,3,4]))


#-----------------td4-----2)exo4-----------


def strToIntLst(lst):
	for i in range(len(lst)):
		lst[i] = int(lst[i])
	return lst

print(strToIntLst(["3", "-4", "4"]))


#-------------------td4-----3)exo1--------------


def contientUn3(lst):
	here = False
	for i in range(len(lst)):
		if lst[i] == 3:
			here = True 
	return here
	
	
print(contientUn3([4,5,4]))



#------------------------td4------3)exo2-----------


def comptePairs(lst):
	lstPair = []
	for i in range (len(lst)):
		if lst[i]%2==0:
			lstPair = lstPair + [lst[i]]
	return lstPair

print(comptePairs([3,4,8,9]))



#---------------------td4---------3)exo3---------------







#td4 exo3.3


def minimum(lst):
	if len(lst) == 0:
		return None
	minimum = lst[0]
	for v in lst:
		if v<minimum:
			minimum = v
	return minimum
	
print(minimum([4,2,9]))


#exo3.4


def indiceDernier(lst,n):
	indice = None
	if len(lst) == 0:
		return None
	for i in range(len(lst)):
		if lst[i]==n:
			indice = i
	return indice


lst = [2,3,8,5,3]

print(indiceDernier(lst, 8))


#exo3.5


def estCroissante(lst):
	croissant = True
	if len(lst) < 2:
		return None
	for i in range(1,len(lst)):
		if lst[i-1] >= lst[i]:
			croissant = False
			
	return croissant
	

print(estCroissante([2,8,19,20]))


#exo4.1

def cinqALaChaine(nb):
	lst = []
	for i in range (nb):
		lst.insert(i, nb)
	return lst
	
print(cinqALaChaine(3))


#exo4.2

def listAlea(n):
	lst = []
	for i in range(n):
		hasard = random.random()
		lst.insert(i, hasard)
	return lst
	
print(listAlea(10))
		



#exo4.3

#compte = 0
#while True:
#	if int(random.random()) == 1:
#		print("trouver ", compte)
#		break
#	compte += 1
#	if compte%100000 == 0:
#		print("\r", compte, end="")


def estPremier(x):
	if x % 2 == 0:
		if x == 2:
			return True
		return False
	d = 3
	while d * d <= x:
		if x % d == 0:
			return False
		d += 2
	return True

def liste_premier(n):
	if n <= 0:
		return []
	nouv = []
	x= 2
	while n > 0:
		if estPremier(x):
			nouv += [x]
			n-= 1
		x +=2
	return nouv



#exo4.4

def supprimeN(lst, x):
	lst2 = []
	for i in range (len(lst)):
		if x != i:
			lst2.insert(i, lst[i])
	return lst2

print(supprimeN([3,4,5], 1))




#exo5.1


grille = [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]

def hauteur(grille):
	"""retourne la hauteur de la grille"""
	return len(grille)

print(hauteur(grille))
 

def largeur(grille):
	"""retourne la largeur de la grille"""
	return len(grille[0])

print(largeur(grille))
	


#exo5.2


def modifValeurs(grille):
	for i in range(len(grille)):
		for j in range(len(grille[0])):
			grille[i][j] = i + 1
	return grille
	
print(modifValeurs(grille))


#exo5.3

def cree(hauteur, largeur):
	nouvelle = []
	for lig in range(hauteur):
		lst = [lig + 1] *largeur
		nouvelle += [lst]
	return nouvelle

		
print(cree(8,5))



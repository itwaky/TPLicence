
#exo1.1:



def est_minuscule(c):
	return 'a' <= c <= 'z'
	
	
def decale_char(c,nombre):
	"""retourne le cractère c de nombre décalé"""
	nom_lettre = ord(c) - ord('a')
	nouv_lettre = (nom_lettre+nombre)%26
	return chr(nouv_lettre + ord('a'))

print(decale_char('z', 12))



#exo1.2



def decalageStr(c, nombre):
	nouv = ""
	for i in range(len(c)):
		if est_minuscule(c):
			nouv += decale_char(c[i], nombre)
		else:
			nouv += c
	return nouv
	

print(decalageStr("eros", 4))



#exo1.3




def codage(s):
	return decalageStr(s, 5)
	



#exo2.1



#4


#exo2.2


def affiche_voisin_laby_inf(lig, col):
	"""affiche les coordonée des case voisines de la case (lig, col)"""
	print(lig-1, col)
	print(lig+1, col)
	print(lig, col-1)
	print(lig, col+1)
	
	



#exo2.3



def voisin_laby_inf(lig,col):
	return [(lig-1, col),(lig+1, col),(lig, col-1),(lig,col+1)]




def est_dans(lig, col, hauteur, largeur):
	if lig<0:
		return False
	if lig > hauteur:
		return False
	if col<0:
		return False
	if col>largeur:
		return False
	return True
	
	



#exo2.6

#2,3,4 voisins 



















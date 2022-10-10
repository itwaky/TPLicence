import tkdraw.basic as graph


graph.open_win(120, 160 , 4)
def ligne_horiz(y, larg):
	for x in range(larg):
		graph.plot(y, x)

def segment_horiz(y, x1, x2):
	for x in range(x2):
		if x>=x1:
			graph.plot(y, x)



def rectangle(y1, y2, x1, x2):
	for x in range(y2):
		if x>=y1:
			segment_horiz(x, x1, x2)
			
def rayures_vertic(departColonne,haut, larg, larg_bande,boolDepart):
	if larg%larg_bande== 0:
		repetition = larg//larg_bande
		print("repetition = ", repetition)
		if boolDepart == False:
			depart = larg_bande
			arrive = depart + larg_bande
		else:
			depart = 0
			arrive = depart + larg_bande
		haut = haut 
		marge = departColonne
		
		print("depart = ", depart)
		print("arrive = ", arrive)
		for i in range(repetition//2):
			rectangle(marge, haut, depart, arrive)
			depart = depart + larg_bande*2
			arrive = arrive + larg_bande*2
			print("depart = ", depart)
			print("arrive = ", arrive)
			
	else:
		print("largeur non valide")
		

def damier (haut, larg, cote):
	if (larg%cote == 0) and (haut%cote == 0):
		print("valeurs valide")
		nbLigne = larg//cote
		nbColonne = haut//cote
		departLarg = False
		departHaut = 0
		
		for i in range (nbColonne):
			rayures_vertic(departHaut, departHaut + cote , larg, cote, departLarg)
			departHaut = departHaut + cote
			if departLarg == False :
				departLarg = True
			else:
				departLarg = False
			
		
	else:
		print("valeurs non valide")		
			
def sapin(haut, larg):
	centreLigne = larg//2
	print(centreLigne)
	graph.plot(0, centreLigne)
	for i in range (haut):
		segment_horiz(i,centreLigne-i, centreLigne)
		graph.plot(i,centreLigne)
		segment_horiz(i, centreLigne, centreLigne)
		
	

#rayures_vertic(20,40,160,20, False)
#damier(120,160,20)	
sapin(120,160)		 
graph.wait()

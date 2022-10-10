def aLaChaine (n):
	A = ""
	for i in range (n):
		A = A + "A"
	return A
	
def aLaChaine2 (esp, n):
	A = str("")
	espace = str("")
	for i in range (esp):
		espace = espace + " "
	for i in range (n):
		A = A + "A"
	return espace + A
	
def colonne (n):
	for i in range (10):
		print(aLaChaine(n))
		
def diagonale1(n):
	for i in range (1, n + 1):
		print(aLaChaine(i))
		
def diagonale2(n):
	for i in range (1, n + 1):
		print(aLaChaine2(n-i, i))
		
		
def sapin(n):
	chaine = ""
	print(" "*n+"A")
	for i in range (1, n-1):
		chaine = aLaChaine2(n-i, i) + "A" + aLaChaine(i)
		print(chaine)
	print((n-1)*" "+"AAA")
 	
print(aLaChaine(10))
sapin(10)

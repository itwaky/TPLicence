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





		

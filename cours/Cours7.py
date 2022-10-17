#--------------------Cours----

def fact(n):
    print("slt")
    if n==0:
        return 1
    else:
        return n * fact(n-1)

#print(fact(5))

#-----7.5


#2)   5

#3)    jusqu'au max récursion

#4) 0, max, return 3 * n






#-------------------7.6

#-----------1

def puissance(x,y):
    if y == 0 :
        return 1
    else :
        return x * puissance(x, y-1)

print(puissance(2,5))


#----------------------2


def multiplication(x,y):
    if y == 0:
        return 0
    else:
        return x + multiplication(x, y-1)


print(multiplication(10, 0))



#-----------------3


def pgcd(a,b):
    if b==0:
        return a
    return pgcd(b,a%b)



#---------------4



def Cnp(n,p):
    if p == 0 or p == n:
        return 1
    else:
        return Cnp(n-1,p) + Cnp(n-1,p-1)

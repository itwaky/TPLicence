import random



#--------------------------------1


def suiteGeom(n,q,u0):
    if n == 0:
        return u0
    else:
        return suiteGeom(n-1,q, u0) * q


print(suiteGeom(4,3,4))


#---------------------------------2

def sommeUnSurNCarre(n):
    if n == 0:
        return 0
    else:
        return sommeUnSurNCarre(n-1) + 1/(n * n)


print(sommeUnSurNCarre(900))



#--------------------------------3

def listeAuHasard(n,valmax):
    if n == 0:
        return []
    else:
        return [random.randint(0,valmax)] + listeAuHasard(n-1,valmax)



print(listeAuHasard(10,10))



#---------------------------------------4


lst = [0,1,2,3,4,5,6,7,8,9,10]

def renverser(lst):
    if lst == []:
        return []
    else:
        return lst[-1:] + renverser(lst[:-1])


print(renverser([0,1,2,3,4,5,6,7]))

#----------------------------------5



print(lst[:1])
print("je m'apelle eros"[1:-1])
print("je m'apelle eros"[:1])

def chemin(lst, x):
    if lst == []:
        return []
    elif x >= lst[0]:
        return lst[:1] + chemin(lst[1:],x)
    else :
        return chemin(lst[1:],x)


print(chemin(lst, 5))



#---------------------------------------6

def supprEspaceApost(txt):
    if len(txt) == 0:
        return ""
    elif txt[0] == " " or txt[0] == "'":
        return supprEspaceApost(txt[1:])
    else:
        return txt[:1] + supprEspaceApost(txt[1:])


print(supprEspaceApost("je m'appelle eros"))



#---------------------------------------7


def estPalindrome(txt):
    txt = supprEspaceApost(txt)
    if len(txt) <= 1:
        return True
    elif txt[:1] == txt[-1:]:
        return estPalindrome(txt[1:-1])
    else:
        return False


print(estPalindrome("kay a k"))



#--------------------------------------8

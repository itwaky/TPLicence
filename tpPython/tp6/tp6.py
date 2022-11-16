import random
import os
import sys
sys.setrecursionlimit(10000000)

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



print(listeAuHasard(100,100))



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



def dichotomieCarre(bmin, bmax, epsilon):
    if round((bmin**2)-2, len(str(int(round(10/epsilon, 1))))-2) == 0:
        return round(bmin, len(str(int(round(10/epsilon, 1))))-2)
    else:
        borne = (bmin+bmax)/2
        if ((borne**2)-2) > 0:
            return dichotomieCarre(bmin, borne, epsilon)
        else:
            return dichotomieCarre(borne, bmax, epsilon)

print("resultat : ", dichotomieCarre(1,2,0.000000001))



#----------------------------------------9
def dichotomieCarre(a, b , c, bmin, bmax, epsilon):
    if round(((a)*(bmin**2))+((b)*bmin)+(c), len(str(int(round(10/epsilon, 1))))-2) == 0:
        return round(bmin, len(str(int(round(10/epsilon, 1))))-2)
    else:
        borne = (bmin+bmax)/2
        if ((a)*(borne**2))+((b)*borne)+(c) > 0:
            return dichotomieCarre(a, b, c, bmin, borne, epsilon)
        else:
            return dichotomieCarre(a, b, c, borne, bmax, epsilon)

print(dichotomieCarre(2,5,-1,0.1,1,0.00001))

#---------------------------------2.1


#listdir     lister un répertoire
#exists    vérifie l'existance du fichier ou dossier
#isdir   vérifie si est un dossier
#isfile  vérifier si est un fichier


#-------------------------------------2.2





def estUnRepertoire(path):
    return os.path.isdir(path)




def listedir(path):
    if estUnRepertoire(path) == False:
        return [path]
    else:
        return os.listdir(path)


print(listedir("/home/itwaky"))
print(listedir("/home/itwaky/Documents/TPLicense/tpPython/morpion.py"))



#-------------------------------------2.3



#def rechercheDansArborescence(path, file, lst=[]):
#    if file in listedir(path):
#        return listedir(path + file)
#    elif len(lst) == 0:
#        return rechercheDansArborescence(path, file, listedir(path))
#    elif estUnRepertoire(path + "/" + lst[0]) == True:
#        return rechercheDansArborescence(path + "/" + lst[0], file, lst[1:])
#    else:
#        return rechercheDansArborescence(path, file, lst[1:])



#print(rechercheDansArborescence("/home/itwaky/Documents/TPLicense", "tp6.py"))




#------------------------------------------3 Pour aller plus loin---------


def troisiemeTour(dep, dest):
    tourListe = (0,1,2)
    tour = None
    for i in range (len(tourListe)):
        if tourListe[i] != dep and tourListe[i] != dest:
            tour = i
    return tour

def afficheMouvement(dep, dest):
    if dep < dest:
        return "T" + str(dep) + " -> " + "T" + str(dest)
    else:
        return "T" + str(dest) + " <- " + "T" + str(dep)


def mouvement(hanoi, dep, dest):
    disque = hanoi[dep][0]
    del hanoi[dep][0]
    hanoi[dest].insert(0, disque)
    print(afficheMouvement(dep, dest))
    print(hanoi)
    return hanoi

def mouvementEstValide(hanoi, dep, dest):
    if dep in (0, 1, 2) and dest in (0, 1, 2):
        pass
    else:
        return False
    if dep != dest:
        pass
    else:
        return False
    try:
        hanoi[dep][0]
        try:
            hanoi[dest][0]
            if hanoi[dep][0] < hanoi[dest][0]:
                pass
            else:
                return False
        except IndexError:
            pass
    except IndexError:
        return False
    return True



hanoi=[[1,2,3],[],[]]
print(mouvementEstValide(hanoi,0,2))







def mouvementMultiDisque(hanoi, dep, dest, nbDisque):
    if nbDisque == 0:
        return hanoi
    else:
        if mouvementEstValide(hanoi, dep, dest):
            hanoi = mouvement(hanoi, dep, dest)
            return mouvementMultiDisque(hanoi, dep, dest, nbDisque-1)
        else:
            return mouvementMultiDisque(hanoi, dep, dest, nbDisque-1)


print(mouvementMultiDisque(hanoi, 0, 2, 2))

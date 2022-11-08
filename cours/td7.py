liste = [3,7,2,0,10,22,3]


def indice_min(lst):
    x = lst[0]
    for i in range(len(lst)):
        if lst[i] < x:
            x = i
    return x


print(indice_min(liste))



def tri_selection(lst):
    for i in range(len(lst)):
        min = indice_min(lst, i)
        lst[i], lst[min] = lst[min], lst[i]
    return lst






def uneBulle(lst):
    r = False
    for i in range(len(lst)-1):
        if lst[i] > lst[i+1]:
            lst[i], lst[i+1] = lst[i+1] , lst[i]
            r = True

    return r


def tri_bulle(lst):
    while uneBulle(lst):
        pass
    return lst


print(tri_bulle(liste))

lstTrier = tri_bulle(liste)

def insere_trie(lst, x):
    binf = 0
    bsup = len(lst)
    while binf != bsup:
        milieu = (binf+bsup)//2
        if x>=lst[milieu]:
            binf = milieu + 1
        else:
            bsup = milieu
    lst[binf:binf] = [x]
    return lst


print(insere_trie(liste, 10))



def tri_insertion(lst):
    nouv = []
    for x in lst:
        insere_trie(nouv,x)
    return nouv

print(tri_insertion(lstTrier))

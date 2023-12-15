-- --------------------------------1.liste polymorphe-----------------------------



-- 1

nth l1 n = case l1 of {
    t:r ->  if n == 0
                then t
            else
                nth r (n-1);
    [] -> 0
}


-- 2


rev l = case l of {
    [] -> [];
    h:t -> rev t ++ [h]
}





-- 3

sans_doublon l = case l of{
    [] -> [];
    t:r ->  if t == head r
                then sans_doublon r
            else
                sans_doublon r ++ [r]
}



-- 4


estVide l = case l of {
    [] -> True;
    h:t -> False
}

dernier_elem l = case l of {
    [] -> -1;
    h:t ->  if estVide t
                then h
            else
                dernier_elem t
} 










-- ------------------------------- exercice2


data Couleur =
            Coeur
            | Carreau
            | Pique
            | Trefle deriving Eq
data Carte = As Couleur
            | Roi Couleur
            | Dame Couleur
            | Valet Couleur
            | Petite Integer Couleur







-------3

compte_as p = case p of{
    [] -> 0;
    (AS _):cas -> compte_as cas + 1;
    _:cas -> compte_as cas
}

carre_as c = (compte_as c == 4)



--------4

valeur_de ca = case ca of{
    AS _ -> 14;
    Roi _ -> 13;
    Dame _ -> 12;
    Valet _ -> 11;
    Petite n _ -> n
}

compte rang p = case p of{
    [] -> 0;
    ca:cas ->   if rang_de ca == rang
                    then 1+compte rang cas
                else
                    compte rang cas
}



carre_aux p m = 
    if m < 2 then
        False
    else
        if compte m p == 4
            then True
        else
            carre_aux p (m-1)


ou_l l = case l of{ -- equivent a fold prédéfini
    [] -> False;
    h:t ->  if h
                then True
            else
                au_l t
}

carre p = carre_aux p 14

carre2 p = ou_l(map (\m -> compte m p) [2..14]) -- bizarre

-- --------------------------------------exercice3-----------------------------------


------------1

data Expr_arith = 
     Notation Integer
    |Addition Expr_arith Expr_arith
    |Multiplication Expr_arith Expr_arith
    deriving show -- Pour afficher



--------------2


-- Multiplication(Notation 2)(addition (Notation 1)(Notation 3)) <=> 2x(1+3)


-------------3



eval exp = case exp of{
    Notation exp1 -> exp1;
    Addition exp1 exp2 -> (eval exp1) + (eval exp2);
    Multiplication exp1 exp2 -> (eval exp1) * (eval exp2)
}

-- eval (Multiplication(Notation 2)(addition (Notation 1)(Notation 3))) ====> 8




-- ---------------------------------Exercice4--------------------------------------------

----------------------1


data Arbre a = 
    Vide
    |Noeud (Arbre a) a (Arbre a)
    deriving show

------------------------2

-- Noeud(Noeud Vide 3 (Noeud Vide 2 Vide)) 1 (Noeud Vide 4 Vide)  <=> arbre de l'enonce



------------------------3



recherche a v = case a of{
    Vide -> False;
    Noeud g w d -> (w == v) || (recherche g v) || (recherche d v)
}

rechercheIf a v = case a of{
    Vide -> False;
    Noeud g w d ->  if w==v
                        then Ture
                    else
                        if (recherche g v)
                            then True
                        else
                            recherche f v
}

taille a = case a of{
    Vide -> 0;
    Noeud g _ d -> 1 + (taille g) + (taille d)
}


parcours a = case a of{
    Vide -> [];
    Noeud g w d -> W:((parcours g)++(parcours d))
}

cree_equilibre n = 
    if n == 0
        then Vide
    else if n `mod` 2 == 1
        then Noeud (cree_equilibre ((n-1)`div`2)) 0 (cree_equilibre ((n-1)`div`2))
    else
        then Noeud (cree_equilibre n`div`2) 0 (cree_equilibre (n-1)`div`2)





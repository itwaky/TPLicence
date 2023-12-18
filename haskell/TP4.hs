

-- -----------------------Jeux de cartes--------------------


-- ----------------------1


data Couleur =
    Coeur
    |Pique
    |Carreau
    |Trefle
    deriving (Eq,Ord,Show)


data Carte = 
    As Couleur
    |Roi Couleur
    |Dame Couleur
    |Valet Couleur
    |Petite Integer Couleur
    deriving (Eq,Ord,Show)



-- ---------------------2


couleur_de ca = case ca of{
    As couleur -> couleur;
    Roi couleur -> couleur;
    Dame couleur -> couleur;
    Valet couleur -> couleur;
    Petite _ couleur -> couleur
}



-- ----------------------3


data Paquet_de_cartes= 
    Derniere Carte
    |Dessus Carte Paquet_de_cartes
    deriving (Eq,Ord,Show)



-- Dessus (Petite 10 Carreau) (Dessus(Roi Trefle) (Derniere (As Coeur)))


-- ------------------4


est_dans_paquet paquet ca = case paquet of{
    Derniere cart ->    if cart == ca
                            then True
                        else False ;
    Dessus cart r->      if cart == ca
                            then True
                        else
                            est_dans_paquet r ca
}


-- -------------------5

compte_as paquet = case paquet of {
    Derniere (As _) -> 1;
    Dessus (As _) r -> 1 + compte_as r;
    Dessus _ r -> compte_as r
}


quatre_as paquet = (compte_as paquet) == 4 

-- Dessus(As Coeur)(Dessus (As Pique)(Dessus (As Trefle)(Derniere (As Carreau)))) -> True

-- Dessus (Petite 10 Carreau) (Dessus(Roi Trefle) (Derniere (As Coeur))) -> False



-- -----------------6


-- -----------------------pas réussi

ordre_color c =
    if couleur_de c == Coeur
        then 4
    else if couleur_de c == Carreau
        then 3
    else if couleur_de c == Pique
        then 2
    else 
        1

insere_paquet paquet c = case paquet of{
    Derniere ca ->  if (ordre_color ca)>(ordre_color c)
                        then Dessus(c)(Derniere ca)
                    else
                        Dessus(ca)(Derniere c);
    Dessus ca r ->  if (ordre_color ca)>(ordre_color c)
                        then Dessus(ca)(insere_paquet r c)
                    else
                        Dessus(c)(Dessus(ca)(r))
}

-- insere_paquet (Dessus(As Trefle)(Dessus (As Pique)(Dessus (As Carreau)(Derniere (As Coeur))))) (Roi Carreau)




-- -----------------------------Arbres binaire----------------

-----1

data Tree a = Vide 
            | Noeud (Tree a) a (Tree a)
            deriving(Eq,Ord,Show)



--------2

-- Noeud (Noeud Vide 3 (Noeud Vide 2 Vide)) 1 (Noeud Vide 4 Vide)





---------3

nb_feuilles arbre = case arbre of{
    Noeud Vide _ Vide -> 1;
    Noeud g _ d -> (nb_feuilles g) + (nb_feuilles d);
    _ -> 0
}


--------4


nb_noeuds arbre = case arbre of{
    Noeud g _ d -> (nb_noeuds g) + 1 + (nb_noeuds d);
    _ -> 0;
}


-------5

hauteur arbre = case arbre of{
    Noeud g _ d ->  let gauche = (hauteur g) + 1 in let droite = (hauteur d) + 1 in 
                        if gauche > droite
                            then gauche
                        else
                            droite;
    _ -> 0 
}


------6

max_tree arbre = case arbre of{
    Noeud g val d -> max (max val (max_tree g)) (max val (max_tree d));
    _ -> 0;
}


------7



miroir arbre = case arbre of{ -- comprends pas pourquoi ça ne fonctionne pas 
    Noeud g val d -> Noeud (miroir d) val (miroir g);
    Vide -> Vide
}






--------------------------------Arbres binaire de recherche-------------------------



------------1


-- (Noeud (Noeud (Noeud Vide 1 Vide) 3 (Noeud (Noeud Vide 4 Vide) 6 (Noeud Vide 7 Vide))) 8 (Noeud Vide 10 (Noeud (Noeud Vide 13 Vide) 14 Vide)))


-----------2



mem arbre x = case arbre of{
    Noeud g val d ->    if val == x
                            then True
                        else if x < val
                            then mem g x
                        else
                            mem d x;
    _ -> False
}


-----------3


add arbre x = case arbre of{
    Noeud g val d ->    if x > val
                            then Noeud g val (add d x)
                        else
                            Noeud (add g x) val d;
    Vide -> Noeud Vide x Vide
}



----------4

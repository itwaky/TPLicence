
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




---------1

plusieur_fois elem n =  if n == 0
                            then []
                        else
                            [elem] ++ (plusieur_fois elem (n-1))




---------2


myMap f l = case l of{
    [] -> [];
    h:t ->  [f h] ++ myMap f t
}



----------3


-- (t -> a) -> [t] -> [a]


-----------4

-- \x -> \y -> [x]





--------------5


data Couleur = Noir | Blanc

data Image = Mono Couleur
            | Compos Image Image Image Image
            deriving Show



-- (Compos (Mono Blanc) (Mono Noir) (Mono Blanc) (Compos (Mono Noir) (Mono Noir) (Mono Noir) (Mono Blanc)))



--------------6

ligne q n i = case q of {
    Mono c -> plusieur_fois c n;
    Compos q1 q2 q3 q4 ->   let n2 = n `div` 2 in
                            let i2 = i `mod` n2 in
                                if i>=n2 
                                    then ligne q3 n2 i2 ++ ligne q2 n2 i2
                                else 
                                    ligne q4 n2 i2 ++ ligne q1 n2 i2
}



-------------7


inverse_couleur q = case q of{
    Mono Blanc -> Mono Noir;
    Mono Noir -> Mono Blanc;
    Compos a1 a2 a3 a4 ->   Compos (inverse_couleur a1)(inverse_couleur a2)(inverse_couleur a3)(inverse_couleur a4)
}


masque qm q = case qm of{
    Mono Noir -> inverse_couleur q;
    Mono Blanc -> q
    Compos a1 a2 a3 a4 -> case q of{
        Mono Noir -> Compos (masque a1 Noir)(masque a2 Noir)(masque a3 Noir)(masque a4 Noir);
        Mono Blanc -> Compos (masque a1 Blanc)(masque a2 Blanc)(masque a3 Blanc)(masque a4 Blanc);
        Compos b1 b2 b3 b4 -> Compos (masque a1 b1)(masque a2 b2)(masque a3 b3)(masque a4 b4)
    }
}


-----------8

nb_groupes l = case l of {
    [] -> 0;
    [c1] -> 0;
    [c1,c2] -> 0;
    [c1,c2,c3] -> 0;
    [c1,c2,c3,c4] -> 0;
    c1:c2:c3:c4:c5:r -> let n = nb_groupes (c2:c3:c4:c5:r) in
        if c1==c2 && c2==c3 && c3==c4 && c4==c5 then 1+n else n
}
score_lisibilite_aux q n i =
        if i==n 
            then 0 
        else 
            score_lisibilite_aux q n (i+1) + nb_groupes (ligne q n i)
        
    score_lisibilite q n = score_lisibilite_aux q n 0
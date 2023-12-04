

-- ---------------------------exercice1------------------


longueur a = case a of {
    [] -> 0;
    _:r -> 1+longueur(r);
}


tete a = case a of{
    a:_ -> a;
}

reste a = case a of {
    _:a -> a;
}


nieme liste n = 
    if n == 0
        then tete liste
    else
        nieme (reste liste) (n-1)



inverse liste = case liste of {
    [] -> [];
    t:r -> inverse r ++ [t];
}



concatene l1 l2 = case l1 of {
    [] -> l2;
    t:r -> t:concatene r l2;
}



-- a revoir
aplatir l = case l of {
    [] -> [];
    t:r -> t ++ aplatir r
}



-- ---------------------------exercice2---------------------

-- deux façon de faire app 
app e x=
    if head e == x
        then True
    else if length e == 1
        then False
    else
        app (tail e) x



app2 e x = case e of {
    t:r ->  if t == x
                then True
            else
                app2 r x;
    [] -> False
}


-- card

card l = case l of{
    [] -> 0;
    _:r -> 1 + card r;
}
 

-- inclus

inclus l1 l2 =
    if length l1 == 1
        then
            if app l2 (head l1)
                then True
            else
                False 
    else
        if app l2 (head l1)
            then inclus (tail l1) l2
        else
            False

-- union

union l1 l2 = case l1 of{
    [] -> l2;
    t:r -> t:union r l2;
}


-- intersection


intersection l1 l2 = case l1 of {
    [] -> [];
    t:r ->  if app l2 t
                then t:intersection r l2
            else
                intersection r l2;
}


-- difference

difference l1 l2 = case l1 of {
    [] -> [];
    t:r ->  if app l2 t
                then difference r l2
            else
                t:difference r l2;
}

-- egal

egal l1 l2 =
    if length l1 == length l2 && inclus l1 l2
        then True
    else
        False


-- --------------------------------------exercice3-----------------------------------------------

sous_liste l = case l of {
    [] -> [[]];
    t:r -> let p = sous_liste r in
                p ++ (map (\l -> t:l) p)
}



-- -------------------------------------exercice4---------------------------------------------


place e l = case l of {
    [] -> [[e]];
    t:r -> let p = place e r in (e:l):map(\x -> t:x) p
}


permut l = case l of {
    [] -> [[]];
    t:r -> aplatir(map (place t) (permut r))
}

-- [1,2] -> [[1,2],[2,1]]




-- ----------------------------------exercice5----------------------------


-- ---------------------------------exercice6--------------------------


-- c

-- void hanoi(int n, int depart, int inter, int arrive ){
--     if (n == 1){
--         printf("Deplacer de la tour %d a la tour %d\n", depart,arrive);
--     }else{
--         hanoi(n-1, depart, arrive,inter);
--         printf("Deplacer de la tour %d a la tour %d\n", depart, arrive);
--         hanoi(n-1,inter,depart,arrive);
--     }
-- }

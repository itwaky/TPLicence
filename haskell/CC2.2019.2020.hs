-- ----------------------------------1


--1


-- 2 + 3x + 4x2 + x3 + 2x4

exemple_poly = \x -> 2 + x*(3 + x*(4 + x*(1+x*2)))

-- Homer liste

valeur_poly l x = case l of{
    [] -> 0;
    h:t -> h + x*(valeur_poly t x)
}



-- ---------------------------2


myelem x l = case l of {
    [] -> False;
    h:t ->  if h == x
                then True
            else
                myelem x t
}


inclus e1 e2 = case e1 of {
    [] -> True;
    h:t ->  if myelem h e2
                then inclus t e2
            else
                False
}


egal e1 e2 = inclus e1 e2 && inclus e2 e1




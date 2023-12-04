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





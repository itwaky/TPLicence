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

sans_doublon l = case l of{
    [] -> [];
    t:r ->  if t == head r
                then sans_doublon r
            else
                sans_doublon r ++ [r]
}




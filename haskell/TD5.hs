-- --------------------------------1.liste polymorphe-----------------------------



-- 1

nth l1 n = case l1 of {
    t:r ->  if n == 0
                then t
            else
                nth l1 (n-1)
    [] -> []
}




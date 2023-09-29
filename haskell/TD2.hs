
-- ----------------------Exercice2-------------


et (a,b) =
    if a
        then b
    else
        False

ou (a,b) =
    if a
        then True
    else 
        b


non a =
    if a
        then False
    else
        True

implique (a,b) =
    if a
        then b
    else
        True



-- --------------------------------Exercice3------------------------------



renverse n = 
    if n >= 10 && n <= 99
        then let a = n `div` 10 in let b = (n `mod` 10) * 10 in a + b
    else
        error("nombre invalide")



-- -----------------------------Exercice4-----------------------------------


-- 1

chaine2 ((a1,b1),(a2,b2)) = (a1 == a2 || a1 == b2 || b1 == a2 || b1 == b2)

extremite ((a1,b1),(a2,b2)) =
    if b1 == a2
        then (a1,b2)
    else if a1 == a2
        then (b1,b2)
    else if (b1 == b2)
        then (a1,a2)
    else
        (b1,a2)

chaine3 ((a1,b1),(a2,b2),(a3,b3)) = chaine2((a1,b1),(a2,b2)) && chaine2(extremite((a1,b1),(a2,b2)),(a3,b3)) || chaine2((a1,b1),(a3,b3)) && chaine2(extremite((a1,b1),(a3,b3)),(a2,b2)) || chaine2((a2,b2),(a3,b3)) && chaine2(extremite((a2,b2),(a3,b3)),(a1,b1))


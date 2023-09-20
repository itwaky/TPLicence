import Data.Complex

-- ex01


double x = x*2

carre x = x**2





-- ex02

-- a

poly x = 2 + 3*x + 4*x**2 + x**3 + 2*x**4



-- b

-- poly x = let x2 = x**2 in let x3 = x**3 in let x4 == x**4 in 2 + 3 * x + 4 * x2 + x3 + 2 * x4


-- ex03 

joursemaine x = if x==1 then "lundi" else if x==2 then "mardi" else if x==3 then "mercredi" else if x==4 then "jeudi" else if x==5 then "vendredi" else if x==6 then "samedi" else "dimanche"




-- ex04

mois x = if x==1 then "janvier" else if x==2 then "fevrier" else if x==3 then "mars" else if x==4 then "avril" else if x==5 then "mai" else if x==6 then "juin" else if x==7 then "juillet" else if x==8 then "août" else if x==9 then "septembre" else if x==10 then "octobre" else if x==11 then "novembre" else "décembre"


--ex 05

date (jour, nbJour, moi, annee) ="le " ++ joursemaine(jour) ++ " " ++ show(nbJour) ++ " " ++ mois(moi) ++ " " ++ show(annee)



--ex 06

-- a
{-
discriminant (a, b, c) = b**2 - 4 * a * c


-- b



solution a b c = let delta = discriminant(a,b,c) in 
    if delta > 0 
    then let a1 = (-b) - sqrt(delta) in let a2 = 2 * a in let a3 = a1 / a2 in a3 
    else if delta == 0 
        then let a1 = b + sqrt(delta) in let a2 = 2 * a in let a3 = a1 / a2 in a3 
        else "error"

-} 


discriminant a b c = b**2 - 4 * a * c


solution a b c =
    let delta = discriminant a b c
    in if delta > 0
           then let a1 = (-b) - sqrt delta
                    a2 = 2 * a
                    a3 = a1 / a2
                in right (a3, a3 + sqrt delta / a2)
           else if delta == 0
                    then let a1 = b + sqrt delta
                             a2 = 2 * a
                             a3 = a1 / a2
                         in right (a3, a3)
                    else left "Pas de solution réelle"



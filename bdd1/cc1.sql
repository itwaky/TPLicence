SELECT idp, article, prix FROM produit WHERE prix>300 ORDER BY prix DESC;

SELECT nom FROM client WHERE parrain IS NULL and TO_CHAR(sysdate,'YYYY')-TO_CHAR(naissance,'YYYY')<40;

SELECT article, marque, prix FROM produit WHERE prix = (SELECT MAX(prix) FROM produit);

SELECT COUNT(DISTINCT ville) AS nb_ville FROM client WHERE parrain IS NOT NULL;

SELECT idp FROM ligne WHERE idcm IN(SELECT idcm FROM commande WHERE TO_CHAR(datecm,'DD/MM/YYYY'))>='28/04/2018';
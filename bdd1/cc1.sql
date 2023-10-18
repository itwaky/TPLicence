/* 1. Identifiant, nom et prix des produits dont le prix est supérieur à 300 euros, classés par prix
décroissant. */

SELECT idp, article, prix FROM produit WHERE prix>=300 ORDER BY prix;

/* 2. Noms des clients qui n’ont pas de parrain et qui ont moins de 40 ans. */

SELECT nom FROM client WHERE parrain IS NULL AND TO_CHAR(sysdate,'YYYY')-TO_CHAR(naissance,'YYYY') <= 40;

/* 3. Nom, marque et prix du produit le plus cher de la boutique. */

SELECT article, marque, prix FROM produit WHERE prix = (SELECT MAX(prix) FROM produit);

/* 4. Nombre de villes différentes où habitent les clients qui ont un parrain. */

SELECT COUNT(DISTINCT ville) AS nb_ville FROM client WHERE parrain IS NOT NULL;

/* 5. Identifiants des produits qui ont été commandés depuis le 28 avril 2018. */

SELECT idp FROM ligne WHERE idcm IN(SELECT idcm FROM commande WHERE TO_CHAR(datecm,'DD/MM/YYYY') >= '28/04/2018');

/* 6. Identifiants des commandes qui ne contiennent pas un produit de prix supérieur à 100 euros */

SELECT idcm FROM ligne WHERE idp NOT IN(SELECT idp FROM produit WHERE prix>=100);

/* 7. Noms des clients qui ont commandé un produit dont le nom contient 'canape' */

SELECT nom FROM client WHERE idcl IN(SELECT idcl FROM commande WHERE idcm IN(SELECT idcm FROM ligne WHERE idp IN(SELECT idp FROM produit WHERE article LIKE('%canape%'))));

/* 8. Identifiant et âge des clients qui ont commandé plus d’une fois. */

SELECT idcl, TO_CHAR(sysdate,'YYYY')-TO_CHAR(naissance,'YYYY') AS age FROM client WHERE idcl IN(SELECT idcl FROM commande GROUP BY idcl HAVING COUNT(idcm)>1);

/* 9. Identifiant du client qui a passé le plus de commandes. */

SELECT idcl FROM commande GROUP BY idcl HAVING COUNT(idcm) = (SELECT MAX(COUNT(idcm)) FROM commande GROUP BY idcl);





/* Deuxieme CC */

/* 1. Nom, mois et année de naissance des clients qui habitent à Illkirch */

SELECT nom, TO_CHAR(naissance,'MM/YYYY') AS Date_Naissance FROM client WHERE upper(ville) = 'ILLKIRCH';

/* 2. Année de naissance du client le plus âgé */

SELECT MAX(TO_CHAR(naissance,'YYYY')) AS older FROM client;

/* 3. Noms des clients nés depuis le 16 mars 1997 */

SELECT nom FROM client WHERE TO_CHAR(naissance,'DD/MM/YYYY') > '16/03/1997';

/* 4. Numéro de la commande la plus ancienne */

SELECT idcm FROM commande WHERE datecm = (SELECT MIN(datecm) FROM commande);

/* 5. Nombre de clients différents ayant commandé */

SELECT COUNT(DISTINCT idcl) AS nb_commande FROM commande;

/* 6. Pour chaque ville, donner le nombre de clients qui y habitent */

SELECT ville, COUNT(idcl) AS nb_client FROM client GROUP BY ville;

/* 7. Noms des clients qui ont passé plusieurs commandes */

SELECT nom FROM client WHERE idcl IN(SELECT idcl FROM commande GROUP BY idcl HAVING COUNT(idcm)>1);

/* 8. Identifiant du client qui a parrainé le plus de filleuls */

SELECT parrain FROM client GROUP BY parrain HAVING COUNT(*) = (SELECT MAX(COUNT(*)) FROM client GROUP BY parrain);

/* 9. [Bonus] Pour chaque client de la table CLIENT, donner son nom et le nombre de commandes qu’il effectuées, et afficher 0 s’il n’a pas effectué de commande */

SELECT nom, COUNT(idcm) FROM client INNER JOIN commande ON client.idcl = commande.idcl GROUP BY nom, commande.idcl;
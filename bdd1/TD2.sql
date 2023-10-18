/* 1. Client résidant soit à Strasbourg, soit à Benfeld */

SELECT * from l2i_client WHERE ville IN('Strasbourg','Benfeld');

/* 2. Numéro et nom des produits dont le prix est compris entre 50 et 150 euros. */

SELECT idp, article FROM l2i_produit WHERE prix BETWEEN 50 and 150;

/* 3. Identifiant et nom des produits dont le numéro de rayon est 1, 5 ou 8. */

SELECT idp, article FROM l2i_produit WHERE idr IN(1,5,8);

/* 4. Identifiant et nom des produits dont le nom comporte le mot table ou lampe */

SELECT idp, article FROM l2i_produit WHERE article LIKE('%table%') or article LIKE('%lampe%');

/* 5. Identifiant, nom et prénom des clients nés entre 1974 et 1984 */




/* Modif affichage */


/* 1. Numéro de tous les clients qui figurent dans la table commande avec suppression
des doublons.
2. Numéro de tous les clients qui figurent dans la table commande en renommant
la colonne affichée CLIENT.
3. Afficher toutes les commandes en renommant les 3 colonnes respectivement
Numéro, Client et Date commande.
4. Afficher toutes les marques des produits en lettres majuscules.
5. Noms de tous les clients affichés par ordre alphabétique.
6. Relation client par ordre de ville croissant et premier achat décroissant.
7. Commandes triées par ordre décroissant des dates. */



SELECT DISTINCT idcl FROM l2i_commande;

SELECT nom AS CLIENT FROM l2i_client WHERE idcl IN(SELECT idcl FROM l2i_commande);

SELECT idcm AS Numero, idcl AS Client, datecm AS date_commande FROM l2i_commande;

SELECT upper(marque) FROM l2i_produit;

SELECT nom FROM l2i_client ORDER BY nom;

SELECT * FROM l2i_client ORDER BY ville, achat1 DESC;

SELECT * FROM l2i_commande ORDER BY datecm DESC;


/* Calcul avec valeur null */

/* 
1. Nom des produits de marque inconnue.
2. Identifiant, nom et prénom des personnes qui n’ont pas été parrainées.
*/

SELECT article FROM l2i_produit WHERE marque IS NULL;

SELECT idcl, nom, prenom FROM l2i_client WHERE parrain IS NULL;


/* Dates */

/*
1. Nom, prénom et date de naissance des clients où les dates de naissance
sont affichées sous un formt JJ/MM/AA (jour, mois et année sur 2 chiffres,
séparés par /). La colonne contenant la date reste intitulée naissance.
2. Numéro des commandes passées en 2002.
3. Nom, prénom et âge (en nombre d’années) de chaque client.
4. Nom, prénom et ancienneté (en nombre d’années) de chaque client.
5. Nom et prénom des personnes de moins de 40 ans.
*/


SELECT nom, prenom, TO_CHAR(naissance,'DD/MM/YY') AS Naissance FROM l2i_client;

SELECT idcm FROM l2i_commande WHERE TO_CHAR(datecm,'YYYY')=2002;

SELECT nom, prenom, TO_CHAR(sysdate,'YYYY') - TO_CHAR(naissance, 'YYYY') AS Age FROM l2i_client;

SELECT nom, prenom, TO_CHAR(sysdate,'YYYY') - achat1 AS anciennete FROM l2i_client;

SELECT nom, prenom FROM l2i_client WHERE TO_CHAR(sysdate,'YYYY') - TO_CHAR(naissance,'YYYY') < 40;


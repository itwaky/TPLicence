/* Restriction - projection */


SELECT idcl from l2i_commande;

SELECT idp,prix from l2i_produit;

SELECT nom,prenom from l2i_client where parrain=1;

SELECT article from l2i_produit where marque='MARINA';

SELECT nom FROM l2i_client where ville='Strasbourg';

SELECT * FROM l2i_produit WHERE idr=1;

SELECT prix FROM l2i_produit WHERE article='chaise';

SELECT idp, article FROM l2i_produit WHERE prix<=99;

SELECT idcm, datecm FROM l2i_commande WHERE idcl=8;


/* Produit cartésien - Jointure */


/* 1. Donner le numéro, nom, prix de chaque produit avec le nom du rayon où 
il est stocké. */

SELECT idp, article, prix, nom AS nom_rayon FROM l2i_produit INNER JOIN l2i_rayon ON l2i_produit.idr = L2i_rayon.idr;

/* 2. Marque des produits informatique. */

SELECT DISTINCT marque FROM l2i_rayon INNER JOIN l2i_produit ON l2i_rayon.idr = l2i_produit.idr;

/* 3. Numéro de commande accompagné du nom et prénom du client ainsi que
la date de la commande. */

SELECT l2i_client.idcl, nom, prenom, l2i_commande.datecm FROM L2i_client INNER JOIN l2i_commande ON l2i_client.idcl = l2i_commande.idcl;

/* 4. Pour chaque ligne de commande, afficher le numéro de la commande, le
nom du produit, le prix unitaire HT et la quantité commandée. */

SELECT l2i_ligne.idcm, article, prix, qte FROM l2i_ligne INNER JOIN l2i_produit ON l2i_ligne.idp=l2i_produit.idp;


/* 5. Identifiant, nom et prénom des clients nés entre 1974 et 1984 */

SELECT nom, prenom FROM l2i_client WHERE TO_CHAR(naissance,'yyyy') BETWEEN 1974 and 1984;

/* 6. Nom et ville des clients qui habitent une ville dont le nom finit par HEIM. */

SELECT nom, ville FROM l2i_client WHERE upper(ville) LIKE('%HEIM');

/* 7. Nom des clients dont le nom comporte la sous-chaîne RE et finit par TZ. */

SELECT nom FROM l2i_client WHERE upper(ville) LIKE('%RE%') and upper(ville) LIKE('%TZ');

/* 8. Nom des produits qui figurent dans une quelconque commande. */

SELECT article FROM l2i_produit WHERE idp IN(SELECT idp FROM l2i_ligne);

SELECT article FROM l2i_produit INNER JOIN L2i_ligne ON l2i_produit.idp=L2i_ligne.idp;

/* 9. Identifiant de client pour lequel il n’y a pas de commande. */

SELECT idcl FROM l2i_client WHERE idcl NOT IN(SELECT idcl FROM l2i_commande);

/* 10. Identifiant des produits dont le prix est inférieur à 250 euros et qui ne figurent pas dans les commandes. */

SELECT idp FROM l2i_produit WHERE prix<250 AND idp NOT IN(SELECT idp FROM l2i_ligne);













/* 1. Numéro de tous les clients qui figurent dans la table commande avec suppression
des doublons. */

SELECT DISTINCT idcl FROM l2i_commande;
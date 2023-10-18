/* Fonction D'agrégation */

/*
1. Nombre de clients stockés dans la base.
2. Nombre de produits dont le prix est inférieur ou égal à 199 euros.
3. Prix du produit le plus cher de la boutique.
4. Age du client le plus jeune.
5. Moyenne sur l’ancienneté des clients.
6. Moyenne d’âge des clients.
7. Nombre de produits commandés (somme sur le champ quantité dans la table ligne, toutes
commandes confondues).
8. Identifiant et nom du produit le plus cher de la boutique.
9. Nom, prénom et âge du client le plus jeune.
*/

SELECT COUNT(*) AS nb_Client FROM l2i_client;

SELECT COUNT(*) AS nb_produit FROM l2i_produit WHERE prix<=199;

SELECT MAX(prix) AS prix_max FROM l2i_produit;

SELECT MIN(TO_CHAR(sysdate,'YYYY')-TO_CHAR(naissance,'YYYY')) AS ageMin FROM l2i_client;

SELECT AVG(TO_CHAR(sysdate,'YYYY')-achat1) AS ancienneteMoy FROM l2i_client;

SELECT AVG(TO_CHAR(sysdate,'YYYY')-TO_CHAR(naissance,'YYYY')) AS MoyAge FROM l2i_client;

SELECT SUM(qte) FROM l2i_ligne;

SELECT idp, article FROM l2i_produit WHERE prix=(SELECT MAX(prix) FROM l2i_produit);

SELECT nom, prenom, TO_CHAR(sysdate,'YYYY')-TO_CHAR(naissance,'YYYY') AS Age FROM l2i_client WHERE TO_CHAR(sysdate,'YYYY')-TO_CHAR(naissance,'YYYY') = (SELECT MIN(TO_CHAR(sysdate,'YYYY')-TO_CHAR(naissance,'YYYY')) FROM l2i_client);



/* GROUP BY et fonctions d’agrégation */

/*
1. Numéro des commandes accompagné du nombre d’articles différents qui la constitue.
Exemple : la commande 1 comporte 2 articles (ou lignes) distincts (82803 et 15559).
2. Numéro des commandes accompagné de la quantité d’articles.
Exemple : la commande 4 est constituée de 3 articles (1 exemplaire de l’article 06607 + 2
exemplaires de l’article 06277).
3. Même question qu’en 2 en ajoutant la contrainte que la quantité d’articles doit être
supérieure ou égale à 3.
4. Pour chaque client, donner le nombre de personnes qu’il a directement parrainé.
5. Compléter la requête 4, en rajoutant les noms des parrains.
6. Compléter la requête 5, en affichant aussi les clients qui n’ont parrainé personne
(en affichant 0 filleuls).
7. Nom des rayons où il y a au moins 3 articles proposés.
8. Nom du rayon où il y a le plus d’articles proposés.
9. Nom du rayon et nombre d’articles proposés, pour le rayon où il y a le plus d’articles proposés
(utilisation d'une table temporaire).
10. Nom du produit figurant le plus souvent dans les lignes de commande.
11. Nom du produit et nombre de lignes de commande où le produit apparaît, pour le produit
figurant le plus souvent dans les lignes de commande (utilisation d'une table temporaire)
*/

SELECT idcm, COUNT(idp) FROM l2i_ligne GROUP BY idcm; 

SELECT idcm, SUM(qte) FROM l2i_ligne GROUP BY idcm;

SELECT idcm, SUM(qte) FROM l2i_ligne GROUP BY idcm HAVING SUM(qte)>=3;

SELECT parrain, COUNT(*) FROM l2i_client GROUP BY parrain;

SELECT b.nom, a.parrain, COUNT(*) AS nb_parainage FROM l2i_client a INNER JOIN l2i_client b ON a.parrain = b.idcl GROUP BY a.parrain, b.nom;


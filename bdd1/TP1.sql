select 1 + mod(12,5) from DUAL;
select 'Bonjour aujourd''hui c''est le : ' as text, sysdate from DUAL;



SELECT *
FROM L2I_CIRCUIT L2I_CIRETAPE;




SELECT PRIX, RANG FROM L2I_CIRCUIT JOIN L2I_CIRETAPE ON L2I_CIRETAPE.NC = L2I_CIRCUIT.NC;




/* Nom des clients de l’agence classés par ordre alphabétique */


SELECT NOM FROM L2I_CLIENT ORDER BY NOM;


/* Numéro de circuit, prix des circuits disponibles par ordre décroissant. */

SELECT NC, PRIX FROM L2I_CIRCUIT ORDER BY PRIX DESC;


/* Villes de départ, numéro de circuit des différents circuits */


SELECT VDEP, NC FROM L2I_CIRCUIT;


/* --------------------------- 6 ----------------------------- */


/* Noms des clients ayant réservé en 2016. */


SELECT NOMC FROM L2I_RESER WHERE TO_CHAR(DATEDEP, 'YYYY') = 2016;


/* Noms des clients ayant réservé après le mois d’avril 2016. */

SELECT NOMC FROM L2I_RESER WHERE TO_CHAR(DATEDEP, 'YYYY') > '2016' AND TO_CHAR(DATEDEP,'MM') > '04';


/*Noms des clients ayant réservé pendant les cinq dernières années.*/


SELECT NOMC FROM L2I_RESER WHERE TO_CHAR(sysdate, 'YYYY') - TO_CHAR(DATEDEP, 'YYYY') <= 5 ORDER BY NOMC;


/* -----------------------------7---------------------------- */

/*Nom des clients ayant réservé en septembre ou en mai.*/


SELECT * FROM L2I_RESER WHERE TO_CHAR(DATEDEP, 'MM') = 05 OR TO_CHAR(DATEDEP, 'MM') = 09;


/* Circuits ne passant ni par Londres ni par Amsterdam */

SELECT * FROM L2I_CIRETAPE WHERE VILET NOT IN('Londres', 'Amsterdam');


/* Numéro de réservation, numéro de circuit des réservations effectuées entre avril et septembre. */


SELECT NR, NC FROM L2I_RESER WHERE TO_CHAR(DATEDEP, 'MM') BETWEEN '04' AND '09';



/*Numéro de circuit, date de départ et nombre de places réservées par Picsou*/


SELECT NC, DATEDEP, NBRES FROM L2I_RESER WHERE NOMC = 'Picsou';


/* Ville dont le nom contient ’Port’ */

SELECT NOMV FROM L2I_VILLE WHERE NOMV LIKE('%Port%');

/* Villes étapes visitées par GrosseBaf */

SELECT vilet from L2I_CIRETAPE c, L2I_RESER r where c.nc = r.nc and nomc='GrosseBaf';

/* Numéro des circuits ayant des villes étapes en Irlande. */

select DISTINCT nc from L2I_CIRETAPE where vilet in(select nomv from l2i_ville where lower(pays) = 'irlande');

select DISTINCT nc from L2I_CIRETAPE join l2i_ville on L2I_CIRETAPE.vilet = l2i_ville.nomv where lower(l2i_ville.pays) = 'irlande';

/* Noms des villes contenant plusieurs monuments */

select nomv from l2i_monument group by nomv having count(nomm) > 1;

/* Numéro, ville de départ et d’arrivée des circuits qui démarrent après le 17 avril 2017 et qui ont plus de 10 places libres. */

select DISTINCT nc, vdep, varr from l2I_circuit natural join l2i_cirprog where l2i_cirprog.datedep > to_date('17/04/17', 'DD/MM/YY') and l2i_cirprog.nblibr >= 10;

/* Monuments visités par Asterix. */

select nomm from l2i_monument where nomv in(select vilet from l2i_ciretape where nc in(select nc from L2i_reser where lower(nomc) = 'asterix'));

/* Numéro de circuit et date de départ des circuits ayant une ville étape en Angleterre */

select nc, datedep from l2i_cirprog where nc in(select nc from l2i_ciretape where vilet in(select nomv from l2i_ville where lower(pays) = 'angleterre'));

/* Numéros des circuits qui ont été réservés avec le nom du client et numéros des circuits qui n’ont pas été réservés. */

select l2I_circuit.nc, l2i_reser.nomc from l2i_circuit left join l2i_reser on l2i_circuit.nc = l2i_reser.nc order by l2i_circuit.nc;




/* Nombre de monuments à visiter en France */

select count(nomm) as nb_monument from l2i_monument where nomv in(select nomv from l2i_ville where lower(pays) = 'france');

/* Prix moyen d’un circuit. */

select avg(prix) as prix_moyen from l2i_circuit;

/* Nombre de places réservées par chaque client. */

select nomc, sum(nbres) as nb_places from l2i_reser group by nomc;

/* Circuit le plus cher. */

select max(prix) as prix_max from l2i_circuit;

/* Noms des villes contenant plusieurs monuments. */

select nomv from l2i_monument group by nomv having count(nomm) > 1;

/* Villes visitées par Donald avec le nombre de monuments dans chaque ville */

select nomv, count(nomm) as nb_monument from l2i_monument group by nomv having nomv in(select vilet from l2i_ciretape where nc in(select nc from l2i_reser where lower(nomc) = 'donald'));

/* Nombre de monuments visités par Donald. */

select count(nomm) as nb_monument from l2i_monument where nomv in(select vilet from l2i_ciretape where nc in(select nc from l2i_reser where lower(nomc) = 'donald'));

/* Nombre de monuments visités par chaque client */

select count(nomm) as nb_monument from l2i_monument group by nomv having nomv in(select vilet from l2i_ciretape where nc in(select nc from l2i_reser)); -- jsp pourquoi ça fonctionne mdr mais c'est pas grave


select nomc, count(l2i_monument.nomm) as nb_monument from l2i_reser join l2i_ciretape on l2i_reser.nc = l2i_ciretape.nc join l2i_monument on l2i_ciretape.vilet = l2i_monument.nomv group by nomc; -- solution que je comprends

/* Liste des clients avec le montant total de la facture associée */

select nomc, sum(l2i_circuit.prix * l2i_reser.nbres) as facture_total from l2i_reser join l2i_circuit on l2i_reser.nc = l2i_circuit.nc group by nomc;

/* Montant de la plus grosse facture */

select max(facture_total) from (select nomc, l2i_circuit.prix * l2i_reser.nbres as facture_total from l2i_reser join l2i_circuit on l2i_reser.nc = l2i_circuit.nc);

/* Client ayant la plus grosse facture */

select max(facture_total) from (select nomc, sum(l2i_circuit.prix * l2i_reser.nbres) as facture_total from l2i_reser join l2i_circuit on l2i_reser.nc = l2i_circuit.nc group by nomc);
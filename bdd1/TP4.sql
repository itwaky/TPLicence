/*
. Créer une vue nommée circuit_pas_cher contenant le n° de circuit et le prix des circuits
de prix inférieur à 200 euros.
- vérifier dans la table système user_views la présence de cette vue.
- insérer un tuple à travers la vue circuit_pas_cher. Que se passe-t-il ?
*/

create view circuit_pas_cher(nc, prix) as (select nc, prix from l2i_circuit where prix<200);


select view_name from user_views;

insert into circuit_pas_cher(nc, prix) values(19,199); /* privilèges insuffisants */

/*
Pour que la vue circuit_pas_cher puisse être modifiée, elle doit reposer sur une table
 que vous avez le droit de modifier :
- créer une table mon_circuit identique à la table circuit.
- définir la vue circuit_pas_cher qui s’appuie sur votre table mon_circuit sans
utiliser l’option « check option ».
- peut-on insérer un circuit de prix supérieur à 200 euros à travers la vue ?
- peut-on modifier le prix d'un circuit appartenant à la vue en changeant son prix à 300 ?
*/

create table mon_circuit(
    nc number primary key,
    vdep varchar2(20),
    varr varchar2(20),
    prix number(6)
);

create view mon_circuit_pas_cher(nc, prix) as (select nc, prix from mon_circuit where prix<200);

CREATE VIEW mon_circuit_pas_cher (nc, prix) AS (SELECT nc, prix FROM mon_circuit WHERE prix < 200 WITH CHECK OPTION);



grant select on table circuit_pas_cher to nomDeLaPersonne;

SELECT * FROM user_tab_privs;
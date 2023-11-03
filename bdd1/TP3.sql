

/* Table ETUDIANT */



/* Créer une table ETUDIANT avec les champs : net, nom et age. L’attribut net (numéro d’étudiant) est la clé primaire de la relation */

create table etudiant(
    net number primary key,
    nom varchar2(20),
    age number(3)
);


/* 
Insérer des lignes qui peuvent être :
– complètes (toutes les colonnes sont renseignées) dans l’ordre de définition des colonnes,
– complètes, mais où les valeurs sont dans un ordre différent que dans celui de définition des colonnes,
– incomplètes, i.e. toutes les valeurs des colonnes ne sont pas connues.
*/

insert into etudiant values(0,'Eros',21);

insert into etudiant(nom ,net ,age) values  ('Eros', 1, 21);

insert into etudiant(nom, net) values('Eros', 2);



/* Modifier et supprimer des lignes. */

update etudiant set nom='didier'
where net = 1 and nom = 'Eros';

delete from etudiant
where net = 2 and age is null;



/* Modifier la table ETUDIANT : ajouter la contrainte d’intégrité age >= 18 et insérer des lignes qui vérifient ou non la contrainte. */

alter table etudiant add constraint age check(age >= 18);


/* Modifier la table ETUDIANT : ajouter la colonne adresse et insérer des lignes avec l’adresse */

alter table etudiant add(adresse varchar2(30));

insert into etudiant values(4,'Eros',22,'Rue des arbres');






/* Table COUT */

/*
Créer la table COUT avec les champs age et tarif et les deux contraintes :
– le champ age est la clé primaire de la relation,
– le champ tarif a pour seules valeurs autorisées : 1, 2 ou 3.
*/

create table cout(
    age number(3) primary key,
    tarif number(1) check(tarif in(1,2,3))
);

/* Insérer des lignes qui vérifient ou non la contrainte. */

insert into cout values (13, 8);

insert into cout values (18, 1);

/*  
Modifier la table ETUDIANT. Ajouter la contrainte référentielle :
– le champ age fait référence au champ age dans la table COUT,
– insérer des lignes dans la table ETUDIANT qui vérifient ou non la contrainte,
– modifier ou supprimer dans COUT une ligne référencée dans ETUDIANT. Que se passe-t-il ? 
*/

alter table etudiant add foreign key (age) references cout(age);

insert into etudiant values (43,'Eros', 22, 'rue de eau');

insert into etudiant values (43,'Eros', 19, 'rue de eau');



delete from cout where age = 22; /* impossible violation de contrainte */






/* Table INSCRIPTION */

/*
Créer la table INSCRIPTION avec les champs net et diplôme :
– le champ net (numéro d’étudiant) est la clé de la relation et fait référence à la clé dans la relation
ETUDIANT,
– insérer des lignes qui vérifient ou non la contrainte référentielle,
– supprimer une ligne de la relation ETUDIANT qui est référencée dans la table INSCRIPTION.
La suppression a-t-elle lieu ? 
*/

create table inscription(
    net number primary key,
    diplome varchar2(20),
    foreign key (net) references etudiant(net)
    on delete cascade
);


insert into inscription values(0, 'bts');

insert into inscription values(123, 'bac');



delete from etudiant where net = 0;/* non violation de contrainte */


/* Ajouter l’option ON DELETE CASCADE dans la contrainte référentielle et tester à nouveau la
suppression des lignes. */


alter table inscription drop constraint net;

alter table inscription add foreign key (net) references etudiant(net) on delete cascade;

/* la supression fonctionne mtn */
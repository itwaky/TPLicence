.at 10
x: .word 000
y: .word 000
const: .word 007
sortie: .word 000
.at 20
INP x
LDA x
ADD x
ADD x
INP y
ADD y
SUB const
STA sortie
OUT sortie
HRS





.at 10
zero:  .word 000 ; Constante 0
one:   .word 001 ; Constante 1
n:     .word 000 ; Variable  n

.at 20
main:  INP n     ; Lire n
       LDA n
       JAZ yes
no:    OUT zero  ; Afficher 0 et terminer
exit1: HRS
yes:   OUT one   ; Afficher 1 et terminer
exit2: HRS



.at 10
entre: .word 000
neuf: .word 009
un: .word 001
zero: .word 000
.at 20
main:	INP entre
	LDA entre
	SUB neuf
	JAZ no
	
yes:    OUT un
	HRS

no: 	OUT zero
	HRS
	


//fonctionne pas pour l'instant	
.at 10
entreUn: .word 000
entreDeux: .word 000
one: .word 001
zero: .word 000
.at 20
main:	INP entreUn
	INP entreDeux
	LDA entreUn
	SUB entreDeux
	JAZ next
	OUT zero
sortie:	HRS

next:	LDA entreDeux
	SUB entreUn
	JAZ yes
	OUT zero
	HRS
yes:	OUT one
	HRS
	
	
	
val: .word 777
ptr: .word 000

main:   INP ptr
	LDA val     
	STI ptr
	HRS
	
	

ptr: .word 000
tmp: .word 000

main:   INP ptr
	LDI ptr
	STA tmp
	OUT tmp
	HRS
	
	
tab: .word 010, 121, 232, 343, 454, 565, 676, 787, 898, 909
ptr: .word tab
i:   .word 000
tmp: .word 000

main:   INP i
	LDA ptr
	ADD i
	STA ptr
	LDI ptr
	STA tmp
	OUT tmp
	HRS
	

tab: .word 010, 121, 232, 343, 454, 565, 676, 787, 898, 909
ptr: .word tab
i:   .word 000
n:   .word 000

main:   INP i
	LDA ptr
	ADD i
	STA ptr
	LDA n
	STI ptr
	HRS
	
	
tab: .word 010, 121, 232, 343, 454, 565, 676, 787, 898, 909
ptr: .word tab
i:   .word 000
n:   .word 000

main:   INP i
        INP n
	LDA ptr
	ADD i
	STA ptr
	LDA n
	STI ptr
	HRS
	
	
zero: .word 000
one:  .word 001
tab1: .word 000
tab2: .word
size: .word 000
i:    .word 000
ptr:  .word 000
ptr2: .word 000


main:   INP tab1
	INP tab2
	INP size
loop:	LDA size
	SUB i
	JAZ exit
	LDA tab1
	ADD i
	STA ptr
	LDA tab2
	ADD i
	STA ptr2
	LDA i
	STI ptr
	STI ptr2
	ADD one
	STA i
	
	LDA zero
	JAZ loop
exit:	HRS
	


		
zero: .word 000
one:  .word 001
tab:  .word 040
ptr:  .word 000
i:    .word 000
entre: .word 000

main:	INP i
loop:	LDA i
	SUB one
	STA i
	JAZ loopc
	STA i
	LDA tab
	ADD i
	STA ptr
	INP entre
	LDA entre
	STI ptr
	LDA zero
	JAZ loop
loopc:	HRS
	
	
	


zero: .word 000
one:  .word 001
ptr:  .word 070
n:    .word 000
i:    .word 000
tmp:  .word 000

main:	INP n
read:	LDA n
	SUB i
	JAZ suite
	INP tmp
	LDA tmp
	STI ptr
	LDA ptr
	ADD one
	STA ptr
	LDA i
	ADD one
	STA i
	LDA zero
	JAZ read
	
suite:	LDA ptr
	SUB one
	STA ptr
write:	LDA i
	JAZ exit
	LDI ptr
	STA tmp
	OUT tmp
	LDA ptr
	SUB one
	STA ptr
	LDA i
	SUB one
	STA i
	LDA zero
	JAZ write
exit:	HRS


;---------------------------------TP2----2.2Exercices------------------------------------------------


;ex------------------1


.at 10

tab: .word 010, 121, 232, 343, 454, 565, 676, 787, 898, 909
entre: .word 000
ptr: .word tab
sortie: .word 000


main: INP entre
      LDA ptr
      ADD entre
      STA ptr
      LDI ptr
      STA sortie
      OUT sortie
      HRS


;ex--------------2

.at 10

tab: .word 010, 121, 232, 343, 454, 565, 676, 787, 898, 909
entre: .word 000
entre2: .word 000
ptr: .word tab
sortie: .word 000


main: INP entre
      INP entre2
      LDA ptr
      ADD entre
      STA ptr
      LDA entre2
      STI ptr
      HRS




;ex----------------------------------3

.at 10

zero: .word 000
un: .word 001
tab1: .word 000
size: .word 000
i: .word 000



main:   INP tab1
        INP size
boucle: LDA size
        SUB i
        JAZ sortie
        LDA i
		STI tab1
        ADD un
        STA i
		LDA tab1
		ADD un
		STA tab1
		LDA zero
		JAZ boucle

sortie:	HRS


;ex-------------------------------4-------------------




.at 10

zero: .word 000
un: .word 001
tab1: .word 000
tab2: .word 000
size: .word 000
i: .word 000
ptr: .word 000



main:   INP tab1
		INP tab2
        INP size
boucle: LDA size
        SUB i
        JAZ suite
        LDA i
		STI tab1
        ADD un
        STA i
		LDA tab1
		ADD un
		STA tab1
		LDA zero
		JAZ boucle

suite:	LDA i
		JAZ sortie
		LDA tab1
		SUB i
		STA ptr
		LDI ptr
		STI tab2
		LDA tab2
		ADD un
		STA tab2
		LDA i
		SUB un
		STA i
		LDA zero
		JAZ suite
		



sortie:	HRS


.at 50
zero: .word 000
un: .word 001
i: .word 000
n: .word 000
nb: .word 000
tab: .word 000
.at 40
ptr: .word tab
sorti: .word 000

.at 10
main:	INP n

boucle:	LDA n
		SUB i
		JAZ suite
		INP nb
		LDA nb
		STI ptr
		LDA ptr
		ADD un
		STA ptr
		LDA i
		ADD un
		STA i
		LDA zero
		JAZ boucle

suite:	LDA i
		JAZ sortie
		LDA ptr
		SUB un
		STA ptr
		LDI ptr
		STA sorti
		OUT sorti
		LDA i 
		SUB un
		STA i
		LDA zero
		JAZ suite

sortie:	HRS

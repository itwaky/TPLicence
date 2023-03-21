;--------------------------------3.2--------------------------------


zero: .word 000
one: .word 001

; --- fonction tableau

tableau_size: .word 000
tableau_val: .word 000
tableau_ptab: .word 000
tableau_i: .word 000

tableau:            LDA ra
                    STA tableau_return

tableau_boucle:     LDA tableau_size
                    SUB tableau_i
                    JAZ tableau_return
                    LDA tableau_val
                    STI tableau_ptab
                    LDA tableau_ptab
                    ADD one
                    STA tableau_ptab
                    LDA tableau_i
                    ADD one
                    STA tableau_i
                    LDA zero
                    JAZ tableau_boucle

tableau_return:     .space 1


; --- fonction copie

tableauCopie_size: .word 000
tableauCopie_ptab: .word 000
tableauCopie_ptabCopie: .word 000
tableauCopie_i: .word 000

tableauCopie:       LDA ra
                    STA tableauCopie_return

tableauCopie_boucle: LDA tableauCopie_size
                    SUB tableauCopie_i
                    JAZ tableauCopie_return
                    LDI tableauCopie_ptab
                    STI tableauCopie_ptabCopie
                    LDA tableauCopie_ptab
                    ADD one
                    STA tableauCopie_ptab
                    LDA tableauCopie_ptabCopie
                    ADD one
                    STA tableauCopie_ptabCopie
                    LDA tableauCopie_i
                    ADD one
                    STA tableauCopie_i
                    LDA zero
                    JAZ tableauCopie_boucle

tableauCopie_return: .space 1



; --- main

main_size:  .word 000
main_val: .word 000
main_src: .word 000
main_dst: .word 000 


main:               INP main_val
                    INP main_size
                    INP main_src
                    INP main_dst
                    LDA main_val
                    STA tableau_val
                    LDA main_size
                    STA tableau_size
                    STA tableauCopie_size
                    LDA main_src
                    STA tableau_ptab
                    STA tableauCopie_ptab
                    LDA main_dst
                    STA tableauCopie_ptabCopie
                    LDA zero
                    JAZ tableau
                    LDA zero
                    JAZ tableauCopie
                    HRS


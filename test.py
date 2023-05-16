from tkinter import *
import subprocess
import os

courrant = os.getcwd()

def clear_frame():
   for widgets in fenetre.winfo_children():
      widgets.destroy()

def listButton(courrant):
    ls = os.listdir(courrant)
    for file in ls:
        button = Button(fenetre, text=file, command= lambda texte=file: changerRepertoire(courrant, texte))
        button.pack()

def changerRepertoire(courrant, nom):
    print(nom)
    courrant = courrant + "/" + nom
    print(courrant)
    clear_frame()
    listButton(courrant)




fenetre = Tk()


repertoire = Label(fenetre, text="Répertoire courant : "+courrant)

repertoire.pack()
#ls = subprocess.check_output(["ls"])


listButton(courrant)

fenetre.mainloop()
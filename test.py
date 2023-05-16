from tkinter import *
import subprocess
import os



fenetre = Tk()
#ls = subprocess.check_output(["ls"])
ls = os.listdir()
compteur = 1

liste = Listbox(fenetre)


for file in ls:
    liste.insert(compteur, file)
    compteur += 1
liste.pack()

fenetre.mainloop()
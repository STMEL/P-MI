import matplotlib.pyplot as plt
import matplotlib
matplotlib.use('Agg')


#Fonction affichage
def affichage(fichier,png):  
    with open(fichier,"r") as f: 
        x = []
        y = []
        for line in f:              # On lit le fichier ligne par ligne
            data = line.split()     # On sépare les données
            x.append(data[0])
            y.append(data[1])
        plt.plot(x,y)               
        plt.savefig(png)            # On enregistre le graphe


#Affichage erreurs pas de temps
print("Tapez 1 pour oui, 0 pour non")
print("Graphes erreurs pas de temps ?",end = " ")
pas = int(input())
if pas == 1:  
    affichage("Erreur_1.txt","Erreur_1.png")            # On appelle la fonction pour chaque fichier txt
    affichage("Erreur_01.txt","Erreur_01.png")
    affichage("Erreur_001.txt","Erreur_001.png")
    affichage("Erreur_0001.txt","Erreur_0001.png")
    affichage("Erreur_00001.txt","Erreur_00001.png")

#Affichage erreurs température
print("Graphes erreurs température ?",end = " ")
temp = int(input())
if temp == 1:
    affichage("Erreur_0.txt","Erreur_0.png")            # On appelle la fonction pour chaque fichier txt
    affichage("Erreur_infer.txt","Erreur_infer.png")
    affichage("Erreur_super.txt","Erreur_super.png")
    affichage("Erreur_egal.txt","Erreur_egal.png")
    affichage("Erreur_yinf0.txt","Erreur_yinf0.png")
    affichage("Erreur_ysup0.txt","Erreur_ysup0.png")
    affichage("Erreur_amb0.txt","Erreur_amb0.png")

#Affichage graphe Solutions
print("Graphes solutions ?",end = " ")
solution = int(input())
if solution == 1:
    affichage("Solutions_Euler.txt","Solutions_Euler.png")      # On appelle la fonction pour chaque fichier txt
    affichage("Solutions_direct.txt","Solutions_direct.png")


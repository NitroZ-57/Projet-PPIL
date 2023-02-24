# Projet-PPIL





## PROTOCOLE 

1. **Introduction** 
Chaque *Forme* sera envoyé via le protcole fait pour, ces formes seront envoyées avec leurs coordonées mondes. L'origine d'une *Forme* représentant les coordonnées mondes représente les coordonées du **premier point**. Les valeurs numériques seront toutes des valeurs flotantes (à virgule). Ainsi dans le protocole si l'on veut donner le vecteur (5, 6) on donnera en réalité 5.0 et 6.0. 


2. **Points communs**  
Chaque *Forme* aura en début de protocole son nom, écrit en minuscule pour les reconnaitre. Entre chaque information d'une forme il y aura un `espace`. Toute coordonées (Vecteur2D) sera encapsulé avec des parenthèses autour et une virgule séparant les deux valeurs de la forme : (abcisse,ordonée) sans espace
Ensuite pour les formes simples, il y aura un espace, suivi des de l'origine des coordonnées mondes. Pour finir le protocole il y aura un `point virgule` à la fin d'une forme simple. 

3. **Segment**  
Un segment aura d'abord son nom, puis les coordonées mondes, puis le vecteur associé au segment.   
Exemple : le segment de coordonée monde (1.5,2) et de vecteur (3.2,5) :  
`segment (1.5,2.0) (3.2,5.0) ;`

4. **Cercle**  
Un cercle aura d'abord son nom, puis les coordonées mondes (le centre du cercle), puis la cardinalité du vecteur.   
Exemple : le cercle de centre (-3,3) et de rayon 8.8 :  
`cercle (-3.0,3.0) 8.8 ;`

5. **Triangle**   
Un cercle aura d'abord son nom, puis les coordonées monde représentant ici les coordonnées des deux vecteurs données, puis les deux vecteurs de ce triangle.  
Exemple : le triangle d'origine (0, 1) avec les cotés (1.8,1.9) et (5.5, 1) :  
`triangle (0.0,1.0) (1.8,1.9) (5.5,1.0) ;`

6. **Polygone**   
Un polygone aura d'abord son nom, puis les coordonées monde de son premier point et ensuite une liste de points (Vecteur2D) le composant.  
Exemple : le polygone de coordonée monde (2, 2.5) avec les points (-1, 6.5), (4, 4), (7.8, 8.7), (-6, -12) et (5, -20.2)  
`polygone (2.0,2.5) (-1.9,6.5) (4.0,4.0) (7.8,8.7) (-6.0,-12.0) (5.0,-20.2) ;`

7. **Groupe**  
Un groupe aura d'abord son nom, puis un crochet ouvrant, commançant le début de la liste de forme, les formes seront ensuite de même format qu'en dessous et seront séparés par des espaces après chaque point virgule. Le format finira par un crochet fermant. (les crochets sont encapsulés par des espaces, sauf à droite du dernier.   
Exemple : le groupe composé d'un segment d'origine (4.1, 4.2) de longueur (1, -2), deux cercles respectivement de centre (8.4, -8.4) et (5,5) et de rayon 12 et 20.5, et d'un polygone de coordonée monde (2.5, 2) avec les points (-2, 6), (4.4, 33), (7, 8), (-12, -6) et (5.01, 10.5)   
`groupe [ segment (4.1,4.2) (1.0,-2.0) ; cercle (8.4,-8.4) 12.0 ; cercle (5.0,5.0) 20.5 ; polygone (2.5,2.0) (-2.0,6.0) (4.4,33.0) (7.0,8.0) (-12.0,-6.0) (5.01,10.5) ; ]`
# Projet jeu vidéo : c++ & SDL2

Dans le cadre d'un cours de c++ (ISBS3), ce projet consiste en la création d'un jeu vidéo en c++ et se basant sur la librairie SDL2.

## Compilation

Il faut utiliser QT Creator et avoir CMake et SDL2, SDL2 TTF, SDL2 IMAGE et SDL2 MIXER installés. Si le message d'erreur suivant apparaît :
```
error : nullptr was not declared in this scope
```
Il suffit de rajouter au début de [game.cpp](src/game.cpp) et de [main.cpp](src/main.cpp):
```
#define nullptr NULL
```

## Pour exécuter le jeu

### Windows
Lancer le fichier la_legende_de_Dora.exe

### MacOsX
* Installer les fichiers .dmg en suivant le README de chacun
* Lancer la_legende_de_Dora

### Linux
* Installer les libraires SDL2 :
```
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-ttf-dev
sudo apt-get install libsdl2-image-dev
sudo apt-get install libsdl2-mixer-dev
```
* Lancer la_legende_de_Dora

## Edité avec

* [C++](http://www.cplusplus.com/) - Langage de programmation utilisé
* [Qt Creator](https://www.qt.io/) - Editeur de texte utilisé
* [CMake](https://cmake.org/) - Compilateur utilisé
* [SDL2](https://wiki.libsdl.org/FrontPage) - Librairie utilisée pour la gestion des évènements (clavier & souris) et des graphismes

## Auteurs

* **Stretenowich Paul**
* **Vuong Benjamin**

## License

Ce projet est licensé sous la Licence Beerware - voir le [LICENSE.md](LICENSE.md) ficher pour plus de détails

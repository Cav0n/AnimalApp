# AnimalApp
A little App that list animals in Qt Quick

## Auteurs

- Bernard Florian
- Lopes-Vicente Benjamin

## Descriptif

AnimalApp est une application qui liste les mammifères disponible sur wikipedia et montre une courte description et sa photo quand on choisit un animal de la liste.

## Usage

Il suffit de lancer l'application avec une connexion internet et on peut chosir un animal pour en voir sa description et sa photo

## Techniques de programmation 

### PullDownMenu

Un PullDownMenu est présent dans chaque page de détail d'un animal, il permet d'ajouter le mammifère aux favoris.

### Clic

Un clic sur un mammifère ouvre la page de détail.

### SilicaListView

La liste sur laquelle démarre l'app est une silicalistview qui fonctionne avec l'animalmodel.

### SilicaWebView

Un clic sur le bouton "Voir la page Wikipedia" dans le detail permet d'afficher la page Wikipedia dans une SilicaWebView.

### Suppression

Pas de remorse bar... néanmois il y a possibilité de supprimer un animal de la liste.

### QObject avec QProperties

Chaque animal possède de multiples QPROPERTY permettant de décrire un animal et surtout de le lier dans la vue.

## Bugs connus

- Lors des appelles api le nombre de réponse est limité, on a donc que les 500 premiers mammifères
- Comme Wikipedia est extremement complexe et complet, parfois en plus d'animaux il y aussi des ordres, 
 des sous-classes ou autres...
- Page favoris pas encore mis en place.
- Quelques fois l'image et la description dans le detail ne se mettent pas a jour...

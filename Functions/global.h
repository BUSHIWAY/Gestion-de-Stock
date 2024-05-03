// La déclaration des fonctions et procédures dans ce fichier header pour un appel global.
// Cette methode facilite l'organisation du projet en séparant chaque fonction dans un fichier .c 
// et les utiliser dans un fichier principale.

void print(Prod* prod);
Prod* Extract(Prod* prod);
void Insert(Prod *products_list);
Prod* Add(Prod* prod, int choice);
Prod* Delete(Prod* prod, int choice);
Prod* Search(Prod* prod, int choice);
Prod* Edit(Prod* prod);
Prod* Sort(Prod* prod, int choice);
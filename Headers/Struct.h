
// La déclaration de la structure date
typedef struct Date{
    int day;
    int month;
    int year;
} Date;

// La déclaration de la structure Produit 
typedef struct Prod {
    int id;
    char name[50];
    char Description[256];
    char Username[25];
    float price;
    int Quantity;
    int Alert_threshold;
    Date d_last_enter, d_last_exit;
    struct Prod* next, *prev;
} Prod;
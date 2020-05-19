typedef struct{
    char color; //r: rouge, b: bleu, o: orange, m: mauve, j: jaune, v: vert
    char shape; //x: croix, l: losange, e: etoile, r: rectangle, t: trefle, c: cercle
} Case;

typedef struct{
    int score;    //variable de stockage du score du joueur
    Case hand[6]; //variable de stockage de la main du joueur
} Player;

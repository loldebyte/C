#include <stdint.h>
#include <stdio.h>

typedef struct point_t {
	int32_t x;
	int32_t y;
	char nom;
	} point_t;
// idéalement on crée un fonction qui construit notre point et incrémente un compteur de point, qu'on compare pour nommer les nouveaux points
int32_t max(int32_t x, int32_t y) {
	if (x>=y) {
		return x;
	} else return y;
}

point_t point_additionner(point_t a, point_t b) {
	point_t point_resultant = {a.x + b.x, a.y + b.y, max(a.nom,b.nom) + 1};
	return point_resultant;
}

void point_add_inplace(point_t * point1, point_t * point2) {
	point1->x = point1->x + point2->x;
	(*point1).y = (*point1).y + (*point2).y;
}

void point_printer(point_t point) {
	printf("abscise du point %c : %d\n", point.nom, point.x);
	printf("ordonnee du point %c : %d\n", point.nom, point.y);
}

int main(void)
{
	int32_t x_p1, y_p1;
	printf("Entrez l'abscise du point 1 : \n");
	scanf("%d",&x_p1);
	printf("Entrez l'abscise du point 1 : \n");
	scanf("%d", &y_p1);
	point_t point = {x_p1,y_p1,'1'};
	struct point_t * p = &point;
	point_t p2 = {.x=7,.y=18,.nom='2'};
	printf("abscise du point %c : %d\n", point.nom, point.x);
	printf("ordonnee du point %c : %d\n", point.nom, (*p).y); // (*p).y ou p->y
	point_printer(p2);
	point_t p3 = point_additionner(point, p2);
	point_printer(p3);
	point_add_inplace(&p3, &p3);
	point_printer(p3);
	point_t p4 = point_additionner(point, p3);
	point_t p5 = point_additionner(point, p4);
	point_t p6 = point_additionner(point, p5);
	point_printer(p4);
	point_printer(p5);
	point_printer(p6);
}



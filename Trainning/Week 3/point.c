#include <stdio.h>

typedef struct point{
    double x;
    double y;
}point;


void add_points(point * p1, point * p2, point * sum){
    sum->x = p1->x + p2->x;
    sum->y = p1->y + p2->y;
}

int main(void){
    
    point p_1;
    point p_2;
    point sum;
    
    p_1.x = 2;
    p_1.y = 5;
    
    p_2.x = 7;
    p_2.y = 2;
    
    printf("\n\tpoint 1 : (%.2f, %.2f)\n", p_1.x, p_1.y);
    printf("\tpoint 2 : (%.2f, %.2f)\n", p_2.x, p_2.y);
    
    add_points(&p_1, &p_2, &sum);
    printf("\tSum : (%.2f, %.2f)\n", sum.x, sum.y);
    
    
    
    return 0;
}

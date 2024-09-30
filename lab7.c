//there was a mistake in calculating perimeter in last file,so i upload a new one

#include <stdio.h>
#include <math.h>

typedef struct coordinates
{
    double x;
    double y;
}point;


int main(int argc, char* argv[])
{
    point tri[3];
    double perimeter;

    //take value from user
    for(int i=0; i<3; ++i)
    {
        printf("Please entre the x coordinates of %d-th vertice: ", i+1);
        scanf("%lf", &tri[i].x);

        printf("Please entre the y coordinates of %d-th vertice: ", i+1);
        scanf("%lf", &tri[i].y);
    }
    
    //print values
    for(int i=0; i<3; ++i)
    {
        printf("The %d-th vertice of triangle is at (x,y): %lf, %lf\n", i+1, tri[i].x, tri[i].y);
    }
    
    //calculate perimeter
    double length1 = sqrt(pow((tri[0].x-tri[1].x),2) + pow((tri[0].y-tri[1].y),2));
    double length2 = sqrt(pow((tri[1].x-tri[2].x),2) + pow((tri[1].y-tri[2].y),2));
    double length3 = sqrt(pow((tri[2].x-tri[0].x),2) + pow((tri[2].y-tri[0].y),2));
    perimeter = length1 + length2 + length3;
    printf("The permimeter of triangle is: %lf\n", perimeter);
    
    //verify equilateral
    if(length1 == length2 && length2 == length3)
        printf("The triangle is an equilateral triangle\n");
    
    //verify isosceles
    else if(length1 == length2 || length2 == length3 || length1 == length3)
        printf("The triangle is an isosceles triangle.\n");

    return 0;
}


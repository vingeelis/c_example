#include <stdio.h>

struct Point1
{
    int x;
    int y;
    int z;
};

struct _Point2
{
    int x;
    int y;
    int z;
};
typedef struct _Point2 Point2;

typedef struct _Point3
{
    int x;
    int y;
    int z;
} Point3;


struct tagNode
{
    char *pItem;
    struct tagNode *pNext;
};
typedef struct tagNode *pNode;

int main(int argc, char const *argv[])
{
    struct Point1 p1 = {0, 0, 1}; 
    printf("%d %d %d\n", p1.x, p1.y, p1.z);
    
    Point2 p2 = {0, 1, 0};
    printf("%d %d %d\n", p2.x, p2.y, p2.z);

    Point3 p3 = {1, 0, 0};
    printf("%d %d %d\n", p3.x, p3.y, p3.z);
}

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int *ptr[4], x=1, y=2, z=3, w=5;
    ptr[0]=&x, ptr[1]=&y, ptr[2]=&z, ptr[3]=&w;
    cout << sizeof(ptr);
    for (int i = 0; i < 4; i++)
    {
        /* code */
    }
    
    
    return 0;
}
#include <iostream>

using namespace std;



int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    int x, y;
    int uz_a_pret = 1;
    int uz_b_pret = 0;
    int uz_a = 0;
    int uz_b = 1;
    while(b != 0)
    {
        int q = a / b;
        int r = a % b;
        a = b;
        b = r;
        if(b != 0)
        {
            int uz_a_temp = uz_a;
            int uz_b_temp = uz_b;
            uz_a = uz_a_pret - q * uz_a;
            uz_b = uz_b_pret - q * uz_b;
            uz_a_pret = uz_a_temp;
            uz_b_pret = uz_b_temp;
        }
        x = uz_a;
        y = uz_b;
    }
    cout << x << " " << y << endl;    
    return 0;
}

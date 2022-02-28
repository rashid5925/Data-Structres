#include <iostream>

using namespace std;

void print_num(int n){
    if (n>=1)
    {
        cout<<n<<" ";
        print_num(n-1);
        cout<<n<<" ";
    }else{
        cout<<n<<" ";
    }
    
}

int main()
{
    print_num(10);
    return 0;
}
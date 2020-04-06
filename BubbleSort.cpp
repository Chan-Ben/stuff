#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int i,j,t;
    //int N;
    //cin >> N;
    //int nums[N];
    /*
     *for(i = 0;i < N;i++)
     *    cin >> nums[i];
     */

    int nums[] = {3,2,5,6,4,7,1,9,10,8};
    int N = 10;
    for (i = 1;i < N - 1; i++) {
        for (j = 0;j < N-i; j++) {
            if (nums[j]<nums[j+1]) {
                t = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = t;
            }
        }
    }
    for (i=0;i<N;i++)
        cout<<nums[i]<<" ";

    return 0;
}

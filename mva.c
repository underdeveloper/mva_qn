#include <stdio.h>

int main(int argc, char **argv) {
    int i=1;
    const int K = 10; // Number of users to be inserted into system
    const int Q = 3; // Number of queues
    const int Mu = 1; // Base value of service rate
    float n[Q]={0,0,0}; // Mean number of users per queue
    float t[Q]={0,0,0}; // Mean wait time per queue
    float m[Q]={3*Mu,2*Mu,Mu}; // Mean service rate per queue
    float l[Q]={0,0,0}; // Mean arrival rate per queue
    float h[Q]={4,1,3}; // Solutions to flow equation (lambda hat i)
    float s = 0;// Sigma of h*t
    int a = 0;

    do {
        printf("%d\n", a);
        for(a=0;i<Q;a++){
            t[a] = (1/m[a])*(1+n[a]);
            s += h[a]*t[a];
        };
        for(a=0;i<Q;a++){
            n[a] = i*(h[a]*t[a])/s;
            l[a] = n[a]/t[a];
        };
        i++;
        printf("%d\n", i);
    } while (i<=K);

    printf("For k = %d: l1 = %d, l2 = %d, l3 = %d.\n", K, l[0], l[1], l[2]);
}

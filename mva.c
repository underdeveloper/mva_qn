#include <stdio.h>

// Kinda forgot that c arrays are immutable...

int i=1;
const int K = 10; // Number of users to be inserted into system
const int Q = 3; // Number of queues
const float Mu = 1.0; // Base value of service rate
double n[Q]={0,0,0}; // Mean number of users per queue
double t[Q]={0,0,0}; // Mean wait time per queue
float m[Q]={3*Mu,2*Mu,Mu}; // Mean service rate per queue
double l[Q]={0,0,0}; // Mean arrival rate per queue
float h[Q]={4,1,3}; // Solutions to flow equation (lambda hat i)

int main() {
    double s = 0; // Sigma of h*t
    int a; // Counter to loop through queue arrays
     printf("t[%d] = %d.\n", a, t[a]);
    do {
        //printf("%d\n", a);
        for(a=0;a<Q;a++){
            &(t[a]) = 1+n[a];
            s += h[a]*t[a];
            printf("t_%d = %d, s=%d.\n", a+1, t[a], s);
        };
        for(a=0;a<Q;a++){
            n[a] = i*(h[a]*t[a])/s;
            l[a] = n[a]/t[a];
            printf("n_%d = %d, l_%d=%d.\n", a+1, n[a], a+1, l[a]);
        };
        s=0;
        i++;
        //printf("%d\n", i);
    } while (i<=K);

    printf("For k = %d: l1 = %d, l2 = %d, l3 = %d.\n", K, l[0], l[1], l[2]);
}

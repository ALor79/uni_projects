#include <stdio.h>
typedef struct time
{
    int hour;
    int min;
    int sec;
} time;
time convert(int T);

int main() {
    int totalsec=10243;
    time t=convert(totalsec);
    printf("%d hours %d minutie and %d seconds",t.hour,t.min,t.sec);
    return 0;
}
time convert(int T){
    time t;
    t.hour=T/3600;
    int remain=T%3600;
    t.min=remain/60;
    t.sec=remain%60;
    return t;
}
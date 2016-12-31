/*
欧拉函数PHI(n)表示的是比n小，并且与n互质的正整数的个数(包括1)
*/


int euler(int n) {
     int res = n;
     int a = n;

     for(int i = 2; i * i <= a; ++i) {
         if(a % i == 0) {
             res -= res / i;
             while (a % i == 0) {
                 a /= i;
             }
         }
     }

     if (a > 1) {
         res -= res / a;
     }
     return res;
}

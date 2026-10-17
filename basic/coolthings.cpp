
priority_queue<T> //由大到小
priority_queue<T,vector<T>,greater<T>> //由小到大
__builtin_popcountll// 二進位有幾個1(記得這是long long)
__builtin_clzll         // 左起第一個1之前0的個數
__builtin_parityll      // 1的個數的奇偶性
__builtin_mul_overflow(a,b,&h) // a*b是否溢位,h = a * b;
__builtin_add_overflow(a,b,&h) 
x>>=1 //右移最左邊補零
x<<=1 //左移最右邊補零
//註 : k 0-base
x&(1<<k) //取出 x 的第 k 位
if(x&(1<<k)) x = x ^ (1<<k) //把第 k 位歸零
x = x | (1<<k) //把第 k 位變成 1 
x = ((1<<n) - 1) - x; //取 x 的補集合
//宇集 U = (1<<n) - 1 
__builtin_popcount(x) //數 x 有幾個 1
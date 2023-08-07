class Solution {
public:
    #define ll long long
    int m = 1e9 + 7;

    ll power(ll x, ll y){
        ll ans = 1;
        x = x % m;
        if(x == 0)
            return 0;
        while( y > 0 ){
            if(y%2 != 0) //y is odd
                ans = (ans * x) % m;
            y = y/2;
            x = (x*x) % m;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        ll count4 = n/2;
        ll count5 = n - count4;
        ll sol = ((power(4ll, count4)) % m * (power(5ll, count5) %m )% m) ;
        return (int)sol;
    }
};
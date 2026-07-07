/*
https://codeforces.com/contest/2240/my



*/

void solve() {
    ll n ,m,r,c;
    cin >> n >>m >> r >>c;
    ll pw = n*m;
    pw = pw - (n-r+1) * (m-c+1);


    ll ans = power(2,pw) ;
    cout << ans <<endl;

    

}

/*
Equations (general): Each constraint of the form "XOR of some variables = 0" is a 
linear equation mod 2. With V total variables and rank independent equations 
(none derivable by XOR-combining the others), solutions = 2^(V - rank).
 Each independent equation locks in one variable (solve for it in terms of the rest),
  halving the count — regardless of which variables it shares with other equations. 
  Redundant equations don't reduce the c
  ount further, so rank, not raw equation count, 
  is what matters.


  v= all variables comboned of all equations its not necssary for all of them to occur ina ll equations.





Windows: number of positions a window can start at. 1D: row length n, window r → starts i=1..n-r+1 → n-r+1 windows (last cell i+r-1 can't exceed n). 2D: independent row-starts × col-starts → (n-r+1)(m-c+1) windows total.




*/




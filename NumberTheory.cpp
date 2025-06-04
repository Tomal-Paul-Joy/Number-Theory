const int sievelim = 1e8; 
bitset<sievelim>isPrime ; 
void sieve(int n ) { 

    isPrime[2] = 1 ; 
    for(int i=3 ; i<=n ; i+=2 ) isPrime[i] = 1 ; 
    
    for(int i = 3 ; i*i<=n; i+=2 ) { //divisors
        
        if (isPrime[i]) { 
        
           for(int j = i*i; j<=n ; j+=i ) { //multiples
           
               isPrime[j] = 0 ; 
               
           
           }
        
        }
    
    } //O(nln(n))
    
    

}
vector<int> primeFactors(int n) {
	
	vector<int>primes; 
	vector<int>factors ; 
	sieve(n);
	primes.push_back(2); 
	 
	for(int i = 3  ; i<=n ; i+=2 ) { 
	
	    if (isPrime[i]) primes.push_back(i); 
	    
	
	}
	
	for(auto it: primes ) { // O(sqrt(n)/ln(sqrt(n)))
	
	    if(1LL * it *it > n ) break; 
	    
	    while(n%it==0) {// + O(log(2base)(n))
	    	factors.push_back(it);
	    	n/=it; 
	    } 
	     
	
	}
	if (n>1) factors.push_back(n); 
	return factors ; 
	
}
ll gcd(ll a , ll b ) { return __gcd(a,b); }
ll lcm(ll a , ll b ) { return (a/gcd(a,b)) * b; }
void noOfDivisorsOfaNumber() { 
    
    
    int n;cin>>n ;   
    for(int i = 1; i*i<=n;  i++ ) { 
    
    
         if (n%i==0) {
         	 
         	 cout<<i<<" "<<n/i<<endl ; 
         	 if (i*i!=n)cout<<n/i<<" "<<i<<endl ;
         	
         }
         
    
    
    
    }



}
void sumofdivisorstilln() { 
     
     int n; 
     cin>>n; 
     int sum =  0; 
     for(int i = 1 ; i*i<=n ; i++ ) { 
     
          int val = (n/i) - i ; 
          sum+=2*val; 
     
         
     
     }
     sum+=sqrt(n);
     cout<<sum<<endl ; 
     
 
 
 }
 int sumOfDivisorsforOneNumber(int n) {
	
	vector<int>primes; 
	sieve(n);
	primes.push_back(2); 
	 
	for(int i = 3  ; i<=n ; i+=2 ) { 
	
	    if (isPrime[i]) primes.push_back(i); 
	    
	
	}
	
	int sod = 1 ;
	
	for(auto it: primes ) { // O(sqrt(n)/ln(sqrt(n)))
	
	    if(1LL * it *it > n ) break; 
	    
	    
	    int sum = 1 ; 
	    int a = 1 ; 
	    
	    while(n%it==0) {// + O(log(2base)(n))
	    
	       a*=it ; 
	       
	       sum+=a; 
	       
	    	
	       n/=it; 
	    } 
	    sod*=sum; 
	     
	
	}
	if (n>1) sod*=(n+1); 
	return sod   ; 
	
} 
int eulerFuctionToFindHowManyCoprimesofaNumbergcdequalTo1(int n) {
	
	//n = p1^a1*p2^a2*....*pk^ak;
	//euler(n) = gcd(a,n) = 1 [1<= a <=n] = n*((p1-1)/p1)*((p2-1)/p2) *....*((pk-1)/pk)
	
	vector<int>primes; 
	sieve(n);
	primes.push_back(2); 
	 
	for(int i = 3  ; i<=n ; i+=2 ) { 
	
	    if (isPrime[i]) primes.push_back(i); 
	    
	
	}
	
	int sum = n; 
	
	for(auto it: primes ) { // O(sqrt(n)/ln(sqrt(n)))
	
	    if(1LL * it *it > n ) break; 
	    
	    if(n%it==0) { 
	        while(n%it==0) {// + O(log(2base)(n))
	    	n/=it; 
	       } 
	       
	       sum/=it ;
	       sum*=(it-1); 
	    
	    }
	   
	     
	
	}
	if (n>1) {
		sum/=n ; 
	} 
	return sum*=(n-1) ; 
	
} 
 
 

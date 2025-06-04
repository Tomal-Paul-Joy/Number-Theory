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
 
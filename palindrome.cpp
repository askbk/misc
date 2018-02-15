#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

bool isPalindrome(long long number){
    long long temp = number, hygg = number, size = 0;
    
    while(temp > 0){
	++size;
        temp /= 10;
    }
	
    int digits[size];
    int k = 0;
    
    while(number > 0){
        int curr = number % 10;
        number /= 10;
        
        digits[k] = curr;
      	++k;
    }
    
    for(int i = 0; i < size / 2; ++i){
        if(digits[i] != digits[size - 1 - i]){
            return false;
        }
    }
    
    return true;
}

long long maxPalindromeProduct(int n) {
    long long  max = 0, lower = pow(10, n - 1), upper = pow(10, n);
    bool checked[upper][upper];

    memset(checked, sizeof checked, false);

    for(long long i = lower; i < upper; ++i){
        for(long long j = lower; j < upper; ++j){
            if(checked[i][j] || checked[j][i]) continue;
            
            long long curr = i * j;
            
            if(curr > max){
                if(isPalindrome(curr)){
                    max = curr;
                }
            }
            checked[i][j] = true;
            checked[j][i] = true;
        }
    }
    
    return max;
}

int main(){
    int n;
    cin >> n;
    cout << maxPalindromeProduct(n) << "\n";
}





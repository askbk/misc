function prime_factors(n)
    primes = sieve(n);
    temp = n;
    factors = zeros(Int64, length(primes));
    ans = "";
    factorcount = 0
    for i in 1:length(primes)
        if  temp % primes[i] == 0
            factorcount += 1;
            ans *= "(" * string(primes[i]);
            while temp % primes[i] == 0
                temp = div(temp, primes[i]);
                factors[i] += 1;
            end
            if factors[i] > 1
                ans *= "**" * string(factors[i]);
            end
            ans *= ")";
        end
    end
    
    if factorcount == 0
        return "(" * string(n) * ")";
    end
    
    return ans;
end

function sieve(n)
    ceil = Int(div(n, 2))
    isprime = trues(n);
    primes = [2];

    for i in 3:2:ceil
        if isprime[i]
            push!(primes, i)
            for j in i*i:2i:ceil
                isprime[j] = false;
            end
        end
    end

    return primes
end


#println(prime_factors(181957291));

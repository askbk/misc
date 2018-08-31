function gap(g, m, n)
    isprime = getprimes(n)
    prevPrime = 2

    for i in m:n
        if isprime[i]
            if i - prevPrime == g
                return [prevPrime, i]
            end
            prevPrime = i
        end
    end

    return Int64[]
end

function getprimes(n)
    isprime = trues(n)
    isprime[1] = false
    for i in 4:2:n
        isprime[i] = false
    end

    for i in 3:2:n
        if isprime[i]
            for j in i*i:i:n
                isprime[j] = false
            end
        end
    end

    return isprime
end

println(gap(2, 100, 110))

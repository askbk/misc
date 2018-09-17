function fib1(n)
    return (n == 1 || n == 2) ? 1 : fib1(n-1)+fib1(n-2);
end

function fib2(n)
    f = Array{Int}(undef,  n)
    f[1], f[2] = 1, 1

    for i in 3:n
        f[i] = f[i-1] + f[i-2]
    end

    return f[n]
end

println(fib1(100));
println(fib2(100));

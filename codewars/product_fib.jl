function product_fib(prod)
        if prod == 0
                return [0, 1, false]
        end

        ceiling = floor(BigInt, log(sqrt(5)*prod)/log(2))

        fib = zeros(BigInt, ceiling, 1)
        fib[1], fib[2] = 1, 1
        left, right = 1, ceiling
        arrow = 1
        prevLowerBound = ceiling
        while left <= right
                arrow = div((left + right), 2)

                if fib[arrow+1] == 0
                        compute_fib!(arrow+1, fib)
                end

                temp_prod = fib[arrow] * fib[arrow+1]

                if prod == temp_prod
                        return (fib[arrow], fib[arrow+1], true)
                end

                if right - left == 1 || right == left
                        temp_prod = fib[left] * fib[left + 1]
                        if temp_prod == prod
                                return (fib[left], fib[left+1], true)
                        end

                        return (fib[prevLowerBound], fib[prevLowerBound+1], false)
                end

                if prod < temp_prod
                        prevLowerBound = arrow
                        right = arrow
                elseif temp_prod < prod
                        left = arrow
                end
        end
end

function compute_fib!(n, fib)
        if fib[n] != 0
                return;
        end

        if fib[n-2] == 0
                compute_fib!(n-2, fib)
        end

        if fib[n-1] == 0
                compute_fib!(n-1, fib)
        end

        fib[n] = fib[n-1] + fib[n-2]
end

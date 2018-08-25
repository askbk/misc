function dir_reduc(arr)
    opposites = Dict(
        "NORTH" => "SOUTH",
        "SOUTH" => "NORTH",
        "EAST"  => "WEST",
        "WEST"  => "EAST"
    )

    finished = false

    while !finished
            finished = true
            len = length(arr)
            i = 1
            while i < len
                    if arr[i] == opposites[arr[i+1]]
                            finished = false;
                            splice!(arr, i:(i+1))
                            len -= 2
                    else
                            i += 1
                    end
            end
    end
    return arr
end

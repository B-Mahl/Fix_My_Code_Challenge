###
# Sort integer arguments (ascending)
###

result = []
ARGV.each do |arg|
    # Skip if not an integer
    next unless arg =~ /^-?\d+$/

    # Convert to integer
    i_arg = arg.to_i

    # Insert the integer at the right position
    is_inserted = false
    i = 0
    while i < result.size
        if result[i] < i_arg
            i += 1
        else
            result.insert(i, i_arg)
            is_inserted = true
            break
        end
    end

    result << i_arg unless is_inserted
end

puts result

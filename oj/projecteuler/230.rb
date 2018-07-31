
AB = ["1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679",
     "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196"]


fib = []
fib << 1
fib << 1
while(fib.last * 100 < (127 + 19 * 17) * (7 ** 17))
  fib << (fib[-1] + fib[-2])
end

ans = 0

for i in 0..17
  sum = (127 + 19 * i) * (7 **i)
  #puts "#{i} #{(127 + 19 * i) * (7 **i)}"
  fib.each_with_index { |val, idx|
    if val*100 > sum
      #puts "#{val} #{idx}"
      j = idx
      while true
        if j < 2
          break
        end
        #puts "#{sum} #{j} #{fib[j - 2]} #{fib[j - 1]} #{fib[j]}"
        if sum > fib[j - 2] * 100
          sum -= fib[j - 2] * 100
          j -= 1
        else
          j -= 2
        end
      end
      #puts "#{sum} #{j} #{fib[j - 2]} #{fib[j - 1]} #{fib[j]}"
      #puts "#{sum} #{j} #{AB[j][sum-1]}"
      ans = ans +  AB[j][sum-1].to_i * (10 ** i)
      break
    end
  }

end
puts "ans=#{ans}"

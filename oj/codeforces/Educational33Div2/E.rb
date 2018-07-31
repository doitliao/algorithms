N = 1e6 + 31
N = 6
fac = Array.new(N)

fac[0] = 1
for i in 1..N
  fac[i] = fac[i-1] * i

  #puts "#{i}! = #{fac[i]}"
end

mod = 1e9 + 7

n = 200
m = 17
x =  (fac[n] / (fac[n-m] * fac[m])) % mod

puts "#{x}"

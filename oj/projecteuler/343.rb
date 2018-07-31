
$mem = Hash.new
def f(k)
  if $mem[k]
    return $mem[k]
  end
  x = 1
  y = k
  while y != 1
    x += 1
    y -= 1

    cg = x.gcd(y)
    x /= cg
    y /= cg
    if x == 1
      $mem[y] = f(y)
      x = $mem[y]
      y = 1
    end
    #puts "#{x}/#{y}"
  end
  $mem[k] = x
  return x
end

x = 0
for i in 1..2000000
  x += f(i**3)
end

puts "#{x}"

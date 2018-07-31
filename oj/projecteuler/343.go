package main

import (
       "fmt"
       "sync"
)

func main() {
  var primes []uint64
  var all [2000000]uint64

  all[0] = 1
  all[1] = 1
  for i, _ := range all {
    if all[i] == 0 {
      primes = append(primes, uint64(i))
      j := i
      for j < 2000000 {
        all[j] = 1
        j += i
      }
    }
  }

  for _, i := range primes {
    fmt.Println(i)
    break
  }

  //var sum uint64 = 0
  var wg sync.WaitGroup
  var i uint64 = 1
  messages := make(chan uint64)
  for i = 1; i <= 2000000; i++ {
    wg.Add(1)
    go func(k uint64){
      defer wg.Done()
      var a uint64 = k + 1

      var ele uint64 = 1
      for _, p := range primes {
        if p > a {
          break
        }

        if (a % p) == 0 {
          ele = p
          for 0 == (a % p) {
            a /= p
          }
        }
      }
      ea := ele

      a = k*k - k + 1
      ele = 1
      for _, p := range primes {
        if p > a {
          break
        }

        if (a % p) == 0 {
          ele = p
          for 0 == (a % p) {
            a /= p
          }
        }
      }
      eb := ele
      if ea > eb {
        messages <- ea
      } else {
        messages <- eb
      }
    }(i)
  }

  go func() {
    var x uint64
    var sum uint64
    for i := range messages {
      //fmt.Println(i)
      if (x % 10000)  == 0{
        fmt.Println(x)
      }
      x += 1
      sum += i
    }
    fmt.Println(sum)
  }()
  wg.Wait()
}

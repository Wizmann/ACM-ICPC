open System;

let rec do_is_prime x i =
    if 1L * i * i > x then
        true
    elif x % i = 0L then
        false
    else
        do_is_prime x (i + 1L)

let is_prime x =
    if x = 1L then
        false
    else
        do_is_prime x 2L

[<EntryPoint>]
let main argv = 
    let n = Console.ReadLine() |> int

    for i in 0 .. n - 1 do
        let x = Console.ReadLine() |> int64

        if is_prime x then
            Console.WriteLine("Prime")
        else
            Console.WriteLine("Not prime")
    0


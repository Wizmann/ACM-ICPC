open System

let rec do_fib a b cur n =
    let c = a + b
    if cur = n then
        c
    else
        do_fib b c (cur + 1) n

let rec fib n =
    if n = 1 then
        0
    elif n = 2 then
        1
    else
        do_fib 0 1 3 n

[<EntryPoint>]
let main argv = 
    let n = Console.ReadLine() |> int
    printfn "%d" (fib n)
    0

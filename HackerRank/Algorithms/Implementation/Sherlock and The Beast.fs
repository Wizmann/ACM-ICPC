open System

let rec solve n i = 
    if i > n then
        "-1"
    else
        let a = n - i
        let b = i
        if a % 3 = 0 && b % 5 = 0 then
            let l = String.replicate a "5"
            let r = String.replicate b "3"
            l + r
        else
            solve n (i + 1)

[<EntryPoint>]
let main argv = 
    let T = Console.ReadLine() |> int

    for case_ in 1 .. T do
        let n = Console.ReadLine() |> int
        let res = solve n 0
        printfn "%s" res
    0

open System

[<EntryPoint>]
let main argv = 
    let n = Console.ReadLine() |> int

    let rec solve x xx y yy n =
        if n = 10 then 1.0
        else 1.0 * xx / yy + solve x (xx * x) (y + 1.0) (yy * (y + 1.0)) (n + 1)

    for i in 1 .. n do
        let x = Console.ReadLine() |> double
        let res = solve x x 1.0 1.0 1
        printfn "%f" res
    0

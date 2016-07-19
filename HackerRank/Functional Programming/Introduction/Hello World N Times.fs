open System

[<EntryPoint>]
let main argv = 
    let n = Console.ReadLine() |> int
    for i in 1 .. n do
        printfn "Hello World"
    0

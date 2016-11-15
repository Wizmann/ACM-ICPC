open System;

[<EntryPoint>]
let main argv = 
    let n = Console.ReadLine() |> int
    let res = Console.ReadLine()
            |> fun line -> line.Split([|' '|])
            |> Seq.map int
            |> Seq.reduce(fun a b -> a ^^^ b)

    Console.WriteLine(res)
    0


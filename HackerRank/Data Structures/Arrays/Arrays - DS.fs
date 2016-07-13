open System

[<EntryPoint>]
let main argv = 
    let n = Console.ReadLine() |> int
    let ns = 
        Console.ReadLine()
        |> fun line -> line.Split([|' '|])
        |> Seq.toList
        |> Seq.map int
        |> Seq.rev
    for num in ns do
        printfn "%d " num
    0
    

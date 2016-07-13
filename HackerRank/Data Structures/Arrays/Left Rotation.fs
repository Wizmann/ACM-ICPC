open System
open Microsoft.FSharp.Collections

[<EntryPoint>]
let main argv = 
    let n, k =
        Console.ReadLine()
        |> fun line -> line.Split([|' '|])
        |> Seq.map int
        |> Seq.toList
        |> fun items -> (items.Item(0), items.Item(1))

    let ns = 
        Console.ReadLine()
        |> fun line -> line.Split([|' '|])
        |> Seq.map int
        |> Seq.toList

    let ls = ns |> Seq.take(k) |> Seq.rev |> Seq.toList
    let rs = ns |> Seq.skip(k) |> Seq.rev |> Seq.toList

    let res = List.append ls rs|> Seq.rev

    for num in res do
        printf "%d " num
    0
    

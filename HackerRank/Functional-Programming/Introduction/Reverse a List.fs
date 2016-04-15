open System;

[<EntryPoint>]
let main argv = 
    let nums = 
        Seq.initInfinite(fun _ -> Console.ReadLine())
        |> Seq.takeWhile(fun line -> line <> null)
        |> Seq.map int
        |> Seq.toList
        |> List.rev
    for num in nums do
        printfn "%d" num
    0

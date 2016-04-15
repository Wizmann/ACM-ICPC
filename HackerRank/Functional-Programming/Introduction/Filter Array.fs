open System

[<EntryPoint>]
let main argv = 
    let B = Console.ReadLine() |> int
    let nums = 
        Seq.initInfinite(fun _ -> Console.ReadLine())
        |> Seq.takeWhile(fun line -> line <> null)
        |> Seq.toList
        |> Seq.map int
        |> Seq.filter(fun x -> x < B)
    for num in nums do
        printfn "%d" num
    0

// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let ns = (Console.ReadLine()).Split(' ') |> Array.map int
    printfn "%d\n" (Array.reduce min ns)
    0 // return an integer exit code

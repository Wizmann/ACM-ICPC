// Learn more about F# at http://fsharp.org

open System

let rec digitsum num =
    if num > 0 then
        (num % 10) + (digitsum (num / 10))
    else
        0

[<EntryPoint>]
let main argv =
    let (a, b) = (Console.ReadLine()).Split(' ') |> Array.map int |> (fun arr -> arr.[0], arr.[1])
    let sa = (digitsum a)
    let sb = (digitsum b)
    printfn "%d\n" (Math.Max(sa, sb))
    0 // return an integer exit code

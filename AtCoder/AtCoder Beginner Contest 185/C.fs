// Learn more about F# at http://fsharp.org

open System

let rec C n m s b =
    if s = n then
        b
    else
        (C n m (s + 1L) (b * (m - s) / (s + 1L)))

[<EntryPoint>]
let main argv =
    let (L) = (Console.ReadLine()).Split(' ')
                    |> Array.map int64
                    |> (fun arr -> arr.[0])
    printfn "%d\n" (C 11L (L - 1L) 0L 1L)
    0 // return an integer exit code

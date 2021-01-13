// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let (x, y) = Console.ReadLine().Split(' ')
                 |> Array.map(fun x -> int(x))
                 |> fun ps -> (ps.[0], ps.[1])
    if Math.Abs(x - y) < 3 then
        Console.WriteLine("Yes")
    else
        Console.WriteLine("No")
    0 // return an integer exit code

// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let (n) = Console.ReadLine() |> int
    let l1 = Console.ReadLine().Split(' ')
             |> Array.map(fun x -> int(x))
    let l2 = Console.ReadLine().Split(' ')
             |> Array.map(fun x -> int(x))

    let dot = (Array.zip l1 l2) |> Array.map(fun (x, y) -> x * y) |> Array.sum

    if dot = 0 then
        Console.WriteLine("Yes")
    else
        Console.WriteLine("No")
    0 // return an integer exit code

open System

[<EntryPoint>]
let main argv =
    let (n, m) = (Console.ReadLine()).Split(' ')
                 |> Array.map int
                 |> (fun arr -> arr.[0], arr.[1])
    if m - n > 0 then
        printfn "%d\n" ((m - n + 9) / 10)
    else
        printfn "0\n"
    0 // return an integer exit code

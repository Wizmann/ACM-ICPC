open System

[<EntryPoint>]
let main argv =
    let (n, m) = (Console.ReadLine()).Split(' ')
                 |> Array.map int
                 |> (fun arr -> arr.[0] - 1, arr.[1] - 1)
    let s = Console.ReadLine()
    printfn "%s\n" (s.Substring(0, n) + (s.Substring(n, m - n + 1).ToCharArray() |> Array.rev |> System.String) + s.Substring(m + 1))
    0 // return an integer exit code

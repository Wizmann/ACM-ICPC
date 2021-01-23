// Learn more about F# at http://fsharp.org

open System

let INF = 0x3f3f3f3f

let rec solve1 ns =
    match ns with
    | [] -> []
    | [item] -> []
    | a1 :: a2 :: tl ->
        if (a1 + 1) = a2 then
            (solve1 (a2 :: tl))
        else
            let cur = a2 - a1 - 1 in
            cur :: (solve1 (a2 :: tl))

[<EntryPoint>]
let main argv =
    let (n, m) = (Console.ReadLine()).Split(' ')
                 |> Array.map int
                 |> (fun arr -> arr.[0], arr.[1])
        
    let ns = if m > 0 then
                 (Console.ReadLine()).Split(' ')
                 |> Array.map int
                 |> Array.sort
                 |> Array.toList
             else
                []

    let ms = (solve1 ([0] @ ns @ [(n + 1)]))
    let k = List.reduce min (INF :: ms)

    if k >= INF then 
        printfn "0\n"
    else
        let vs = (List.map (fun x -> (x + k - 1) / k) ms)
        printfn "%d\n" (List.fold (+) 0 vs)
    0 // return an integer exit code

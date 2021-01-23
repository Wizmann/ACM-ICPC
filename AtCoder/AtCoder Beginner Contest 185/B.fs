// Learn more about F# at http://fsharp.org

open System

let rec solve n m t pre battery =
    if m = 0 then
        battery > (t - pre)
    else
        let (a, b) = (Console.ReadLine()).Split(' ')
                     |> Array.map int
                     |> (fun arr -> arr.[0], arr.[1]) in
        if battery <= (a - pre) then
            false
        else
            let nb = (min n (battery - (a - pre) + (b - a))) in 
            (solve n (m - 1) t b nb)
        

[<EntryPoint>]
let main argv =
    let (n, m, t) = (Console.ReadLine()).Split(' ')
                    |> Array.map int
                    |> (fun arr -> arr.[0], arr.[1], arr.[2])
    let ok = (solve n m t 0 n)
    printfn "%s\n" (if ok then "Yes" else "No")
    0 // return an integer exit code

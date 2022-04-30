// Learn more about F# at http://fsharp.org

open System

let rec solve (items : (int * int) list) (mp : Map<int, int>) : bool =
    match items with
    | [] -> true
    | item :: ls ->
        let (key, value) = item in
        if not (mp.ContainsKey key) then
            (solve ls (mp.Add (key, value)))
        elif (mp.TryFind key) = Some(value) then
            (solve ls mp)
        else
            false

[<EntryPoint>]
let main argv =
    let T = Console.ReadLine() |> int

    for case_ in 1 .. T do
        let n = Console.ReadLine() |> int
        let pairs = [1 .. n] |> Seq.map (
                                 fun _ -> (
                                    Console.ReadLine().Trim().Split(' ')
                                    |> Seq.map int
                                    |> Seq.toList
                                    |> fun items -> (items.Item(0), items.Item(1))))
                             |> Seq.toList

        let res = (solve pairs Map.empty)
        if res = true then
            Console.WriteLine("YES")
        else
            Console.WriteLine("NO")
    
    0 // return an integer exit code

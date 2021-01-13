// Learn more about F# at http://fsharp.org

open System

let rec do_solve (ns : int List) (score : int array)= 
    match ns with
    | a :: b :: tl -> (if score.[a] < score.[b] then b else a) :: (do_solve tl score)
    | [] -> []

let rec solve (ns : int List) (score : int array) = 
    match ns with
    | a :: b :: [] -> (if score.[a] < score.[b] then a else b)
    | _ -> (solve (do_solve ns score) score)

[<EntryPoint>]
let main argv =
    let n = Console.ReadLine() |> int
    let score = Console.ReadLine().Split(' ')
             |> Array.map(fun x -> int(x))
    let ns = [ 0 .. 1 .. (1 <<< n) - 1 ]
    let res = (solve ns score)
    Console.WriteLine(res + 1)
    0 // return an integer exit code

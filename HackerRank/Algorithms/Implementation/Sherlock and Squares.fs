open System

let rec count a b i sum = 
    if i * i > b then
        sum
    else
        if i * i < a then
            count a b (i + 1) sum
        else
            count a b (i + 1) (sum + 1)

[<EntryPoint>]
let main argv = 
    let T = Console.ReadLine() |> int

    for case_ in 1 .. T do
        let nums = 
            Console.ReadLine().Split(' ')
            |> Seq.map int
            |> Seq.toList
        let a, b = nums.Item 0, nums.Item 1
        printfn "%d" (count a b 0 0)
        ()
    0

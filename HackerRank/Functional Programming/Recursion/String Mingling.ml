let string_to_char_list (s : string) : char list =
    List.of_seq (String.to_seq s)

let char_list_to_string (cs : char list) : string =
    String.of_seq (List.to_seq cs)

let rec solve (s1 : char list) (s2 : char list) (res : char list) : char list =
    match s1 with
    | [] -> res
    | hd :: tl -> (solve (List.tl s1) (List.tl s2) ((List.hd s2) :: (List.hd s1) :: res))

let line1 = string_to_char_list(read_line ())
let line2 = string_to_char_list(read_line ())

let cs = List.rev (solve line1 line2 [])

let () = (print_endline (char_list_to_string cs))



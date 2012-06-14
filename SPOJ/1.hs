{-Result:2012-06-14 09:15:13	Moody Wizmann	Life, the Universe, and Everything	 accepted	0.00	3.7M	HASK-}
main = do
	x <- readNum
	if x==42
		then putStr("")
		else do
			putStr ( show(x) ++ "\n")
			main
	where
		readNum :: IO Integer
		readNum = do
			line <- getLine
			readIO line


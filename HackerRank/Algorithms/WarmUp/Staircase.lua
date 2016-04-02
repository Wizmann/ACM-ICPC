n = io.read("*number", "*l")

for i = 1, n do
	print (string.rep(" ", n - i) .. string.rep("#", i))
end
n = int(raw_input())
langs = map(lambda x: x.strip(),
            "C:CPP:JAVA:PYTHON:PERL:PHP:RUBY:CSHARP:HASKELL:CLOJURE:BASH:SCALA: ERLANG:CLISP:LUA:BRAINFUCK:JAVASCRIPT:GO:D:OCAML:R:PASCAL:SBCL:DART: GROOVY:OBJECTIVEC".split(":"))

for i in xrange(n):
    (uid, lang) = raw_input().split()
    print 'VALID' if lang in langs else 'INVALID'
    

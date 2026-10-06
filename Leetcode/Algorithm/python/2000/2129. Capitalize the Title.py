class Solution(object):
    def capitalizeTitle(self, title):
        words = title.lower().split()
        return ' '.join(
                map(lambda word: word if len(word) <= 2 else word.title(),
                    words))


'''
^^^TEST^^^
"capiTalIze tHe titLe"
-------
"Capitalize The Title"
$$$TEST$$$

^^^TEST^^^
"First leTTeR of EACH Word"
-------
"First Letter of Each Word"
$$$TEST$$$
'''


class Solution(object):
    def entityParser(self, text):
        PLACEHOLDER = "*FUCKLEETCODE*"
        mapping = [
            ('&quot;' , '"'),
            ('&apos;' , '\''),
            ('&amp;'  , PLACEHOLDER ),
            ('&gt;'   , '>' ),
            ('&lt;'   , '<' ),
            ('&frasl;', '/' ),
            (PLACEHOLDER , '&' )
        ]
        
        for (k, v) in mapping:
            text = text.replace(k, v)
        return text

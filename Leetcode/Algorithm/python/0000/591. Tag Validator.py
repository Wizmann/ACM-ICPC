import re

class Solution(object):
    def isValid(self, code):
        code = re.sub("\<\!\[CDATA\[.*?\]\]\>", '^', code
        st = []
        for i, item in enumerate(re.findall("<(\/?[A-Z]{1,9}?)>", code)):
            if item.startswith('/'):
                item = item[1:]
                
                if st and st[-1] == item:
                    st.pop()
                else:
                    return False
            else:
                if not st and i:
                    return False
                st.append(item)
        if st:
            return False
        
        raw = re.sub("<(\/?[A-Z]{1,9}?)>", '$', code)
        if not raw.startswith("$") or not raw.endswith("$"):
            return False
        
        if set('<') & set(raw):
            return False                   

        return True

assert Solution().isValid("<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>") == True
assert Solution().isValid('<A>  <B> </A>   </B>') == False
assert Solution().isValid('<DIV>  div tag is not closed  <DIV>') == False

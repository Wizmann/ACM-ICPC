#python3
import re

text = input()
match = re.search(r'\[(.*?)]{2}', text)
if match:
    extracted_string = match.group(1)
    lower_case_string = ''.join([char.lower() for char in extracted_string if char.isupper()])
    print('/' + lower_case_string)
else:
    assert(False)
    print('not found')


'''
^^^^^TEST^^^^
[TaiYang]]QingShiYongZuiXinBanShouJiQQTiYanXinGongNeng
------------
/ty
$$$$TEST$$$

^^^^^TEST^^^^
[LiuLei]]QingShiYongZuiXinBanShouJiQQTiYanXinGongNeng
------------
/ll
$$$$TEST$$$
'''

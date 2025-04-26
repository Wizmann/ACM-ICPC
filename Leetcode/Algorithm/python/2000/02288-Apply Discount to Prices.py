class Solution(object):
    def discountPrices(self, sentence, discount):
        items = []
        for word in sentence.split():
            if not word.startswith('$'):
                items.append(word)
                continue
            if not word[1:].isdigit():
                items.append(word)
                continue
            value = int(word[1:])
            items.append('$%.2f' % (1.0 * value * (100 - discount) / 100))
        return ' '.join(items)

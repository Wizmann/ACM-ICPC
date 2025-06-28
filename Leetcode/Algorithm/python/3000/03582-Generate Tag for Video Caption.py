class Solution(object):
    def generateTag(self, caption):
        if not caption.strip():
            return '#'
        caption = caption.split()
        caption[0] = caption[0].lower()
        caption[1:] = map(lambda x: x.lower().capitalize(), caption[1:])

        return '#' + ''.join(caption)[:99]

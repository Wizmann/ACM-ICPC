class Solution(object):
    def scoreValidator(self, events):
        cursor = 0
        score = 0
        for event in events:
            if event == 'W':
                cursor += 1
            elif event == 'WD':
                score += 1
            elif event == 'NB':
                score += 1
            else:
                score += int(event)
            if cursor >= 10:
                break
        return [score, cursor]

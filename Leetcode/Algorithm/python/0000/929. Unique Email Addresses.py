class Solution(object):
    def __init__(self):
        assert (self.purify('a.b@c.com') == 'ab@c.com')
    
    def numUniqueEmails(self, emails):
        return len(set(map(self.purify, emails)))
                   
    def purify(self, email):
        name, domain = email.split('@')
        if '+' in name:
            name = name[:name.index('+')]
        return name.replace('.', '') + '@' + domain

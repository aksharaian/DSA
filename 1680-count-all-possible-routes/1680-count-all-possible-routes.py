class Solution(object):
    def countRoutes(self, locations, start, finish, fuel):
        """
        :type locations: List[int]
        :type start: int
        :type finish: int
        :type fuel: int
        :rtype: int
        """
        def rec_count(start, fuel, d):
            if start+fuel*100 in d: return d[start+fuel*100]
            s = 0
            if start == finish: 
                s += 1
            for i in range(n):
                if i != start:
                   f = fuel - abs(locations[i] - locations[start])
                   if f >= 0:
                      s += rec_count(i, f, d)
            d[start+fuel*100] = s
            return s
        n = len(locations)
        return rec_count(start, fuel, {}) % 1000000007
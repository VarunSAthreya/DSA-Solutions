class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = collections.defaultdict(list)
        for s in strs:
            d["".join(sorted(s))].append(s)
        result = []
        for key in d:
            result.append(d[key])
        return result

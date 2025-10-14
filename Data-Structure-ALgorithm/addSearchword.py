# DSA Interview Question: Add and Search Words Data Structure

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word: str) -> bool:
        def dfs(node, i):
            if i == len(word):
                return node.is_end_of_word

            if word[i] == '.':
                for child in node.children.values():
                    if dfs(child, i + 1):
                        return True
                return False
            else:
                if word[i] not in node.children:
                    return False
                return dfs(node.children[word[i]], i + 1)

        return dfs(self.root, 0)

# Example Usage
if __name__ == "__main__":
    wd = WordDictionary()
    wd.addWord("hello")
    wd.addWord("world")
    wd.addWord("hi")

    print(wd.search("hello"))  # True
    print(wd.search("h.llo"))  # True
    print(wd.search("wor.d"))  # True
    print(wd.search("hey"))    # False

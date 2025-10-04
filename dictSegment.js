// Challenge: Word Break with Reconstruction (Hard Dynamic Programming)

// Problem Statement:
// Given a string s and a dictionary of words wordDict, determine if s can be segmented into one or more words from the dictionary.
// But here’s the twist — not only return true/false, but reconstruct all possible valid sentences that can be formed.

// Example
// Input:  
// s = "catsanddog"  
// wordDict = ["cat","cats","and","sand","dog"]

// Output:  
// [
//   "cat sand dog",
//   "cats and dog"
// ]


// Solution:-

function wordBreak(s, wordDict) {
  const wordSet = new Set(wordDict);
  const memo = new Map();

  function dfs(index) {
    if (memo.has(index)) return memo.get(index);
    if (index === s.length) return [""];

    let sentences = [];

    for (let end = index + 1; end <= s.length; end++) {
      let word = s.slice(index, end);
      if (wordSet.has(word)) {
        let subsentences = dfs(end);
        for (let sub of subsentences) {
          sentences.push(word + (sub === "" ? "" : " " + sub));
        }
      }
    }

    memo.set(index, sentences);
    return sentences;
  }

  return dfs(0);
}

// Test
console.log(wordBreak("catsanddog", ["cat","cats","and","sand","dog"]));
// Output: ["cat sand dog", "cats and dog"]

console.log(wordBreak("pineapplepenapple", ["apple","pen","applepen","pine","pineapple"]));
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]


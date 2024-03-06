# ANAGRAM:
# An anagram is direct word switch or word play, the result of rearranging the letters
# of a word or phrase to produce a new word or phrase, using all the original letters exactly once

# We are taking a word and a list. We return the anagrams of that word from the given list and return the
# list of anagrams else return empty list

from collections import Counter


def anagram(word, myList):
    word = word.lower()
    anagrams = []
    for words in myList:
        if word != words.lower():
            if Counter(word) == Counter(words.lower()):
                anagrams.append(words)
    return anagrams


if __name__ == "__main__":
    # ['tan']
    print((anagram("ant", ["tan", "stand", "at"])))

    # ['stream', 'maters']
    print((anagram("master", ["stream", "pigeon", "maters"])))

    # []
    print((anagram("good", ["dog", "goody"])))

    # ['gallery', 'regally', 'largely']
    print((
        anagram(
            "allergy",
            ["gallery", "ballerina", "regally", "clergy", "largely", "leading"],
        )
    ))

    # []
    print((anagram("BANANA", ["Banana"])))

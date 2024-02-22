def check_palindrome(word:str):
    start = 0
    end = len(word)-1
    while(start < end):
        if (word[start] != word[end]):
            return False
        
        start += 1
        end -= 1

    return True
# parentheses_checker.py
# Usage:
#   python parentheses_checker.py
# Then type a line and press Enter (Ctrl+D/Ctrl+Z to end if using multiple lines).

def is_matching(open_ch, close_ch):
    return (open_ch == '(' and close_ch == ')') or \
           (open_ch == '[' and close_ch == ']') or \
           (open_ch == '{' and close_ch == '}')

def are_parentheses_balanced(s: str) -> bool:
    stack = []
    for ch in s:
        if ch in "([{":
            stack.append(ch)
        elif ch in ")]}":
            if not stack or not is_matching(stack.pop(), ch):
                return False
    return not stack

if __name__ == "__main__":
    try:
        line = input("Enter string to check: ")
    except EOFError:
        line = ""
    print("Balanced" if are_parentheses_balanced(line) else "Not Balanced")

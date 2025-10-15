def addBinary(a: str, b: str)-> str:
    res = ""
    a = a[::-1]
    b = b[::-1]
    carry = 0
    for i in range(max(len(a), len(b))):
        digitA = ord(a[i]) - ord("0") if i < len(a) else 0
        digitB = ord(b[i]) - ord("0") if i < len(b) else 0

        total = digitA + digitB + carry
        char = str(total % 2)
        res = char + res
        carry = total // 2

    if carry:
        res = "1" + res
    return res

a = str(input("Enter the 1st binary string: "))
b = str(input("Enter the 2nd binary string: "))
print(addBinary(a=a, b=b))

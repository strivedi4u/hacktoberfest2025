def print_armstrong_numbers_in_range(A, B):
    
    
    for number in range(A,B+1):
        sum=0
        digit=0
        dc=number
        temp=number
        while dc>0:
           digit+=1
           dc=dc//10
        while temp>0:
            r=temp%10
            sum+=r**digit
            temp=temp//10
          
        if sum==number:
            print(number,end=" ")


A=int(input())
B=int(input())
print_armstrong_numbers_in_range(A, B)

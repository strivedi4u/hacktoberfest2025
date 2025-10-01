# Fibonacci sequence in nature examples

def fibonacci(n):
    seq = [0, 1]
    for i in range(2, n):
        seq.append(seq[-1] + seq[-2])
    return seq

fib = fibonacci(10)  # first 10 Fibonacci numbers

print("Fibonacci numbers:", fib)

# Nature examples
nature = {
    fib[5]: "Number of petals in some flowers (e.g., lilies, buttercups)",
    fib[6]: "Sunflower spirals",
    fib[7]: "Pinecone spiral counts",
    fib[8]: "Pineapple scales",
}
print("\nFibonacci in Nature:")
for k, v in nature.items():
    print(f"{k}: {v}")

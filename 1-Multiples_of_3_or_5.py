# https://projecteuler.net/problem=1
# Output: 233168
# Time: 0.06s
print(sum(set(range(3, 1000, 3)) | set(range(5, 1000, 5))))

def mul(A, B):
    if len(A[0]) != len(B):
        raise ValueError("Invalid matrix dimensions")
    result = [[0 for j in range(len(B[0]))] for i in range(len(A))]
    multiply(A, B, result, 0, 0, 0)
    return result

def multiply(A, B, result, i, j, k):
    if i >= len(A):
        return
    if j >= len(B[0]):
        return multiply(A, B, result, i+1, 0, 0)
    if k >= len(B):
        return multiply(A, B, result, i, j+1, 0)
    result[i][j] += A[i][k] * B[k][j]
    multiply(A, B, result, i, j, k+1)
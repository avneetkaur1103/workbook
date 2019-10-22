""" Given a boolean expression with following symbols.

Symbols
    'T' ---> true 
    'F' ---> false 
And following operators filled between symbols

Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR 
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true."""

def parenthesization(symbols, operators):
    n = len(symbols)
    T = [[0 for _ in range(n)] for _ in range(n)]
    F = [[0 for _ in range(n)] for _ in range(n)]

    for l in range(1, n + 1):
        for i in range(n - l + 1):
            j = i + l - 1
            if l == 1:
                T[i][j] = int(symbols[i] == 'T')
                F[i][j] = int(symbols[i] == 'F')
            else:
                for k in range(i, j):
                    tik = T[i][k] + F[i][k]
                    tkj = T[k + 1][j] + F[k + 1][j]
                    if operators[k] == '&':
                        T[i][j] += T[i][k] * T[k + 1][j]
                        F[i][j] += (tik * tkj - T[i][k] * T[k + 1][j])
                    elif operators[k] == '|':
                        F[i][j] += F[i][k] * F[k + 1][j]
                        T[i][j] += (tik * tkj - F[i][k] * F[k + 1][j])
                    elif operators[k] == '^':
                        T[i][j] += T[i][k] * F[k + 1][j] + T[k + 1][j] * F[i][k]
                        F[i][j] += T[i][k] * T[k + 1][j] + F[k + 1][j] * F[i][k]
    return T, F

if __name__ == '__main__':
    symbols = "TTFT"
    operators = "|&^"
    print('Parenthesization ways: ', parenthesization(symbols, operators))

from collections import deque

def downToZero(n):
    if n == 0:
        return 0
    
    visited = set()
    queue = deque([(n, 0)])  # (number, moves)
    
    while queue:
        num, moves = queue.popleft()
        
        if num == 0:
            return moves
        
        if num - 1 not in visited:
            queue.append((num - 1, moves + 1))
            visited.add(num - 1)
        
        sqrt = int(num**0.5)
        for i in range(sqrt, 1, -1):
            if num % i == 0:
                factor = max(i, num // i)
                if factor not in visited:
                    queue.append((factor, moves + 1))
                    visited.add(factor)
    
    return -1  # If no solution is found

if __name__ == '_main_':
    q = int(input().strip())
    
    for _ in range(q):
        n = int(input().strip())
        
        result = downToZero(n)
        
        print(result)
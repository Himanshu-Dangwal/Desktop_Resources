def build_tree_and_trap_icarus(S):
    # Calculate the number of nodes needed
    N = 2 * len(S)
    
    # Starting node A is the root
    A = 1
    
    # Choosing exit node B to be one of the leaf nodes, for example N
    B = N
    
    # We'll build a binary tree where each node i has:
    # Left child = 2*i (if it exists)
    # Right child = 2*i + 1 (if it exists)
    
    tree = []
    for i in range(1, N + 1):
        left = 2 * i if 2 * i <= N else 0
        right = 2 * i + 1 if 2 * i + 1 <= N else 0
        tree.append((left, right))
    
    return N, A, B, tree

# Read input
S = input().strip()

# Build the tree and output
N, A, B, tree = build_tree_and_trap_icarus(S)

print(N, A, B)
for left, right in tree:
    print(left, right)

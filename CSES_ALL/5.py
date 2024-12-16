from collections import deque

def main():
    n = int(input())

    if n == 0:
        print(0)
        return

    q = deque()
    q.append((1, 1))
    q.append((-1, 1))

    st = set()
    st.add((1, 1))
    st.add((-1, 1))

    while q:
        curr_f, curr_s = q.popleft()
        
        if curr_f == n:
            print(curr_s)
            return

        next1 = (curr_f + curr_s + 1, curr_s + 1)
        next2 = (curr_f - curr_s - 1, curr_s + 1)

        if next1 not in st:
            q.append(next1)
            st.add(next1)

        if next2 not in st:
            q.append(next2)
            st.add(next2)

if __name__ == "__main__":
    main()

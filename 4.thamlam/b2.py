MONEY = [1000, 2000, 3000, 5000]

def solve(w, c):
    # với mệnh giá nhỏ nhất mà ko chia hết? -> 0
    if (w % MONEY[0] !=0):
        print("0")
        return
    
    n=0
    s=1
    for i in range(c, -1, -1):
        paper_needed = [0, 0, 0, 0]
        for j in range(3, -1, -1):
            # curr_money: số tiền hiện tại trên tay
            curr_money = MONEY[j] * 10**i

            paper_needed[j] = w // curr_money
            n += paper_needed[j]

            # update số tiền cần trả
            w %= curr_money
        
        # Cập nhật số cách trả lại, theo số tiền sử dụng tại hàng 10^i
        if (paper_needed[3] != 0 and paper_needed[2] != 0 and paper_needed[0] != 0):
            # 9000 = (Cách 1) 5000 + 3000 + 1000 = (Cách 2) 5000 + 2000 * 2 = (Cách 3) 3000 * 3
            s *= 3
        elif (paper_needed[3] != 0 and paper_needed[0] != 0):
            # 6000 = (Cách 1) 5000 + 1000 = (Cách 2) 3000 * 2
            s *= 2
        elif (paper_needed[2] != 0 and paper_needed[0] != 0):
            # 4000 = (Cách 1) 3000 + 1000 = (Cách 2) 2000 * 3
            s *= 2

    print(n, s)

def main():
    T = int(input())

    for i in range(T):
        w = int(input())
        c = int(input())
        
        solve(w, c)

if __name__ == '__main__':
    main()


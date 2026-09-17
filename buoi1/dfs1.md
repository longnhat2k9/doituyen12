Cho đồ thị vô hướng được biểu diễn bằng danh sách cạnh. Có $Q$ truy vấn yêu cầu trả lời có đường đi giữa $2$ đỉnh này hay không

## Input
- Dòng đầu gồm hai số $m, n$ tương ứng với số đỉnh và số cạnh của đồ thị, các đỉnh được đánh số từ $1$ tới $n$. $m$ dòng tiếp theo mỗi dòng chứa $2$ đỉnh $u, v$ tương ứng với cạnh đồ thị
- Dòng tiếp theo là $Q$, $Q$ dòng tiếp theo chứa $2$ đỉnh $s, t$ cần truy vấn

## Constrain
- $1 \le s, t \le n \le 1000$
- $1 \le m \le frac{n(n-1)}{2}$
- $1 \le Q \le 1000$

## Output
Với mỗi truy vấn in trên 1 dòng
- In ```1``` nếu có đường đi giữa $2$ đỉnh
- Ngược lại in ```-1```

## Example Input 
```
5 3
5 4
4 1
4 3
3
4 5
4 2
3 4
```

## Example Output 
```
1
-1
1
```

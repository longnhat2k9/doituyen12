## Bài toán: Ốc sên ăn rau
Một khu vườn hình chữ nhật có kích thước NxM (N dòng, M cột). Ta đánh số các dòng từ 1 đến N theo chiều từ trên xuống dưới và các cột từ 1 đến M theo chiều từ trái qua phải để chia khu vườn thành các ô. Trong các ô đó, ngoài những ô là đất để người nông dân trồng rau vẫn có những ô là đá không thể trồng rau được. Một chú ốc sên xuất phát từ ô (x,y) (x là vị trí dòng, y là vị trí cột). Nếu ô xuất phát là đất, chú ốc sên có thể di chuyển sang 4 ô kề cạnh với ô đó (bên trái, bên phải, bên trên, bên dưới) và đương nhiên không thể di chuyển vào ô đá được. Trường hợp ô xuất phát là đá thì chú ốc sên không thể di chuyển đến ô nào khác.

**Yêu cầu:** Hãy tính xem chú ốc sên có thể di chuyển đến nhiều nhất là bao nhiêu ô để ăn rau?

## Dữ liệu vào: Từ tệp văn bản OCSEN.INP gồm:

- Dòng thứ nhất gồm 4 số nguyên N, M, X, Y (mỗi số cách nhau một khoảng trắng) (4 ≤ N ≤ 2000, 1 ≤ Y ≤ M ≤ 2000)
- Trong N dòng tiếp theo, mỗi dòng gồm M số nguyên 0 hoặc 1 Y (mỗi số cách nhau một khoảng trắng). Số 0 nghĩa là ô đó trồng rau, số 1 nghĩa là ô đá.

## Dữ liệu ra: Ghi ra tệp văn bản OCSEN.OUT gồm:
- 1 số nguyên là số lượng ô rau lớn nhất mà chú ốc sên có thể di chuyển đến để ăn rau. Nếu chú ốc sên không ăn được ô rau nào thì ghi kết quả là -1.

## Sample Input 
```
4 5 2 4 
0 0 1 0 0 
0 1 0 0 1 
1 0 0 0 0 
0 1 0 0 1 
```

## Sample Output
```
10
```

# Ràng buộc:

- Sub1: có 50% test tương ứng 50% số điểm của bài toán với N, M < 10;
- Sub2: có 30% test tương ứng 30% số điểm của bài toán với N, M ≤ 100;
- Sub3: có 20% test tương ứng 20% số điểm của bài toán với N, M ≤ 2 x 10³.;

**Bài toán: Đường đi của Robot** *(Đề thi HSG lớp 12 năm học 2009 - 2010, Tỉnh Hà Tĩnh)*

Một bảng hình chữ nhật có kích thước $M \times N$ ($M, N$ nguyên dương và không lớn hơn $100$) được chia thành các ô vuông đơn vị bằng các đường thẳng song song với các cạnh. Một số ô vuông nào đó có thể đặt các vật cản. Từ một ô vuông, Robot có thể đi đến một ô vuông kề cạnh với nó nếu ô vuông đó không có vật cản. Hỏi rằng nếu Robot bắt đầu xuất phát từ một ô vuông không có vật cản thuộc dòng $K$, cột $L$ thì có thể đi đến được ô vuông không có vật cản thuộc dòng $H$, cột $O$ hay không? Nếu có thì hãy chỉ ra đường đi qua ít ô vuông nhất.

**Dữ liệu vào** là tệp văn bản **ROBOT.INP** có cấu trúc:

* Dòng đầu tiên ghi các chữ số $M, N, K, L, H, O$. Các số ghi cách nhau ít nhất một ký tự trống;
* $M$ dòng tiếp theo, mỗi dòng ghi $N$ số $1$ hoặc $0$ tuỳ thuộc vào ô vuông tương ứng trong bảng hình chữ nhật nêu trên có vật cản hay không (ghi số $1$ nếu có vật cản), các số trên mỗi dòng ghi liên tiếp nhau.

**Dữ liệu ra** là tệp văn bản **ROBOT.OUT** có cấu trúc:

* Nếu Robot có thể đi được từ ô vuông thuộc dòng $K$, cột $L$ đến ô vuông thuộc dòng $H$, cột $O$ thì:
- Dòng đầu tiên ghi 'Co duong di';
- Các dòng tiếp theo, mỗi dòng ghi 2 số là chỉ số dòng và chỉ số cột của các ô vuông trong đường đi tìm được từ ô vuông thuộc dòng K, cột L đến ô vuông thuộc dòng H, cột O mà qua ít ô vuông nhất. Hai số trên mỗi dòng ghi cách nhau ít nhất một ký tự trống;
- Ngược lại, nếu Robot không thể đi được từ ô vuông thuộc dòng K, cột L đến ô vuông thuộc dòng H, cột O thì ghi 'Khong co duong di'.

**Ví dụ:**

| ROBOT.INP | ROBOT.OUT | ROBOT.INP | ROBOT.OUT |
| :--- | :--- | :--- | :--- |
| 4 7 3 4 2 6<br>1000000<br>0010100<br>0000000<br>1101000 | Co duong di<br>3 4<br>3 5<br>3 6<br>2 6 | 4 7 2 2 1 3<br>1010000<br>0010100<br>0100000<br>1101000 | Khong co duong di |

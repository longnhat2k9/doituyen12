## Statement

**[VI]**

Sau khi kết thúc OLP Tin Học SV, một số OLP-er quyết định đầu tư thuê đất để trồng rau. Mảnh đất thuê là một hình chữ nhật N x M (1<=N<=100; 1<=M<=100) ô đất hình vuông. Nhưng chỉ sau đó vài ngày, trận lụt khủng khiếp đã diễn ra làm một số ô đất bị ngập :((

Mảnh đất biến thành một số các ao. Các OLP-er quyết định chuyển sang nuôi cá :D Vấn đề lại nảy sinh, các OLP-er muốn biết mảnh đất chia thành bao nhiêu cái ao để có thể tính toán nuôi trồng hợp lý. Bạn hãy giúp các bạn ý nhé.

Chú ý: Ao là gồm một số ô đất bị ngập có chung đỉnh. Dễ nhận thấy là một ô đất có thể có tối đa 8 ô chung đỉnh.

**[EN]**

Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M (1 <= N <= 100; 1 <= M <= 100) squares. Each square contains either water ('W') or dry land ('.'). Farmer John would like to figure out how many ponds have formed in his field.  A pond is a connected set of squares with water in them, where a square is considered adjacent to all eight of its neighbors. 

Given a diagram of Farmer John's field, determine how many ponds he has.

## INPUT FORMAT:

**[VI]**

- Line 1: Two space-separated integers: N and M
- Lines 2..N+1: M characters per line representing one row of Farmer John's field.  Each character is either 'W' or '.'.  The characters do not have spaces between them.

**[EN]**

- Dòng 1: 2 số nguyên cách nhau bởi dấu cách: N và M
- Dòng 2..N+1: M kí tự liên tiếp nhau mỗi dòng đại diện cho 1 hàng các ô đất. Mỗi kí tự là 'W' hoặc '.' tương ứng với ô đất đã bị ngập và ô đất vẫn còn nguyên.


## SAMPLE INPUT (file lkcount.in):

```
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
```

## OUTPUT FORMAT:

- **[EN]** Line 1: The number of ponds in Farmer John's field.
- **[VI]** Dòng 1: 1 dòng chứa 1 số nguyên duy nhất là số ao tạo thành.

## SAMPLE OUTPUT (file lkcount.out):

3

## OUTPUT DETAILS:

There are three ponds: one in the upper left, one in the lower left, and one along the right side.

# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
Bài lab nhằm giúp sinh viên hiểu và cài đặt hai phương pháp mã hóa cổ điển:
- Caesar Cipher (mã hóa thay thế)
- Rail Fence Cipher (mã hóa hoán vị)

Ngoài ra, sinh viên làm quen với việc tổ chức code, kiểm thử và quản lý bài làm bằng GitHub.

---

## 2. Cách làm
- Xây dựng hàm mã hóa và giải mã Caesar Cipher, hỗ trợ chữ hoa, chữ thường và giữ nguyên dấu cách.
- Cài đặt Rail Fence Cipher với cơ chế zigzag, cho phép thay đổi số ray.
- Viết thêm chức năng giải mã Rail Fence.
- Kiểm tra đầu vào chỉ gồm chữ cái và dấu cách.
- Đọc dữ liệu từ file `data/input.txt`.
- Thực hiện kiểm thử với nhiều test case khác nhau.

---

## 3. Kết quả chính

### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 3 | L ORYH BRX | Mã hóa đúng, giữ dấu cách |
| hello world | 5 | mjqqt btwqi | Xử lý đúng chữ thường |
| L ORYH BRX | 3 | I LOVE YOU | Giải mã chính xác |

---

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 | IOEOLVYU | Mã hóa zigzag đúng |
| I LOVE YOU | 4 | IOYELUOV | Thay đổi số ray hoạt động |
| IOEOLVYU | 2 | I LOVE YOU | Giải mã chính xác |

---

### 3.3 Input validation / file input
- Trường hợp đầu vào không hợp lệ:
  - Input: `Hello123` → bị từ chối (có ký tự số)
- Kết quả đọc từ `data/input.txt`:
  - Input file: `HELLO WORLD`
  - Output: mã hóa và giải mã đúng

---

## 4. Kết luận
Qua bài lab, em hiểu rõ nguyên lý của hai loại mã hóa:
- Caesar Cipher: dịch chuyển ký tự theo bảng chữ cái
- Rail Fence Cipher: sắp xếp ký tự theo dạng zigzag

Khó khăn lớn nhất là cài đặt phần giải mã Rail Fence do phải tái tạo đúng cấu trúc zigzag.  
Bài lab giúp em hiểu rõ hơn về cách hoạt động của các thuật toán mã hóa cơ bản và cách tổ chức một project hoàn chỉnh.

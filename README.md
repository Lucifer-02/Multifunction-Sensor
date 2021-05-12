# Multifunction-Sensor
# Mô tả: Hệ thống cảm biến điều khiển có thể thay đổi điều kiện dễ dàng.
![image](https://user-images.githubusercontent.com/84069686/117951840-c2a6fd00-b33e-11eb-8440-7b62349a1d02.png)
* Cảm biến bất kỳ.
* Bộ xử lý sử dụng 8051 với 3 đầu vào tín hiệu cảm biến và 8 điều kiện theo nhu cầu người dùng.
* Bộ điều khiển sử dụng PIC16F877A điều khiển Servo đóng mở cửa số, được kết nối với 8051 và hỗ trợ kết nối Bluetooth.
* Smart phone sử dụng phần mềm Arduino BlueControl trên Playstore và máy tính sử dụng phần mềm viết bằng Processing mô tả ở file PIC_Bluetooth.pde để điều khiển Servo bàng PIC.

Note: Lưu ý ở đây chỉ tập trung vào tính linh hoạt của bộ xử lý, phần còn lại chỉ để tạo thành một sản phẩm hoàn chỉnh.

# Chế độ: Tự động và thủ công.
        - Tự động: sử dụng tín hiệu từ các cảm biến và điều khiển servo.
        - Thủ công: điều kiển đóng mở trực tiếp bằng Bluetooth qua điện thoại hoặc máy tính.
# Sử dụng:
1. Mở file mô phỏng Proteus để trực quan hóa.
2. Trên laptop chạy file PIC_Bluetooth.exe lên và chọn các chế độ, nút đầu tiên là chế độ tự động, 3 nút còn lại là chế độ thủ công điều kiển đóng/mở/mở hé cửa sổ.(làm tương tự trên smartphone với phần mềm Arduino BlueControl)
3. Ở chế độ Tự động, chỉ cần chọn điều kiện cho bộ xử lý, double click vào file SetUp_Mode.py và làm theo chỉ dẫn trên màn hình, nó sẽ tự động mở file Excel lên và gạt công tắt theo bảng màu đỏ.
4. Chế độ thủ công đã nhắc ở trên.


Note: Thông tin chi tiết trong file .docx  
